#include <iostream>

using namespace std;

const int thisyear = 2013;

int main()
{
    int age = 0;
    cout << "Enter age: ";
    cin >> age;
    cout << "You were born in " << thisyear - age << endl;
}
