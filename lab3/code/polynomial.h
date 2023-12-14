/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

class Polynomial
{
	public:
		/* CONSTRUCTORS */
		// Default Constructor
		Polynomial();

		// Constructor for singelton with value m
		Polynomial(int m);

		// Constructor for singleton with multiplication m and exponent x
		Polynomial(int m, int x);

		// Constructor from a vector of m and x values
		Polynomial(const std::vector<std::pair<int, int>> &in);

		// Destructor
		~Polynomial();

		/* MEMBER FUNCTIONS */
		// Return the degree of the given polynomial
		int degree();

		// Converts polynomial to string
		operator std::string() const;

		// Increment operator overloading
		Polynomial &operator+=(const Polynomial &p);

		// Decrement operator overloading
		Polynomial &operator-=(const Polynomial &p);

		// Multiply & increment operator overloading
		Polynomial &operator*=(const Polynomial &p);

		// Equality operator
		friend bool operator==(const Polynomial &lhs, const Polynomial &rhs);

		// Add polynomials
		friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);

		// Subtract polynomials
		friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);

		// Multiply polynomials
		friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);

		// Polynomial stream operator
		friend std::ostream &operator<<(std::ostream &os, const Polynomial &p);

	private:
		std::map<int, int> coefficients_table;
};
