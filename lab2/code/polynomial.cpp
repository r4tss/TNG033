/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include <iomanip>
#include <cmath>

#include "polynomial.h"

Polynomial::Polynomial() {}

// Constructor for value input
Polynomial::Polynomial(double x)
{
    coeff.insert(coeff.begin(), x);
}

// Constructor for vector input
Polynomial::Polynomial(std::vector<double> x)
{
    coeff = x;
}

// Copy constructor
Polynomial::Polynomial(const Polynomial &p) : Expression{}
{
    coeff = p.coeff;
}

Polynomial::~Polynomial()
{
    coeff = std::vector<double>();
}

// Converts polynomial to string
Polynomial::operator std::string() const
{
    std::stringstream s;

    s << *this;

    return s.str();
}

// Assignment operator
Polynomial &Polynomial::operator=(const Polynomial &p)
{
    coeff = p.coeff;
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    int i = 0;

    while(i < (int)coeff.size() && i < (int)p.coeff.size())
    {
        coeff[i] = coeff[i] + p.coeff[i];
        i++;
    }

    while(i < (int)p.coeff.size())
    {
        coeff.insert(coeff.end(), p.coeff[i]);
        i++;
    }

    return *this;
}

Polynomial &Polynomial::operator+=(const double d)
{
    coeff[0] += d;

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) const
{
    Polynomial res = *this;

    res += p;

    return res;
}

Polynomial operator+(const Polynomial &lhs, const double rhs)
{
    Polynomial res = lhs;

    res[0] += rhs;

    return res;
}

Polynomial operator+(const double lhs, const Polynomial &rhs)
{
    Polynomial res = rhs;

    res[0] += lhs;

    return res;
}

double Polynomial::operator()(const double x) const
{
    double res = 0.0;
    int i = 0;

    for(double y : coeff)
    {
        res += y * (std::pow(x,i));
        i++;
    }

    return res;
}

bool Polynomial::isRoot(const double x) const
{
    double d = this->operator()(x);

    if(std::abs(d) < Epsilon)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &p)
{
    os.precision(2);

    for(int i = 0;i < (int)p.coeff.size();i++)
    {
        if(i > 0)
        {
            os << std::fixed << std::abs(p.coeff[i]) << " * X^" << i;
        }
        else
        {
            os << std::fixed << std::abs(p.coeff[i]);
        }

        if(i + 1 < (int)p.coeff.size())
        {
            if(p.coeff[i + 1] < 0)
                os << " - ";
            else
                os << " + ";
        }
    }

    return os;
}
