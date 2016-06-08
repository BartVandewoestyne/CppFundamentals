#include <iostream>
#include <cassert>
#include <cstring>
#include "TString.h"

using namespace std;

const char* TEST_STRING = "TestString";
const char* TEST_SUBSTRING = "Test";
const char* TEST_SUBSTRING_END = "String";
const char* TEST_STRING_FILL = "ZZZZ";

int main()
{
    // Test all constructors (& conversion operator implicitly)
    TString s;
    assert(0 == (const char*)s);

    TString t(TEST_STRING);
    assert(0 == strcmp(TEST_STRING, (const char*)t));
    
    TString u(t);
    assert(0 == strcmp(TEST_STRING, (const char*)u));

    TString v(t, 4, 6);
    assert(0 == strcmp(TEST_SUBSTRING_END, (const char*)v));
    
    TString w(t, 4);
    assert(0 == strcmp(TEST_SUBSTRING, (const char*)w));

    TString x(4, 'Z');
    assert(0 == strcmp(TEST_STRING_FILL, (const char*)x));

    // Test operators
    s = t;
    assert(0 == strcmp(TEST_STRING, (const char*)s));
    
    assert(s == t);
    assert(s != x);
    assert(t == w + v);

    // Test getLength
    assert(strlen(TEST_STRING) == t.getLength());

    cout << t << endl;

    cout << "Made it to the end without assertions! Yay!" << endl;
}
