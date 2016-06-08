#include "TestCallerTests.hpp"
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using namespace std;
using CppUnit::TestSuite;

#include "TestCaller.hpp"
using tass::TestCaller;

struct ToBeCalled
{
    bool doSomethingCalled;
    bool setUpCalled;
    bool tearDownCalled;

    ToBeCalled() : 
        doSomethingCalled(false), setUpCalled(false), tearDownCalled(false) {}
    
    void setUp(){ setUpCalled = true; }
    void tearDown(){ tearDownCalled = true; }
    void doSomething(){ doSomethingCalled = true; }
};

//------------------------------------------------------------
Test* TestCallerTests::suite()
{
    TestSuite* suite = new TestSuite();
    suite->addTest(new CppUnit::TestCaller<TestCallerTests>("test Constructor", &TestCallerTests::testConstructor));
    suite->addTest(new CppUnit::TestCaller<TestCallerTests>("test testRun", &TestCallerTests::testRun));
    suite->addTest(new CppUnit::TestCaller<TestCallerTests>("test setUp", &TestCallerTests::testSetUp));
    suite->addTest(new CppUnit::TestCaller<TestCallerTests>("test tearDown", &TestCallerTests::testTearDown));
    return suite;
}
//------------------------------------------------------------
void TestCallerTests::testConstructor()
{
    tass::TestCaller<ToBeCalled> tc("test", &ToBeCalled::doSomething);
    CPPUNIT_ASSERT(!tc.t->doSomethingCalled);
}
//------------------------------------------------------------
void TestCallerTests::testRun()
{
    tass::TestCaller<ToBeCalled> tc("test", &ToBeCalled::doSomething);
    tc.runTest();
    CPPUNIT_ASSERT(tc.t->doSomethingCalled);
}
//------------------------------------------------------------
void TestCallerTests::testSetUp()
{
    tass::TestCaller<ToBeCalled> tc("test", &ToBeCalled::doSomething);
    tc.setUp();
    CPPUNIT_ASSERT(tc.t->setUpCalled);
}
//------------------------------------------------------------
void TestCallerTests::testTearDown()
{
    tass::TestCaller<ToBeCalled> tc("test", &ToBeCalled::doSomething);
    tc.tearDown();
    CPPUNIT_ASSERT(tc.t->tearDownCalled);
}
//------------------------------------------------------------
