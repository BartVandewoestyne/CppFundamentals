#include <iostream>

struct Complex
{
    Complex() : real(0), imag(0) {}
    Complex(int real, int imag) : real(real), imag(imag) {}

    // TODO: member or non-member function?
    Complex operator+(Complex& other);

    int real;
    int imag;
};

Complex Complex::operator+(Complex& other) {
   return Complex(real + other.real, imag + other.imag);
}

std::ostream& operator<<(std::ostream& stream, const Complex& c)
{
   return stream << "Complex{real=" << c.real << ", imaginary="<< c.imag << "}";
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex thesum = c1 + c2;
    std::cout << thesum << std::endl;
}
