#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{

public:
    Complex();
    Complex(int real, int imaginary);
    Complex(const Complex& c);
    ~Complex();

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    friend std::ostream& operator<<(std::ostream& out, const Complex& c);

    int getReal() const;
    int getImaginary() const;
    void setReal(int real);
    void setImaginary(int imaginary);

private:
    int real;
    int imaginary;
};

std::ostream& operator<<(std::ostream& stream, const Complex& c);

#endif  // COMPLEX_H
