
#include <iostream>
//#include <cassert>

using namespace std;

struct Complex
{
    int real, imaginary;
};

ostream& operator<<(ostream& s, const Complex& c)
{
    s << "Complex{real=" << c.real << ", imaginary=" << c.imaginary << "}";
    return s;
}


int main()
{
    Complex i;
    i.real = 3;
    i.imaginary = 4;

    cout << i << endl;
}
