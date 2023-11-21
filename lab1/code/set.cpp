#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node
}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    insert_first(x);
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    Node* n1;
    Node* n2;
    for(int i : elements)
    {
        n1 = head;
        while(n1 != nullptr && !member(i))
        {
            n2 = n1;
            n1 = n1->next;

            if(n1 == nullptr || n1->value > i)
            {
                insert_after(i, n2);
                n1 = nullptr;
            }
        }
    }
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    Node* n1 = rhs.head->next;   // Original node to copy from

    // Goes through the set rhs and inserts each element into this set.
    while(n1 != nullptr)
    {
        insert_last(n1->value);
        n1 = n1->next;
    }
    counter = rhs.counter;
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) { // Call-by-value, copies rhs.
    // Swaps the head and counter of the copied set.
    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);

    // Destructor for rhs is called.
    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // Goes through the set removing the first node until the set is empty
    // lastly deletes the head.
    while(head->next != nullptr)
        remove_first();
    delete head;
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    return counter; // The counter holds the number of nodes (elements) in the set.
}

// Test if set is empty
bool Set::empty() const {
    return(counter == 0); // If the counter is 0, there are no nodes in the set.
}

bool Set::member(int x) const {
    Node* n = head->next;

    // Goes through this set checking if x appears in the set.
    // If it does exist return true. If not reutrn false.
    while(n != nullptr)
    {
        if(n->value == x)
            return true;
        n = n->next;
    }
    return false;
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const {
    Node *n1 = head->next;

    // Goes through this set checking if every element is a
    // member in set b. If an element is not a member return false.
    while(n1 != nullptr)
    {
        if(!b.member(n1->value))
            return false;
        n1 = n1->next;
    }

    return true;
}

// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    Set s;
    Node* n1 = head->next;
    Node* n2 = b.head->next;

    // Goes through both set this and set b.
    // For each element of both sets we see which one is less than the other.
    // The smaller element gets added to the resulting set.
    while(n1 != nullptr && n2 != nullptr)
    {
        if(n1->value < n2->value)
        {
            s.insert_last(n1->value);
            n1 = n1->next;
        }
        else if(n2->value < n1->value)
        {
            s.insert_last(n2->value);
            n2 = n2->next;
        }
        else
        {
            s.insert_last(n1->value);
            n1 = n1->next;
            n2 = n2->next;
        }
    }

    while(n1 != nullptr)
    {
        s.insert_last(n1->value);
        n1 = n1->next;
    }

    while(n2 != nullptr)
    {
        s.insert_last(n2->value);
        n2 = n2->next;
    }

    return s;
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    Set s;
    Node* n1 = head->next;

    // Goes through this set checking if each element is a member of set b.
    // If the element is a member we add it to the resulting set.
    while(n1 != nullptr)
    {
        if(b.member(n1->value))
            s.insert_last(n1->value);
        n1 = n1->next;
    }

    return s;
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    Set s;
    Node* n1 = head->next;

    // Goes through this set checking if each element is a member of set b.
    // If the element is not a member we add it to the resulting set.
    while(n1 != nullptr)
    {
        if(!b.member(n1->value))
            s.insert_last(n1->value);
        n1 = n1->next;
    }

    return s;
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

// Inserts a node directly after head and assigns it value x.
void Set::insert_first(int x)
{
    head->next = new Node{x, head->next};
    counter++;
}

// Insert a node last in a set and assign it value x.
void Set::insert_last(int x)
{
    Node* n = head;
    while(n->next != nullptr)
        n = n->next;
    n->next = new Node{x, nullptr};
    counter++;
}

// Inserts a node directly after node n and assigns it value x.
void Set::insert_after(int x, Node* n)
{
    n->next = new Node{x, n->next};
    counter++;
}


// Removes the first node after head.
void Set::remove_first()
{
    Node* n = head->next;
    head->next = n->next;
    delete n;
    counter--;
}

// Displays a set
void Set::display() const
{
    Node* n = head;

    while(n->next != nullptr)
    {
        std::cout << n->value << ", ";
        n = n->next;
    }
    std::cout << n->value << "\n";
}
