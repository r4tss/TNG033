/*********************************************
 * Lab 3: exercise 3                         *
 * Program to compute an approximation of pi *
 * STL-algorithms should be used             *
 *********************************************/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <format>

int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

	// Create vector of indecies
	std::vector<double> indecies(n);
	std::iota(indecies.begin(), indecies.end(), 0);

	// Create vector of terms
	std::vector<double> terms;
	std::transform(indecies.begin(), indecies.end(), std::back_inserter(terms), [] (const double d) { return(4 / (8 * d + 1) - 2 / (8 * d + 4) - 1 / (8 * d + 5) - 1 / (8 * d + 6)); });

	// Create vector of power terms
	std::vector<double> power_terms;
	std::transform(indecies.begin(), indecies.end(), std::back_inserter(power_terms), [] (const double d) { return std::pow(16.0, -d); });

	// Multiply each term and power term together with matching indecies
	double pi = std::inner_product(terms.begin(), terms.end(), power_terms.begin(), 0.0);
    std::cout << std::format("{:.15f}\n", pi);
}
