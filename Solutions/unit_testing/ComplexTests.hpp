#ifndef ComplexTests_H
#define ComplexTests_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>

class ComplexTests : public CppUnit::TestFixture
{
public:
    static CppUnit::Test* suite();

    void testConstructors();
    void testAssignment();
    void testEquality();
    void testInequality();
    
    void testGetters();
    void testSetters();

    void testPlus();
    void testMinus();
    void testMultiply();
    void testDivide();

    void testPlusEquals();
    void testMinusEquals();
    void testMultiplyEquals();
    void testDivideEquals();

};

#endif // ComplexTests_H
