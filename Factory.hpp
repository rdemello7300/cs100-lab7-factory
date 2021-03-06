#ifndef __FACTORY_HPP
#define __FACTORY_HPP

#include <iostream>
#include <string>
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Factory
{
  public:
     Factory() { };
     Base* parse(char** input, int length){
	queue<string> q;
	string str;
	int counter = 0;
        for(unsigned i = 1; i < length; i++){
	   str = static_cast<string>(input[i]);
           q.push(str);
	   counter++;
        }
	Base* prev;
	Base* cur;
	bool prevBool = false, curBool = false, isOper = false, isNumber = true;
	char oper;
	double Value;
	string::size_type sz;
	string s;
	while(!q.empty())
	{
	   s = q.front();
	   q.pop();
	  if(!prevBool)
	  {
	    if(is_number(s)){
	       Value = stod(s);
	       prev = new Op(Value);
	       prevBool = true;
	    }
	    else
	    {
	       cout << "Invalid input" << endl;
	       return NULL;
	    }
	   }
	  else if(prevBool && !isOper && !curBool)
	  {
	     if(s == "-") oper = '-';
             else if(s == "+") oper = '+';
             else if(s == "*") oper = '*';
             else if(s == "/") oper = '/';
             else if(s == "**") oper = '^';
	     else return NULL;
             isOper = true;	
	  }
	else{
	  if(is_number(s)){
	     Value = stod(s);
	     cur = new Op(Value);
	     prev = calculate(prev, cur, oper);
	     isOper = false;
	  }
	  else
	  {
	     cout << "Invalid input" << endl;
	     return NULL;
	  }
	}
	}
	return prev;

}
 /**
 * The purpose is to have the Base parse to pass on a past(a) value
 * it's operator and it's current(b) value
 * For example a \operator b
 * In which this class will handle the dynamic input from the user
 */
    Base* calculate(Base* prevValue, Base* curValue, char operand)
    {
        switch(operand)
        {
           case '-' :
             return new Sub(prevValue, curValue);
             break;

           case '+' :
             return new Add(prevValue, curValue);
             break;

           case '*' :
             return new Mult(prevValue, curValue);
             break;

          case '/' :
            return new Div(prevValue, curValue);
            break;
	  
	  case '^':
	    return new Pow(prevValue, curValue);
	    break;

          default :
            return NULL;

        }

    }
 /**
 *Just checks if the string pass by Base parse is 
 *a number or not
 */
   bool is_number(string str){
     for(int i = 0;i < (strlen(str.c_str()) - 1);i++) {
		if(isdigit(str[i]) == false) return false;
	}
	return true;
   }

};

#endif
