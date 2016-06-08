#ifndef Complex_H
#define Complex_H

class Complex
{
    friend class ComplexTests;
public:
    Complex();
    Complex(int real, int imaginary);
    Complex(const Complex& c);

    Complex& operator=(const Complex& c);

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);


    int getReal() const;
    int getImaginary() const;
    void setReal(int real);
    void setImaginary(int imaginary);

private:
    int real;
    int imaginary;
};

#endif // Complex_H
