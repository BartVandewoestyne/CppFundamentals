#ifndef SmartPointer_H
#define SmartPointer_H

#include "ReferenceCounter.hpp"

#ifdef PRINT_WHAT_HAPPENS
#include <iostream>
using namespace std;
#endif


template<class T>
class SmartPointer : protected ReferenceCounter
{
    friend class SmartPointerTests; // 4 testing ...

public:
    SmartPointer();
    SmartPointer(T* pointee);

    // Experiment, apparently both forms work
    //SmartPointer(const SmartPointer<T>& sp);
    SmartPointer(const SmartPointer& sp);
    virtual ~SmartPointer();

    // Experiment, see copy ctor
    SmartPointer& operator=(const SmartPointer& sp);
//    SmartPointer<T>& operator=(const SmartPointer<T>& sp);

    T& operator*() const;
    T* operator->() const;

    template <class S>
    friend bool operator==(SmartPointer<S> const& lhs, SmartPointer<S> const& rhs);

    template <class S>
    friend bool operator==(const S* lhs, SmartPointer<S> const& rhs);

    template <class S>
    friend bool operator==(SmartPointer<S> const& lhs, const S* rhs);

    template <class S, class U>
    friend bool operator==(U* lhs, SmartPointer<S> const& rhs);

    template <class S, class U>
    friend bool operator==(SmartPointer<S> const& lhs, U* rhs);

    
protected:
    T* pointee;
};

//------------------------------------------------------------
template<class T>
SmartPointer<T>::SmartPointer() :
    ReferenceCounter(),
    pointee()
{
#ifdef PRINT_WHAT_HAPPENS
    cout << "SmartPointer<T> default ctor; I'm null" << endl;
#endif
}
//------------------------------------------------------------
template<class T>
SmartPointer<T>::SmartPointer(T* pointee) :
    ReferenceCounter(),
    pointee(pointee)
{
#ifdef PRINT_WHAT_HAPPENS
    cout << "SmartPointer<T> T* ctor;" << endl;
#endif
}
//------------------------------------------------------------
template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& sp) :
    ReferenceCounter(sp),
    pointee(sp.pointee)
{
#ifdef PRINT_WHAT_HAPPENS
    cout << "SmartPointer<T> copy ctor;" << endl;
#endif
}
//------------------------------------------------------------
template<class T>
SmartPointer<T>::~SmartPointer()
{
#ifdef PRINT_WHAT_HAPPENS
    cout << "SmartPointer<T> dtor;" << endl;
#endif
    if (*counter == 1)
    {
#ifdef PRINT_WHAT_HAPPENS
    cout << "SmartPointer<T> dtor; i'm the last one standing; deleting pointee" << endl;
#endif
        delete pointee;
    }
}
//------------------------------------------------------------
template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& sp)
{
    if (this != &sp)
    {
#ifdef PRINT_WHAT_HAPPENS
        cout << "SmartPointer<T> operator=;" << endl;
#endif
        if (*counter == 1)
        {
#ifdef PRINT_WHAT_HAPPENS
            cout << "SmartPointer<T> operator=; i'm the last one standing; deleting pointee" << endl;
#endif
            delete pointee;
        }
#ifdef PRINT_WHAT_HAPPENS
            cout << "SmartPointer<T> operator=; accepting new pointee & calling ReferenceCounter::operator=" << endl;
#endif
        pointee = sp.pointee;
        ReferenceCounter::operator=(sp);
    }
    return *this;
}
//------------------------------------------------------------
template<class T>
T& SmartPointer<T>::operator*() const
{
    return *pointee;
}
//------------------------------------------------------------
template<class T>
T* SmartPointer<T>::operator->() const
{
    return pointee;
}
//------------------------------------------------------------
template<class T>
bool operator==(SmartPointer<T> const& lhs, SmartPointer<T> const& rhs)
{
    return lhs.pointee == rhs.pointee;
}
//------------------------------------------------------------
template <class S>
bool operator==(const S* lhs, SmartPointer<S> const& rhs)
{
    return lhs == rhs.pointee;
}
//------------------------------------------------------------
template <class S>
bool operator==(SmartPointer<S> const& lhs, const S* rhs)
{
    return lhs.pointee == rhs;
}
//------------------------------------------------------------

#endif // SmartPointer_H
