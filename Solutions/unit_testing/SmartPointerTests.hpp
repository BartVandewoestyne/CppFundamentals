#ifndef SmartPointerTests_H
#define SmartPointerTests_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
using namespace CppUnit;

class SmartPointerTests : public TestFixture
{
public:
    static Test* suite();

    void testConstructors();
    void testAssignment();
    void testRefcount();  
    void testDereference();
    void testMemberOperator();
    void testEquality();
};

#endif // SmartPointerTests_H
