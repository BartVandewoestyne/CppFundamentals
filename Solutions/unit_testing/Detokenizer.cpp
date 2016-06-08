#include "Detokenizer.hpp"

#include <cstring>
using namespace std;

//------------------------------------------------------------
Detokenizer::Detokenizer(const std::string& string, const std::string& delimiters) : 
    originalString(string),
    delimiters(delimiters),
    current(new char[string.length()]),
    startFromBeginning(true)
{
    strcpy(current.get(), originalString.c_str());
}
//------------------------------------------------------------
std::string Detokenizer::nextToken()
{
    if (startFromBeginning)
    {
        startFromBeginning = false;
        return strtok(current.get(), delimiters.c_str());
    }
    else
        return strtok(0, delimiters.c_str());
}
//------------------------------------------------------------
void Detokenizer::reset()
{
    startFromBeginning = true;
    strcpy(current.get(), originalString.c_str());
}
//------------------------------------------------------------
