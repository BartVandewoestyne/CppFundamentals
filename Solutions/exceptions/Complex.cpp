#include <cassert>
#include "Complex.h"
//------------------------------------------------------------
Complex::Complex() :
    real(),
    imaginary()
{}
//------------------------------------------------------------
Complex::Complex(int real, int imaginary) :
    real(real),
    imaginary(imaginary)
{}
//------------------------------------------------------------
Complex::Complex(const Complex& c) :
    real(c.real),
    imaginary(c.imaginary)
{}
//------------------------------------------------------------
Complex& Complex::operator=(const Complex& c)
{
    if (c != *this)
    {
        real = c.real;
        imaginary = c.imaginary;
    }
    return *this;
}
//------------------------------------------------------------
bool Complex::operator==(const Complex& c) const
{
    return real == c.real && imaginary == c.imaginary;
}
//------------------------------------------------------------
bool Complex::operator!=(const Complex& c) const
{
    return !operator==(c);
}
//------------------------------------------------------------
Complex Complex::operator+(const Complex& c) const
{
    return Complex(real+c.real, imaginary+c.imaginary);
}
//------------------------------------------------------------
Complex Complex::operator-(const Complex& c) const
{
    return Complex(real-c.real, imaginary-c.imaginary);
}
//------------------------------------------------------------
Complex Complex::operator*(const Complex& c) const
{
    return Complex((real*c.real - imaginary*c.imaginary), (real*c.imaginary + imaginary*c.real));
}
//------------------------------------------------------------
Complex Complex::operator/(const Complex& c) const
{
    if (0 == c.real && 0 == c.imaginary)
        throw DivisionByZeroException();

    int d = c.real*c.real + c.imaginary*c.imaginary;
    int r = (real*c.real + imaginary*c.imaginary) / d;
    int i = (imaginary*c.real - real*c.imaginary) / d;

    return Complex(r, i);
}
//------------------------------------------------------------
Complex& Complex::operator+=(const Complex& c)
{
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}
//------------------------------------------------------------
Complex& Complex::operator-=(const Complex& c)
{
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}
//------------------------------------------------------------
Complex& Complex::operator*=(const Complex& c)
{
    int r = real*c.real - imaginary*c.imaginary;
    int i = real*c.imaginary + imaginary*c.real;
    real = r;
    imaginary = i;
    return *this;
}
//------------------------------------------------------------
Complex& Complex::operator/=(const Complex& c)
{
    if (0 == c.real)
        throw DivisionByZeroException();
    else if (0 == c.imaginary)
        throw DivisionByZeroException();

    //assert(0 != c.real);
    //assert(0 != c.imaginary);

    int d = c.real*c.real + c.imaginary*c.imaginary;
    int r = (real*c.real + imaginary*c.imaginary) / d;
    int i = (imaginary*c.real - real*c.imaginary) / d; 
    real = r;
    imaginary = i;
    return *this;
}
//------------------------------------------------------------
void Complex::setReal(int real)
{
    this->real = real;
}
//------------------------------------------------------------
void Complex::setImaginary(int imaginary)
{
    this->imaginary = imaginary;
}
//------------------------------------------------------------
int Complex::getReal() const
{
    return real;
}
//------------------------------------------------------------
int Complex::getImaginary() const
{
    return imaginary;
}
//------------------------------------------------------------
const char* Complex::DivisionByZeroException::what() const throw()
{
    return "A complex number would cause a division by zero";
}
//------------------------------------------------------------
