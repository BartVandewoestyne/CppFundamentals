#ifndef Detokenizer_H
#define Detokenizer_H

#include <string>
#include <boost/shared_array.hpp>

class DetokenizerTests;

/**
 * @brief Wrapper around C's strtok
 *
 * Not a particluar memory friendly implementation
 * Should detokenize in Ctor and cache results in vector,
 * typedef vector iterator
 * But we don't know about vector or iterators yet
 *
 * Also strtok doesn't let itself be wrapped nicely, as it has state ...
 * But this makes for a nice TDD assignment as each new test 
 */
class Detokenizer
{
    friend class DetokenizerTests;

    /** Keep a copy, for reset, strtok permutates the string */
    std::string originalString;
    std::string delimiters;

    /** Not doing my own housekeeping ... */
    boost::shared_array<char> current;

    bool startFromBeginning;

    Detokenizer(const Detokenizer& d);
    Detokenizer& operator=(const Detokenizer& d);

public:
    Detokenizer(const std::string& string, const std::string& delimiters);
    //~Detokenizer();

    std::string nextToken();
    void reset();    
};

#endif // Detokenizer_H
