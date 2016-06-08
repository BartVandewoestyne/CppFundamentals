#include "DetokenizerTests.hpp"
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
//#include <iostream>
using namespace std;
//using CppUnit::TestSuite;

#include "Detokenizer.hpp"
//using tass::Detokenizer;

//------------------------------------------------------------
CppUnit::Test* DetokenizerTests::suite()
{
    CppUnit::TestSuite* suite = new CppUnit::TestSuite();
    suite->addTest(new CppUnit::TestCaller<DetokenizerTests>("test nextToken", &DetokenizerTests::testNextToken));
    suite->addTest(new CppUnit::TestCaller<DetokenizerTests>("test reset", &DetokenizerTests::testReset));
    return suite;
}
//------------------------------------------------------------
void DetokenizerTests::testNextToken()
{
    Detokenizer dt("this.is,a.test", ",.");
    CPPUNIT_ASSERT(dt.startFromBeginning);
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("this"));
    CPPUNIT_ASSERT(!dt.startFromBeginning);
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("is"));
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("a"));
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("test"));
}
//------------------------------------------------------------
void DetokenizerTests::testReset()
{
    Detokenizer dt("this.is,a.test", ",.");
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("this"));
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("is"));
    dt.reset();
    CPPUNIT_ASSERT(dt.startFromBeginning);
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("this"));
    CPPUNIT_ASSERT(0 == dt.nextToken().compare("is"));
}
//------------------------------------------------------------
