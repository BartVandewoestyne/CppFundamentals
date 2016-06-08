#ifndef TSTRING_H
#define TSTRING_H

#include <iostream>

class TString
{
public:

    TString();
    TString(const TString& str);
    TString(const TString& str, size_t pos, size_t len /*= npos*/);
    TString(const char* s);
    TString(const char* s, size_t n);
    TString(size_t n, char c);
    ~TString();

    //TString& operator=(const TString& other);
    // Compare == !=
    // Concatenation +
 
    const char* c_str() const;
    
    int getLength() const;

private:
    int length;  // length without '\0' character
    char* data;
};

std::ostream& operator<<(std::ostream& os, const TString& s);

#endif  // TSTRING_H
