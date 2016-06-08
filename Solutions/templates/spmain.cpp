
#include "SmartPointer.hpp"
#include "../classes/Complex.h"

#include <iostream>
using namespace std;

int main()
{
    cout << "main: Creating new SP from raw pointer" << endl;
    SmartPointer<Complex> sp(new Complex);
    cout << "main: Creating new SP by copying another SP" << endl;
    SmartPointer<Complex> sp2(sp);
    cout << "main: Creating a null SP" << endl;
    SmartPointer<Complex> sp3;
    cout << "main: Assigning the null SP another one" << endl;
    sp3 = sp2;


    cout << "main: Creating new SP from raw pointer" << endl;
    SmartPointer<Complex> nsp(new Complex);
    cout << "main: Assigning SP from another SP" << endl;
    sp = nsp;
    cout << "main: Assigning SP from another SP" << endl;
    sp2 = nsp;
    cout << "main: Assigning LAST! SP from another SP, expect something to be deleted here" << endl;
    sp3 = nsp;

    (*sp).setReal(8);
    (*sp).setImaginary(9);

    cout << "main: Creating new SP from raw pointer" << endl;
    SmartPointer<Complex> csp(new Complex());
    csp->setReal(42);
    csp->setImaginary(44);

    cout << "main: Leaving scope, expecting lots of destructors called" << endl;
}
