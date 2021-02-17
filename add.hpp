#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
    private:
	Base* num1;
        Base* num2;
    public:
        Add(Base* value1, Base* value2) : num1(value1), num2(value2){ }
        double evaluate() { return num1 -> evaluate() + num2 -> evaluate(); }
        virtual std::string stringify() { return "("+ num1 -> stringify()+ " + "+ num2 -> stringify()+")"; }
};
#endif //__ADD_HPP__
