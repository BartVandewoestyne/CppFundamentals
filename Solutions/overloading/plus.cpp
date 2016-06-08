
#include <iostream>
#include <cassert>

using namespace std;

struct Complex
{
    int real, imaginary;
};

Complex operator+(const Complex& a, const Complex& b)
{
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}


int main()
{
    Complex i, j;
    i.real = 3;
    i.imaginary = 4;
    j.real = 7;
    j.imaginary = 8;
    
    Complex r = i + j;
    assert(10 == r.real);
    assert(12 == r.imaginary);

    cout << "No assertions!" << endl;
}
