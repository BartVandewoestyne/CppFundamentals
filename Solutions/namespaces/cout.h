#ifndef cout_H
#define cout_H

namespace tass 
{

    class tass_endl{};
    extern tass_endl endl;

    class ostream 
    {
        bool time4Timestamp;
        void maybeAddTimeStamp();

    public:
        ostream();
        ostream& operator<<(const char* p);
        ostream& operator<<(int i);
        ostream& operator<<(const tass_endl& e);
    };

    extern ostream cout;
}
        

#endif //cout_H
