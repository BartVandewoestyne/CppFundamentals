#include <cppunit/extensions/HelperMacros.h>
#include <cstring>

#include "TStringTests.hpp"
//------------------------------------------------------------
const char* TEST_STRING = "TestString";
const char* TEST_SUBSTRING = "Test";
const char* TEST_SUBSTRING_END = "String";
const char* TEST_STRING_FILL = "ZZZZ";
//------------------------------------------------------------
Test* TStringTests::suite()
{
    TestSuite* suite = new TestSuite();
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testConstructors));
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testAssignment));
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testEquality));
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testInequality));
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testConcatenation));
    suite->addTest(new TestCaller<TStringTests>("test Constructors", &TStringTests::testgetLength));
    
    return suite;
}
//------------------------------------------------------------
void TStringTests::testConstructors()
{
    TString s;
    CPPUNIT_ASSERT(0 == (const char*)s);

    TString t(TEST_STRING);
    CPPUNIT_ASSERT(0 == strcmp(TEST_STRING, (const char*)t));
    
    TString u(t);
    CPPUNIT_ASSERT(0 == strcmp(TEST_STRING, (const char*)u));

    TString v(t, 4, 6);
    CPPUNIT_ASSERT(0 == strcmp(TEST_SUBSTRING_END, (const char*)v));
    
    TString w(t, 4);
    CPPUNIT_ASSERT(0 == strcmp(TEST_SUBSTRING, (const char*)w));

    TString x(4, 'Z');
    CPPUNIT_ASSERT(0 == strcmp(TEST_STRING_FILL, (const char*)x));
}
//------------------------------------------------------------
void TStringTests::testAssignment()
{
    TString s(TEST_STRING);
    TString t = s;
    CPPUNIT_ASSERT(0 == strcmp(TEST_STRING, (const char*)t));
}
//------------------------------------------------------------
void TStringTests::testEquality()
{
    TString s(TEST_STRING);
    TString t = s;
    TString v(TEST_SUBSTRING);
    CPPUNIT_ASSERT(t == s);
    CPPUNIT_ASSERT(!(v == s));
}
//------------------------------------------------------------
void TStringTests::testInequality()
{
    TString s(TEST_STRING);
    TString t = s;
    TString v(TEST_SUBSTRING);
    CPPUNIT_ASSERT(t != v);
    CPPUNIT_ASSERT(!(t != s));
}
//------------------------------------------------------------
void TStringTests::testConcatenation()
{
    TString t(TEST_STRING);
    TString v(t, 4);    // sequence
    TString w(t, 4, 6); // substring
    CPPUNIT_ASSERT(t == v + w);
}
//------------------------------------------------------------
void TStringTests::testgetLength()
{
    TString t(TEST_STRING);
    CPPUNIT_ASSERT(strlen(TEST_STRING) == t.getLength());
}
//------------------------------------------------------------
