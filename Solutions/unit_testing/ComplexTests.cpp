#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using namespace std;
using CppUnit::TestSuite;
using CppUnit::Test;
//using CppUnit::TestCaller;
#include "TestCaller.hpp"
using tass::TestCaller;

#include "ComplexTests.hpp"
#include "../classes/Complex.h"

//------------------------------------------------------------
Test* ComplexTests::suite()
{
    TestSuite* suite = new TestSuite();
    suite->addTest(new TestCaller<ComplexTests>("test Constructor", &ComplexTests::testConstructors));
    suite->addTest(new TestCaller<ComplexTests>("test Assignment", &ComplexTests::testAssignment));
    suite->addTest(new TestCaller<ComplexTests>("test Equality", &ComplexTests::testEquality));
    suite->addTest(new TestCaller<ComplexTests>("test Inequality", &ComplexTests::testInequality));

    suite->addTest(new TestCaller<ComplexTests>("test Getters", &ComplexTests::testGetters));
    suite->addTest(new TestCaller<ComplexTests>("test Setters", &ComplexTests::testSetters));

    suite->addTest(new TestCaller<ComplexTests>("test Plus", &ComplexTests::testPlus));
    suite->addTest(new TestCaller<ComplexTests>("test Minus", &ComplexTests::testMinus));
    suite->addTest(new TestCaller<ComplexTests>("test Multiply", &ComplexTests::testMultiply));
    suite->addTest(new TestCaller<ComplexTests>("test Divide", &ComplexTests::testDivide));

    suite->addTest(new TestCaller<ComplexTests>("test PlusEquals", &ComplexTests::testPlusEquals));
    suite->addTest(new TestCaller<ComplexTests>("test MinusEquals", &ComplexTests::testMinusEquals));
    suite->addTest(new TestCaller<ComplexTests>("test MultiplyEquals", &ComplexTests::testMultiplyEquals));
    suite->addTest(new TestCaller<ComplexTests>("test DivideEquals", &ComplexTests::testDivideEquals));

    return suite;
}
//------------------------------------------------------------
void ComplexTests::testConstructors()
{
    Complex c;
    CPPUNIT_ASSERT(0 == c.real && 0 == c.imaginary);

    Complex d(66, 99);
    CPPUNIT_ASSERT(66 == d.real && 99 == d.imaginary);
    //CPPUNIT_ASSERT(66 == d.real && 98 == d.imaginary); // For testing tass::TestCaller

    Complex e(c);
    CPPUNIT_ASSERT(0 == e.real && 0 == e.imaginary);

    Complex f(d);
    CPPUNIT_ASSERT(66 == f.real && 99 == f.imaginary);
}
//------------------------------------------------------------
void ComplexTests::testAssignment()
{
    Complex c(66, 99);
    Complex d = c;
    CPPUNIT_ASSERT(66 == d.real && 99 == d.imaginary);
}
//------------------------------------------------------------
void ComplexTests::testEquality()
{
    Complex c(66, 99);
    Complex d = c;
    Complex e;
    CPPUNIT_ASSERT(d == c);
    CPPUNIT_ASSERT(!(e == c));
}
//------------------------------------------------------------
void ComplexTests::testInequality()
{
    Complex c(66, 99);
    Complex d = c;
    Complex e;
    CPPUNIT_ASSERT(e != c);
    CPPUNIT_ASSERT(!(d != c));
}
//------------------------------------------------------------
void ComplexTests::testGetters()
{
    Complex c(66, 99);
    CPPUNIT_ASSERT(66 == c.getReal());
    CPPUNIT_ASSERT(99 == c.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testSetters()
{
    Complex c;
    c.setReal(66);
    c.setImaginary(99);    
    CPPUNIT_ASSERT(66 == c.real);
    CPPUNIT_ASSERT(99 == c.imaginary);
}
//------------------------------------------------------------
void ComplexTests::testPlus()
{
    Complex a(3, 4);
    Complex b(7, 8);
    Complex result = a + b;
    CPPUNIT_ASSERT(10 == result.getReal());
    CPPUNIT_ASSERT(12 == result.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testMinus()
{
    Complex a(3, 4);
    Complex b(7, 8);
    Complex result = a - b;
    CPPUNIT_ASSERT(-4 == result.getReal());
    CPPUNIT_ASSERT(-4 == result.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testMultiply()
{
    Complex a(3, 4);
    Complex b(7, 8);
    Complex result = a * b;
    CPPUNIT_ASSERT(-11 == result.getReal());
    CPPUNIT_ASSERT(52 == result.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testDivide()
{
    Complex a(3, 4);
    Complex b(7, 8);
    Complex result = a / b;
    CPPUNIT_ASSERT(0 == result.getReal());
    CPPUNIT_ASSERT(0 == result.getImaginary());

    a.setReal(30);                            
    a.setImaginary(40);

    result = a / b;
    CPPUNIT_ASSERT(4 == result.getReal());
    CPPUNIT_ASSERT(0 == result.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testPlusEquals()
{
    Complex a(3, 4);
    Complex b(7, 8);
    a += b;
    CPPUNIT_ASSERT(10 == a.getReal());
    CPPUNIT_ASSERT(12 == a.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testMinusEquals()
{
    Complex a(3, 4);
    Complex b(7, 8);
    a -= b;
    CPPUNIT_ASSERT(-4 == a.getReal());
    CPPUNIT_ASSERT(-4 == a.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testMultiplyEquals()
{
    Complex a(3, 4);
    Complex b(7, 8);
    a *= b;
    CPPUNIT_ASSERT(-11 == a.getReal());
    CPPUNIT_ASSERT(52 == a.getImaginary());
}
//------------------------------------------------------------
void ComplexTests::testDivideEquals()
{
    Complex a(3, 4);
    Complex b(7, 8);
    a /= b;
    CPPUNIT_ASSERT(0 == a.getReal());
    CPPUNIT_ASSERT(0 == a.getImaginary());

    a.setReal(30);                            
    a.setImaginary(40);

    a /= b;
    CPPUNIT_ASSERT(4 == a.getReal());
    CPPUNIT_ASSERT(0 == a.getImaginary());
}
//------------------------------------------------------------


