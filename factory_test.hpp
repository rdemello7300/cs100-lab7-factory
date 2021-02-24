#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <iostream>
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "Factory.hpp"

using namespace std;

TEST(FactoryTestAdd, AddZero)
{
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "+"; test_val[3] = "0";
	Factory* testFact = new Factory();
	Base* testExp = testFact -> parse(test_val, 4);
	double eval = testExp -> evaluate();
	string s = testExp -> stringify();
	EXPECT_NEAR(2, eval, 0.01);
	EXPECT_EQ("(2.000000 + 0.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestAdd, AddEval)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "+"; test_val[3] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(5, eval, 0.01);
        EXPECT_EQ("(2.000000 + 3.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestAdd, AddMultiple)
{
        char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "+"; test_val[3] = "3"; test_val[4] = "+"; test_val[5] = "4";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 6);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(9, eval, 0.01);
        EXPECT_EQ("((2.000000 + 3.000000) + 4.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestSub, SubZero)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "-"; test_val[3] = "0";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(2, eval, 0.01);
        EXPECT_EQ("(2.000000 - 0.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestSub, SubEval)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "-"; test_val[3] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(-1, eval, 0.01);
        EXPECT_EQ("(2.000000 - 3.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestSub, SubMultiple)
{
        char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "-"; test_val[3] = "3"; test_val[4] = "-"; test_val[5] = "4";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 6);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(-5, eval, 0.01);
        EXPECT_EQ("((2.000000 - 3.000000) - 4.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestMult, MultZero)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "*"; test_val[3] = "0";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(0, eval, 0.01);
        EXPECT_EQ("(2.000000 * 0.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestMult, MultEval)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "*"; test_val[3] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(6, eval, 0.01);
        EXPECT_EQ("(2.000000 * 3.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestMult, MultMultiple)
{
        char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "*"; test_val[3] = "3"; test_val[4] = "*"; test_val[5] = "4";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 6);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(24, eval, 0.01);
        EXPECT_EQ("((2.000000 * 3.000000) * 4.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestDiv, DivZero)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "0"; test_val[2] = "/"; test_val[3] = "2";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(0, eval, 0.01);
        EXPECT_EQ("(0.000000 / 2.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestDiv, DivEval)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "6"; test_val[2] = "/"; test_val[3] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(2, eval, 0.01);
        EXPECT_EQ("(6.000000 / 3.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestDiv, DivMultiple)
{
        char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "16"; test_val[2] = "/"; test_val[3] = "4"; test_val[4] = "/"; test_val[5] = "4";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 6);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(1, eval, 0.01);
        EXPECT_EQ("((16.000000 / 4.000000) / 4.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestPow, PowZero)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "0"; test_val[2] = "**"; test_val[3] = "2";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(0, eval, 0.01);
        EXPECT_EQ("(0.000000 ** 2.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestPow, PowEval)
{
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "**"; test_val[3] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 4);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(8, eval, 0.01);
        EXPECT_EQ("(2.000000 ** 3.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestPow, PowMultiple)
{
        char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "**"; test_val[3] = "3"; test_val[4] = "**"; test_val[5] = "2";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 6);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(64, eval, 0.01);
        EXPECT_EQ("((2.000000 ** 3.000000) ** 2.000000)", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestOther, NumOnly)
{
        char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "2";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 2);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(2, eval, 0.01);
        EXPECT_EQ("2.000000", s);
	delete testFact;
	delete testExp;
}

TEST(FactoryTestOther, AllOperations)
{
        char* test_val[12]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "+"; test_val[3] = "3"; test_val[4] = "-"; test_val[5] = "4"; test_val[6] = "*"; test_val[7] = "4"; test_val[8] = "/"; test_val[9] = "2"; test_val[10] = "**"; test_val[11] = "3";
        Factory* testFact = new Factory();
        Base* testExp = testFact -> parse(test_val, 12);
        double eval = testExp -> evaluate();
        string s = testExp -> stringify();
        EXPECT_NEAR(8, eval, 0.01);
        EXPECT_EQ("(((((2.000000 + 3.000000) - 4.000000) * 4.000000) / 2.000000) ** 3.000000)", s);
	delete testFact;
	delete testExp;
}

#endif
