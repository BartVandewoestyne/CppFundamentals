#ifndef TestCallerTests_H
#define TestCallerTests_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
using namespace CppUnit;

class TestCallerTests : public TestFixture
{
public:
    static Test* suite();

    void testConstructor();
    void testSetUp();
    void testTearDown();
    void testRun();
};


#endif // TestCallerTests_H
