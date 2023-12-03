/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

Logarithm::Logarithm()
{
    b = 2;
    c1 = 0.0;
    c2 = 1.0;
    std::vector v{0.0, 1.0};
    e = new Polynomial{v};
}

Logarithm::Logarithm(const Logarithm &l) : Expression{}
{
    b = l.b;
    c1 = l.c1;
    c2 = l.c2;
    e = l.e->clone();
}

Logarithm::Logarithm(const Expression &exp, double x, double y, int base)
{
    b = base;
    c1 = x;
    c2 = y;
    e = exp.clone();
}

Logarithm::~Logarithm()
{
    delete e;
}

Logarithm *Logarithm::clone() const
{
    return new Logarithm{*this};
}

void Logarithm::display(std::ostream &os) const
{
    std::string sign;
    os.precision(2);
    if(c2 < 0)
        sign = " - ";
    else
        sign = " + ";

    os << std::fixed << c1 << sign << std::abs(c2) << " * Log_" << b << "( " << *e << " )";
}

Logarithm::operator std::string() const
{
    std::stringstream s;

    s << *this;

    return s.str();
}

void Logarithm::set_base(int base)
{
    b = base;
}
