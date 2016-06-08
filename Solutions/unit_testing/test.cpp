
#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#define SUITE_CLASS_1 1
#define SUITE_CLASS_2 2
#define SUITE_CLASS_3 3
#define SUITE_CLASS_4 4
#define SUITE_CLASS_5 5

#if SUITE_CLASS == SUITE_CLASS_1
#warning TStringTests
#include "TStringTests.hpp"
#define SUITE_CLASS_ TStringTests
#elif SUITE_CLASS == SUITE_CLASS_2
#warning SmartPointerTests
#include "SmartPointerTests.hpp"
#define SUITE_CLASS_ SmartPointerTests
#elif SUITE_CLASS == SUITE_CLASS_3
#warning ComplexTests
#include "ComplexTests.hpp"
#define SUITE_CLASS_ ComplexTests
#elif SUITE_CLASS == SUITE_CLASS_4
#warning TestCallerTests
#include "TestCallerTests.hpp"
#define SUITE_CLASS_ TestCallerTests
#elif SUITE_CLASS == SUITE_CLASS_5
#warning DetokenizerTests
#include "DetokenizerTests.hpp"
#define SUITE_CLASS_ DetokenizerTests
#else
#error Please define SUITE_CLASS
#endif

using namespace CppUnit;
using namespace std;

int main()
{
    TextUi::TestRunner runner;
    runner.addTest(SUITE_CLASS_::suite());
    runner.run();
    cout << "Done!" << endl;
}
