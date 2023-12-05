/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double Epsilon = 1.0e-5;

class Expression {
    public:
        // Destructor
        virtual ~Expression() {
            --count_expressions;
        }

        // ADD OTHER MEMBER FUNCTIONS
        friend std::ostream &operator<<(std::ostream &os, const Expression &e)
        {
            e.display(os);
            return os;
        }

		double operator()(const double d) const;

		virtual double evaluate(const double d) const = 0;

        virtual void display(std::ostream &os) const = 0;

		virtual bool isRoot(const double d) const = 0;

        virtual Expression *clone() const = 0;


        // Return number of existing instances of class Expression
        // Used only for debug purposes
        static std::size_t get_count_expressions();

    protected:
        // Default constructor
        Expression() {
            ++count_expressions;
        }

        // Copy constructor
        Expression(const Expression&) {
            ++count_expressions;
        }

        // total number of existing expressions -- only to help to detect bugs in the code
        static std::size_t count_expressions;

		Expression &operator=(const Expression &e) = default;
};
