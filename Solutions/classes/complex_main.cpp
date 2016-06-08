#include <cassert>
#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a;
    assert(0 == a.getReal());
    assert(0 == a.getImaginary());

    a.setReal(5);
    a.setImaginary(6);
    assert(5 == a.getReal());
    assert(6 == a.getImaginary());

    a = Complex(3, 4);
    assert(3 == a.getReal());
    assert(4 == a.getImaginary());

    Complex b(7, 8);
    assert(!(a==b));
    assert(a!=b);

    Complex result(a);
    assert(3 == result.getReal());
    assert(4 == result.getImaginary());

    result = a + b;
    assert(10 == result.getReal());
    assert(12 == result.getImaginary());

    result = a - b;
    assert(-4 == result.getReal());
    assert(-4 == result.getImaginary());
    
    result = a * b;
    assert(-11 == result.getReal());
    assert(52 == result.getImaginary());

    result = a / b;
    assert(0 == result.getReal());
    assert(0 == result.getImaginary());

    a.setReal(30);                            
    a.setImaginary(40);

    result = a / b;
    assert(4 == result.getReal());
    assert(0 == result.getImaginary());
    
    result.setReal(3);                            
    result.setImaginary(4);

    result += b;
    assert(10 == result.getReal());
    assert(12 == result.getImaginary());

    result.setReal(3);                            
    result.setImaginary(4);

    result -= b;
    assert(-4 == result.getReal());
    assert(-4 == result.getImaginary());

    result.setReal(3);                            
    result.setImaginary(4);

    result *= b;
    assert(-11 == result.getReal());
    assert(52 == result.getImaginary());

    result.setReal(3);                            
    result.setImaginary(4);

    result /= b;
    assert(0 == result.getReal());
    assert(0 == result.getImaginary());


    result.setReal(30);                            
    result.setImaginary(40);

    result /= b;
    assert(4 == result.getReal());
    assert(0 == result.getImaginary());
    
    cout << "I ran all the way to the end! Yay!" << endl;

    return 0;
}
