/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
    public:
        Polynomial();

        Polynomial(double x);

        Polynomial(std::vector<double> x);

        Polynomial(const Polynomial &p);

        ~Polynomial();

        Polynomial *clone() const override;

		double evaluate(const double d) const override;

        double& operator[](int i) { return coeff[i]; };

        const double& operator[](int i) const { return coeff[i]; };

        operator std::string() const;

        Polynomial &operator=(const Polynomial &p);

        Polynomial &operator+=(const Polynomial &p);

        Polynomial &operator+=(const double d);

        Polynomial operator+(const Polynomial &p) const;

        void display(std::ostream &os) const override;

        double operator()(const double d) const;

        bool isRoot(const double d) const override;

    private:
        std::vector<double> coeff;
};

    Polynomial operator+(const Polynomial &lhs, const double rhs);

    Polynomial operator+(const double lhs, const Polynomial &rhs);
