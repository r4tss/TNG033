/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>


// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

// Function to filter punctuation signs
char punctuation_signs(char c)
{
	switch(c)
	{
		case '.':
		case ',':
		case '!':
		case '?':
		case ':':
		case '"':
		case '(':
		case ')':
			return true;
		default:
			return false;
	}
}

/***************************
 * Main function           *
 **************************/

int main() {
	// Dialog to choose text file
    std::cout << "Choose text file:\n	1. uppgift.txt\n	2. uppgift_kort.txt" << "\x1b[2A\x1b[9D";
	std::string file_name;
	int choice;
	std::cin >> choice;
	std::cout << "\x1b[2B";
	if(choice == 1)
		file_name = "uppgift.txt";
	else if(choice == 2)
		file_name = "uppgift_kort.txt";
	else
	{
		std::cout << "Invalid choice\n";
		return -1;
	}


	std::ifstream in_File{"../code/" + file_name};  // modify path, if needed

	if (!in_File) {
		std::cout << "Could not open input file!!\n";
		return 0;
	}

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

	// Word string
	std::string word;

	// Read the file word by word
	while(in_File >> word)
	{
		// Erase punctuation in the word
		word.erase(std::remove_if(word.begin(), word.end(), &punctuation_signs), word.end());

		// Make the word lowercase
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

		// Increment the table with the key word
		table[word]++;

		// Increment counter
		counter++;
	}

	std::cout << "--- std::map<std::string, int> table ---\n";
	for(auto i = table.begin();i != table.end();i++)
	{
		std::cout << i->first << std::setw(20 - (int)(i->first).size()) << i->second << "\n";
	}

	std::cout << "STOP -111\n";

    std::vector<std::pair<std::string, int>> freq;

	// transform map to vector using lambda expression
	std::transform(table.begin(), table.end(), back_inserter(freq), [] (const std::pair<std::string, int> &p) { return p; });

	// sort vector using lambda expression
	std::sort(freq.begin(), freq.end(), [](const std::pair<std::string, int> &a,const std::pair<std::string, int> &b)
			{ 
			if(a.second == b.second) // If the words have the samme occurance then they are sorted alphabetically
				return a.first < b.first;
			return a.second > b.second; 
			});

	std::cout << "--- std::vector<std::pair<std::string, int>> freq ---\n";
	for(int i = 0;i < (int)freq.size();i++)
	{
		std::cout << freq[i].first << std::setw(20 - (int)(freq[i].first).size()) << freq[i].second << "\n";
	}

    /* ************** Testing **************** */

    test(table, freq, file_name, counter);
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */

    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}
