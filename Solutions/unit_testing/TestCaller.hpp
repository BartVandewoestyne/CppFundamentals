#ifndef TestCaller_H
#define TestCaller_H

#include <cppunit/TestCase.h>

#include <string>
#include <iostream>
#include <memory>

class TestCallerTests;


namespace tass {

    template<class T>
    class TestCaller : public CppUnit::TestCase
    {
        friend class ::TestCallerTests;
        typedef void (T::* TestFunc)();

        std::shared_ptr<T> t;
        TestFunc func;

        // Not copyable or assignable
        // Is like this in CppUnit
        // But with shared_ptr this shouldn't be an issue
        TestCaller(const TestCaller& tc);
        TestCaller &operator=(const TestCaller& tc);

    public:
        TestCaller(const string& name, TestFunc func);
        TestCaller(const string& name, T* t, TestFunc func);
        virtual ~TestCaller(){}

        virtual void setUp();
        virtual void tearDown();
        //virtual void run(TestResult* result);
        //virtual void getName() const;
        virtual void runTest();
    };
//-----------------------------------------------------------
    template<class T>
    TestCaller<T>::TestCaller(const string& name, TestCaller<T>::TestFunc func) :
        CppUnit::TestCase(name),
        t(new T),
        func(func)
    {}
//-----------------------------------------------------------
    template<class T>
    TestCaller<T>::TestCaller(const string& name, T* t, TestCaller<T>::TestFunc func) :
        CppUnit::TestCase(name),
        t(t),
        func(func)
    {}
//-----------------------------------------------------------
    template<class T>
    void TestCaller<T>::setUp()
    {
        t->setUp();
    }
//-----------------------------------------------------------
    template<class T>
    void TestCaller<T>::tearDown()
    {
        t->tearDown();
    }
//-----------------------------------------------------------
    template<class T>
    void TestCaller<T>::runTest()
    {
        try
        {
            std::cout << "TestCaller<T>::run : Calling func" << std::endl;
            //(t->*func)(); // this works with raw pointer
            ((*t).*func)();
        }
        catch(...)
        {
            std::cout << "TestCaller<T>::run : Caught something" << std::endl;
            throw;
        }
    }
//-----------------------------------------------------------
}
#endif // TestCaller_H
