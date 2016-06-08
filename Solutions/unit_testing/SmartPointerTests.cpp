#include "SmartPointerTests.hpp"
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using namespace std;
using namespace CppUnit;

#include "../templates/SmartPointer.hpp"
#include "../classes/Complex.h"

//------------------------------------------------------------
Test* SmartPointerTests::suite()
{
    TestSuite* suite = new TestSuite();
    suite->addTest(new TestCaller<SmartPointerTests>("test Constructor", &SmartPointerTests::testConstructors));
    suite->addTest(new TestCaller<SmartPointerTests>("test Assignment", &SmartPointerTests::testAssignment));
    suite->addTest(new TestCaller<SmartPointerTests>("test refcount", &SmartPointerTests::testRefcount));
    suite->addTest(new TestCaller<SmartPointerTests>("test refcount", &SmartPointerTests::testDereference));
    suite->addTest(new TestCaller<SmartPointerTests>("test refcount", &SmartPointerTests::testMemberOperator));
    suite->addTest(new TestCaller<SmartPointerTests>("test equality", &SmartPointerTests::testEquality));
    // Add equality tests
    return suite;
}
//------------------------------------------------------------
void SmartPointerTests::testConstructors()
{
    SmartPointer<int> nsp;
    CPPUNIT_ASSERT(0 == nsp.pointee);

    int* ip = new int;
    SmartPointer<int> sp(ip);
    CPPUNIT_ASSERT(ip == sp.pointee);

    SmartPointer<int> sp2(sp);
    CPPUNIT_ASSERT(ip == sp2.pointee);
}
//------------------------------------------------------------
void SmartPointerTests::testAssignment()
{
    int* ip = new int;
    SmartPointer<int> sp(ip);
    CPPUNIT_ASSERT(ip == sp.pointee);

    SmartPointer<int> sp2 = sp;
    CPPUNIT_ASSERT(ip == sp2.pointee);
}
//------------------------------------------------------------
/**
 * @brief Test if SmartPointer call's the appropriate functions of ReferenceCounter
 * This seems like testing the ReferenceCounter implementation, but we're actually verifying
 * that SmartPointer calls the correct ReferenceCounter functions at the correct time.
 */
void SmartPointerTests::testRefcount()
{
    int* ip = new int;
    SmartPointer<int> sp(ip);
    CPPUNIT_ASSERT(1 == *sp.counter);

    {
        SmartPointer<int> sp2(sp);
        CPPUNIT_ASSERT(2 == *sp2.counter);
    }
    // sp2 is already out of scope again (destroyed) so refcount should be 1
    CPPUNIT_ASSERT(1 == *sp.counter);
    
    {
        SmartPointer<int> sp3;
        CPPUNIT_ASSERT(1 == *sp3.counter);
        sp3 = sp;
        CPPUNIT_ASSERT(2 == *sp.counter);
        CPPUNIT_ASSERT(2 == *sp3.counter);
    }
    CPPUNIT_ASSERT(1 == *sp.counter);
}
//------------------------------------------------------------
void SmartPointerTests::testDereference()
{
    int* ip = new int;
    *ip = 99;
    SmartPointer<int> sp(ip);
    CPPUNIT_ASSERT(99 == *sp);
    *sp = 66;
    CPPUNIT_ASSERT(66 == *ip);
}
//------------------------------------------------------------
void SmartPointerTests::testMemberOperator()
{
    SmartPointer<Complex> sp(new Complex(66, 99));
    CPPUNIT_ASSERT(66 == sp->getReal());
    CPPUNIT_ASSERT(99 == sp->getImaginary());
}
//------------------------------------------------------------
void SmartPointerTests::testEquality()
{
    SmartPointer<Complex> sp(new Complex(66, 99));
    SmartPointer<Complex> sp2(new Complex(0, 0));

    CPPUNIT_ASSERT( !(sp==sp2));
    CPPUNIT_ASSERT( (sp==sp));

    CPPUNIT_ASSERT( !(sp==(const Complex*)0));
    CPPUNIT_ASSERT( !((const Complex*)0==sp));
}
//------------------------------------------------------------
// void SmartPointerTests::testEquality()
// {
//     SmartPointer<Complex> sp(new Complex(66, 99));
//     SmartPointer<Complex> sp2(new Complex(0, 0));

//     CPPUNIT_ASSERT( !(sp==sp2));
//     CPPUNIT_ASSERT( (sp==sp));
// }
//------------------------------------------------------------
