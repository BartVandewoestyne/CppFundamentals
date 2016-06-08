#ifndef TStringTests_H
#define TStringTests_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
using namespace CppUnit;

#include "../memory/TString.h"

//------------------------------------------------------------
class TStringTests : public TestFixture
{
public:
    static Test* suite();

    void testConstructors();
    void testAssignment();
    void testEquality();
    void testInequality();
    void testConcatenation();
    void testgetLength();

// private:
//     TString s, t, u, v, w, x;
};
//------------------------------------------------------------

#endif //TStringTests_H
