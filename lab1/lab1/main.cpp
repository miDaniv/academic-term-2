#include <iostream>

#include "logcon.h"

bool myFunction_14(bool a, bool b, bool c)
{
    return LogCon::IMP(LogCon::NOT(LogCon::AND(LogCon::IMP(a,b), LogCon::NOT(c))), LogCon::XOR(a, LogCon::NOT(c)));
}

void print(bool a, bool b, bool c)
{
    std::cout << std::boolalpha <<"a = "<< a << " b = " << b << " c = " << c << " f(a, b, c) = " << myFunction_14(a, b, c) << std::endl;
}
int main()
{
    std::cout << "FIRST PART" << std::endl;
    std::cout << "a=true; false " << std::endl << std::boolalpha <<"NOT"<< ": "<< LogCon::NOT(true) << " "<< LogCon::NOT(false) << std::endl <<std::endl;

    std::cout << "a=true;b=true" << std::endl << "a=true;b=false" << std::endl << "a=false;b=true" << std::endl << "a=false;b=false" << std::endl <<
    std::boolalpha <<"EQU"<< ": "<< LogCon::EQU(true, true) << " "<< LogCon::EQU(true, false) << " " << LogCon::EQU(false, true) << " " << LogCon::EQU(false, false) << std::endl;

    std::cout << std::boolalpha <<"OR "<< ": "<< LogCon::OR(true, true) << " "<< LogCon::OR(true, false)
              << " " << LogCon::OR(false, true) << " " << LogCon::OR(false, false) << std::endl;

    std::cout << std::boolalpha <<"AND"<< ": "<< LogCon::AND(true, true) << " "<< LogCon::AND(true, false)
              << " " << LogCon::AND(false, true) << " " << LogCon::AND(false, false) << std::endl;

    std::cout << std::boolalpha <<"IMP"<< ": "<< LogCon::IMP(true, true) << " "<< LogCon::IMP(true, false)
              << " " << LogCon::IMP(false, true) << " " << LogCon::IMP(false, false) << std::endl;

    std::cout << std::boolalpha <<"XOR"<< ": "<< LogCon::XOR(true, true) << " "<< LogCon::XOR(true, false)
              << " " << LogCon::XOR(false, true) << " " << LogCon::XOR(false, false) << std::endl;

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "SECOND PART" << std::endl;

    print(true, true, true);
    print(true, true, false);
    print(true, false, true);
    print(false, true, true);
    print(true, false, false);
    print(false, true, false);
    print(false, false, true);
    print(false, false, false);
}
