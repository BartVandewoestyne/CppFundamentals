#include <iostream>
#include <string>

class Foo
{
public:

    Foo(int id)
        : id(id)
    {
        std::cout << "Foo(" << id << ")" << std::endl;
    }

    ~Foo()
    {
        std::cout << "~Foo(" << id << ")" << std::endl;
    }

private:
    int id;
};


Foo f(0);

int main()
{
    std::cout << "just entered main()" << std::endl;

    Foo f(1);

    Foo* pf = new Foo(2);
    delete pf;

    std::cout << "right before leaving main()" << std::endl;
}
