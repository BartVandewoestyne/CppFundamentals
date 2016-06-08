#include "Complex.h"

Complex::Complex()
    : real(0)
    , imaginary(0)
{}

Complex::Complex(int real, int imaginary)
    : real(real)
    , imaginary(imaginary)
{}

Complex::Complex(const Complex& c)
    : real(c.real)
    , imaginary(c.imaginary)
{}

Complex::~Complex()
{}


Complex Complex::operator+(const Complex& c) const
{
   return Complex(real + c.real, imaginary + c.imaginary);
}

Complex& Complex::operator+=(const Complex& c)
{
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}

Complex Complex::operator-(const Complex& c) const {
   return Complex(real - c.real, imaginary + c.imaginary);
}

Complex& Complex::operator-=(const Complex& c)
{
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}

int Complex::getReal() const
{
    return real;
}

int Complex::getImaginary() const
{
    return imaginary;
}

void Complex::setReal(int real)
{
    this->real = real;
}

// TODO: report bug in slides 122 en 123
void Complex::setImaginary(int imaginary)
{
    this->imaginary = imaginary;
}

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
   out << "Complex{real=" << c.real << ", imaginary="<< c.imaginary << "}";
   return out;
}
