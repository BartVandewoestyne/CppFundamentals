
#include "cout.h"
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace tass;
//------------------------------------------------------------
ostream tass::cout;
tass_endl tass::endl;
//------------------------------------------------------------
ostream::ostream() : 
    time4Timestamp(true)
{
}
//------------------------------------------------------------
ostream& ostream::operator<<(const char* p)
{
    maybeAddTimeStamp();
    std::cout << p;
    return *this;
}
//------------------------------------------------------------
ostream& ostream::operator<<(int i)
{
    maybeAddTimeStamp();
    std::cout << i;
    return *this;
}
//------------------------------------------------------------
ostream& ostream::operator<<(const tass_endl& e)
{
    std::cout << std::endl;
    time4Timestamp = true;
    return *this;
}
//------------------------------------------------------------
void ostream::maybeAddTimeStamp()
{
    if (time4Timestamp)
    {
        std::time_t now = system_clock::to_time_t(system_clock::now());
        std::tm* local = localtime(&now);
        std::cout << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << " : ";

        time4Timestamp = false;
    }
}
//------------------------------------------------------------
