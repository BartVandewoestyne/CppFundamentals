#ifndef ReferenceCounter_H
#define ReferenceCounter_H

#ifdef PRINT_WHAT_HAPPENS
#include <iostream>
using namespace std;
#endif

class ReferenceCounter
{
protected:
    unsigned int* counter;
public:
    ReferenceCounter() : counter(new unsigned int){
        *counter = 1;
#ifdef PRINT_WHAT_HAPPENS
        cout << "ReferenceCounter default ctor; refcount is 1" << endl;
#endif
    }
    
    ReferenceCounter(const ReferenceCounter& r) :
    counter(r.counter){ 
        (*counter)++; 
#ifdef PRINT_WHAT_HAPPENS
        cout << "ReferenceCounter copy ctor; refcount goes UP and is now " << *counter << endl;
#endif
    }

    ReferenceCounter& operator=(const ReferenceCounter& r){
        if (this != &r)
        {
            (*counter)--;
#ifdef PRINT_WHAT_HAPPENS
            cout << "ReferenceCounter operator=; refcount goes DOWN and is now " << *counter << endl;
#endif
            if (*counter == 0)
            {
#ifdef PRINT_WHAT_HAPPENS
                cout << "ReferenceCounter operator=; refcount is zero, deleting " << endl;
#endif
                delete counter;
            }
        }
        counter = r.counter;
        (*counter)++;
#ifdef PRINT_WHAT_HAPPENS
        cout << "ReferenceCounter operator=; accepting new refcount; refcount goes UP and is now " << *counter << endl;
#endif
        return *this;
    }
    
    virtual ~ReferenceCounter(){ 
        (*counter)--; 
#ifdef PRINT_WHAT_HAPPENS
        cout << "ReferenceCounter dtor; refcount goes DOWN and is now " << *counter << endl;
#endif
        if (0 == *counter) 
        {
#ifdef PRINT_WHAT_HAPPENS
            cout << "ReferenceCounter operator=; refcount is zero, deleting " << endl;
#endif
            delete counter; 
        }
    }
};

#endif // ReferenceCounter_H
