#ifndef DetokenizerTests_H
#define DetokenizerTests_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>

class DetokenizerTests : public CppUnit::TestFixture
{
public:
    static CppUnit::Test* suite();

    void testNextToken();
    void testReset();
};

#endif // DetokenizerTests_H
