#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
	Base* num1;
        Base* num2;
    public:
        Sub(Base* value1, Base* value2) : num1(value1), num2(value2){ }
        double evaluate() { return num1 -> evaluate() - num2 -> evaluate(); }
        virtual std::string stringify() { return "(" + num1 -> stringify() +" - "+ num2 -> stringify() +")"; }
};
#endif //__SUB_HPP__
