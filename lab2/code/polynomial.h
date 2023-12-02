/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
    // ADD CODE

    public:
        Polynomial();

        Polynomial(double x);

        Polynomial(std::vector<double> x);

        Polynomial(const Polynomial &p);

        ~Polynomial();

        double& operator[](int i) { return coeff[i]; };

        const double& operator[](int i) const { return coeff[i]; };

        operator std::string() const;

        Polynomial &operator=(const Polynomial &p);

        Polynomial &operator+=(const Polynomial &p);

        Polynomial &operator+=(const double d);

        Polynomial operator+(const Polynomial &p) const;

        friend std::ostream &operator<<(std::ostream &os, const Polynomial &p);

        double operator()(const double x) const;

        bool isRoot(const double x) const;

    private:
        std::vector<double> coeff;
};

    Polynomial operator+(const Polynomial &lhs, const double rhs);

    Polynomial operator+(const double lhs, const Polynomial &rhs);
