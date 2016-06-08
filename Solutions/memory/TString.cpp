#include "TString.h"
#include <cstring>
//------------------------------------------------------------
TString::TString() : 
    cstring()
{}
//------------------------------------------------------------
TString::TString(const TString& s) :
    cstring(new char[s.getLength() + 1])
{
    strcpy(cstring, s.cstring);
}
//------------------------------------------------------------
TString::TString(const TString& s, size_t pos, size_t len) : 
    cstring(new char[len + 1])
{
    memcpy(cstring, &s.cstring[pos], len);
    cstring[len] = 0;
}
//------------------------------------------------------------
TString::TString(const char* s) : 
    cstring(new char[strlen(s) + 1])
{
    strcpy(cstring, s);
}
//------------------------------------------------------------
TString::TString(const char* s, size_t n) :
    cstring(new char[n + 1])
{
    memcpy(cstring, s, n);
    cstring[n] = 0;
}
//------------------------------------------------------------
TString::TString(size_t n, char c) : 
    cstring(new char[n+1])
{
    memset(cstring, c, n);
    cstring[n] = 0;
}
//------------------------------------------------------------
TString::~TString()
{
    delete[] cstring;
}
//------------------------------------------------------------
void TString::operator=(const TString& s)
{
    if (this != &s)
    {
        delete[] cstring;
        int len = s.getLength();
        cstring = new char[len+1];
        strcpy(cstring, s.cstring);
    }
}
//------------------------------------------------------------
bool TString::operator==(const TString& s) const
{
    return 0 == strcmp(cstring, s.cstring);
}
//------------------------------------------------------------
bool TString::operator!=(const TString& s) const
{
    return !operator==(s);
}
//------------------------------------------------------------
TString TString::operator+(const TString& s) const
{
    TString ret;
    ret.cstring = new char[getLength() + s.getLength() + 1];
    ret.cstring[0] = 0;
    strcat(ret.cstring, cstring);
    strcat(ret.cstring, s.cstring);
    return ret;
}
//------------------------------------------------------------
TString::operator const char*() const
{
    return cstring;
}
//------------------------------------------------------------
size_t TString::getLength() const
{
    return strlen(cstring);
}
//------------------------------------------------------------
std::ostream& operator<<(std::ostream& s, const TString& t)
{
    s << (const char*)t;
    return s;
}
//------------------------------------------------------------
