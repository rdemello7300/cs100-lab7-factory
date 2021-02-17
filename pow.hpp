#ifndef POW_HPP
#define POW_HPP

#include <math.h>
#include "base.hpp"

class Pow : public Base {
    private:
        Base* num1;
        Base* num2;
    public:
        Pow(Base* value1, Base* value2) : num1(value1), num2(value2){ }
        double evaluate() { return pow(num1 -> evaluate(), num2 -> evaluate()); }
        std::string stringify() { return "(" + num1 -> stringify() + " ** " + num2 -> stringify() + ")"; }
};
#endif //POW_HPP
