#include <iostream>

using namespace std;

class Foo
{
public:
    void printSomething() {
        cout << "Foo::printSomething" << endl;
    }
};

typedef void (Foo::*FooprintFunc)();

int main()
{
    //FooprintFunc fp = &Foo::printSomething;
    void (Foo::*fp)() = &Foo::printSomething;

    Foo f;
    (f.*fp)();
}

