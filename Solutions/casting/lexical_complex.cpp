

#include <iostream>
#include <sstream>
#include <string>
#include "../classes/Complex.h"

#include <boost/lexical_cast.hpp>

using namespace std;

template<typename out_t, typename in_t>
out_t lexical_cast(const in_t& in)
{
    stringstream s;
    s << in;
    out_t out;
    s >> out;
    return out;
}


istream& operator>>(istream& stream, Complex& c)
{
    int real, imaginary;
    char plus, i;
    stream >> real >> plus >> imaginary >> i;
    c.setReal(real);
    c.setImaginary(imaginary);
    return stream;
}


int main()
{
    Complex c = lexical_cast<Complex>("55+66i");

    cout << c.getReal() << " " << c.getImaginary() << endl;
}
