/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression
{
        public:
        Logarithm();

	Logarithm(const Logarithm &l);

        Logarithm(const Expression &exp, double x, double y, int base);

        ~Logarithm();

        void display(std::ostream &os) const override;

        Logarithm *clone() const override;

        operator std::string() const;

        void set_base(int base);

        private:
        int b;
        double c1, c2;
        Expression *e;
};
