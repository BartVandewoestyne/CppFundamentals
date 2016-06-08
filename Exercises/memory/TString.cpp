// length member variable gebruiken zorgt er voor dat je
// een aantal strlen kan vermijden.
// Belangrijk: in assignment operator, do a self-assignment check.
// Remark for operator=
//   getLength, new and strcpy should not throw exceptions.
//   if getLength throws an error, i deleted my buffer, and I can never get it back
// operator== een int laten teruggeven???
// solution version of getLength() is slower, because it always runs strlen function instead of caching the length value
// operator<< uses c-style cast, not that good. / could've also made a friend

#include "TString.h"

#include <cstring>
#include <cstddef>
#include <iostream>

TString::TString()
    : length(0)
    , data(NULL)
{
  data = new char;
  *data = '\0';
}

TString::TString(const TString& str)
    : length(str.getLength())
{
    // BUG: overwriting uninitialized memory!!!
    data = new char;
    std::strcpy(data, str.c_str());
}

TString::TString(const TString& str, size_t pos, size_t len /*= npos*/)
{
    data = new char;
    const char* other = str.c_str();
    std::strncpy(data, other+pos, len);
    length = std::strlen(data);
}

TString::TString(const char* s)
    : length(std::strlen(s))
{
    data = new char;
    std::strcpy(data, s);
}

TString& TString::operator=(const TString& other)
{

    //if (this != other)
    //{
        length = other.getLength();
        data = strcpy(data, other.c_str());
    //}
    return *this;
}

const char* TString::c_str() const
{
    return data;
}

TString::TString(const char* s, size_t n)
    : length(n)
{
    data = new char;
    std::strncpy(data, s, n);
}

TString::TString(size_t n, char c)
    : length(n)
{
    data = new char[n+1];
    for (int i = 0; i < n; ++i)
    {
        data[i] = c;
    }
    data[n] = '\0';
}

TString::~TString()
{
    delete[] data;
}

TString::getLength() const
{
    return length;
}

std::ostream& operator<<(std::ostream& os, const TString& s)
{
    os << s.c_str() << " (length " << s.getLength() << ")";
    return os;
}
