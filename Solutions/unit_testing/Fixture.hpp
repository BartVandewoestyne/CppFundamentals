#ifndef Fixture_H
#define Fixture_H

template<class T>
class Fixture
{
    virtual ~TestFixture(){}
    virtual void setUp(){}
    virtual void tearDown(){}
}

#endif // Fixture_H
