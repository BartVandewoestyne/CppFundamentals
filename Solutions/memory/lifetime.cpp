#include <iostream>

using namespace std;

class Global 
{
public:
    Global() { cout << "Global::Global()" << endl; }
    ~Global() { cout << "Global::~Global()" << endl; }
};

class Local
{
public:
    Local() { cout << "Local::Local()" << endl; }
    ~Local() { cout << "Local::~Local()" << endl; }
};

class Heap
{
public:
    Heap() { cout << "Heap::Heap()" << endl; }
    ~Heap() { cout << "Heap::~Heap()" << endl; }
};


Global g;

int main()
{
    Local l;

    Heap* h = new Heap();
    delete h;
}
