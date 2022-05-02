#include "logcon.h"

bool LogCon::NOT(bool a)
{
    if (a)
        return false;
    else
        return true;
}

bool LogCon::AND(bool a, bool b)
{
    if (a){
        if (b)
            return true;
    }
    return false;
}

bool LogCon::OR(bool a, bool b)
{
    if (a){
        return true;
    } else if (b){
        return true;
    } else{
        return false;
    }
}

bool LogCon::IMP(bool a, bool b)
{
    if (LogCon::NOT(b)){
        if (a)
            return false;
    }
    return true;
}

bool LogCon::EQU(bool a, bool b)
{
    if (LogCon::AND(a, b)){
        return true;
    } else if(LogCon::AND(LogCon::NOT(a), LogCon::NOT(b))){
        return true;
    }
    return false;
}

bool LogCon::XOR(bool a, bool b)
{
    return LogCon::NOT(LogCon::EQU(a, b));
}
