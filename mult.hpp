#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
	Base* num1;
        Base* num2;
    public:
        Mult(Base* value1, Base* value2) : num1(value1), num2(value2){ }
        double evaluate() { return num1 -> evaluate() * num2 -> evaluate(); }
        std::string stringify() { return "("+ num1 -> stringify()+ " * "+ num2 -> stringify()+")"; }
};
#endif //__MULT_HPP__
