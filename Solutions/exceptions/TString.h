#ifndef TString_H
#define TString_H

#include <ostream>
#include <cstddef>

#include <exception>

class TString
{
public:
    TString();
    TString(const TString& s);
    TString(const TString& s, size_t pos, size_t len);
    TString(const char* s);
    TString(const char* s, size_t n);
    TString(size_t n, char c);
    ~TString();

    void operator=(const TString& s);

    bool operator==(const TString& s) const;
    bool operator!=(const TString& s) const;

    TString operator+(const TString& s) const;
    
    operator const char*() const;

    size_t getLength() const;

    class NullPointerException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    char* cstring;
};


std::ostream& operator<<(std::ostream& s, const TString& t);

#endif // TString_H
