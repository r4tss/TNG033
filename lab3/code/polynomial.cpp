/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

Polynomial::Polynomial()
{
	coefficients_table.insert({0, 0});
}

Polynomial::Polynomial(int m)
{
	if(m != 0)
		coefficients_table.insert({0, m});
}

Polynomial::Polynomial(int m, int x)
{
	if(m != 0)
		coefficients_table.insert({x, m});
}

Polynomial::Polynomial(const std::vector<std::pair<int, int>> &in)
{
	// std::inserter produces an iterator for the map
	std::transform(in.begin(), in.end(), std::inserter(coefficients_table, coefficients_table.end()), [] (const std::pair<int, int> &p)
			{
			if(p.second != 0)
				return p;
			return std::make_pair(0,0); // Useless - create an empty element if value == 0, removes a warning
			});
}

Polynomial::~Polynomial()
{
	coefficients_table.clear();
}

int Polynomial::degree()
{
	// Returns the key of the last element
	// This works since the map is in order
	return (coefficients_table.rbegin())->first;
}

// TODO: simplify this when zeroes are not stored in the coefficients_table.
Polynomial::operator std::string() const
{
	std::stringstream s;

	// First is the key and second is the value of each element
	for(auto i = coefficients_table.begin();i != coefficients_table.end();i++)
	{
		if(i == coefficients_table.begin())
		{
			if(i->first == 0 && i->second == 0)
				s << i->second;
			else
				s << i->second << "X^" << i->first;
		}
		else
		{
			if(i != ++coefficients_table.begin() || coefficients_table.begin()->second != 0)
			{
				if(i->second < 0)
					s << " - ";
				else
					s << " + ";
			}

			s << ((i->second >= 0) ? i->second : -i->second) << "X^" << i->first;
		}
	}

	return s.str();
}

Polynomial &Polynomial::operator+=(const Polynomial &p)
{
	for(auto i = p.coefficients_table.begin();i != p.coefficients_table.end();i++)
	{
		coefficients_table[i->first] += i->second;

		// Remove an element if it equates to zero
		if(coefficients_table[i->first] == 0)
			coefficients_table.erase(i->first);
	}
	return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &p)
{
	for(auto i = p.coefficients_table.begin();i != p.coefficients_table.end();i++)
	{
		coefficients_table[i->first] -= i->second;

		// Remove an element if it equates to zero
		if(coefficients_table[i->first] == 0)
			coefficients_table.erase(i->first);
	}
	return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &p)
{
	std::map<int, int> result_table;

	auto i1 = coefficients_table.begin();
	auto i2 = p.coefficients_table.begin();

	while(i2 != p.coefficients_table.end())
	{
		result_table[i1->first + i2->first] += i1->second * i2->second;
		if(result_table[i1->first + i2->first] == 0)
			result_table.erase(i1->first + i2->first);
		if(i1 != coefficients_table.end())
			i1++;
		else
		{
			i2++;
			i1 = coefficients_table.begin();
		}
	}
	
	coefficients_table = result_table;

	return *this;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs)
{
	return (lhs.coefficients_table == rhs.coefficients_table);
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs)
{
	Polynomial p = lhs;
	p += rhs;
	return p;
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs)
{
	Polynomial p = lhs;
	p -= rhs;
	return p;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs)
{
	Polynomial p = lhs;
	p *= rhs;
	return p;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &p)
{
	return os << std::string(p);
}
