#include <iostream>
#include <string>
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include <vector>
#include "Factory.hpp"
using namespace std;

int main(int argc, char** argv)
{
    Factory* factory = new Factory();
    Base* out = factory -> parse( argv,argc);
    if(out == NULL) cout << "";
    else
    {
    	cout << "Number: " << out -> evaluate() << endl;
	cout << "String: " << out -> stringify() << endl;
    }
    delete factory;
    delete out;
    return 0;
}





