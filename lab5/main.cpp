#include "converter.h"

int main()
{
    string exp("((10.1+value)*((100+0.01)^value2))");

    while (true) {
        cout << "Current exp: " << exp << endl;
        cout << "Input: " << endl
             << "ipost - infix to postfix" << endl
             << "ipre - infix to prefix" << endl
             << "posti - postfix to infix" << endl
             << "prei - prefix to infix" << endl
             << "exp - new mathematical expression" << endl
             << "e - exit" << endl;
        std::string key;
        getline(cin, key);
        if (key == "e")
            break;
        else if (key == "ipost")
            exp = infixToPostfix(exp);
        else if (key == "ipre")
            exp = infixToPrefix(exp);
        else if (key == "posti")
            exp = postfixToInfix(exp);
        else if (key == "prei")
            exp = prefixToInfix(exp);
        else if (key == "exp")
            getline(cin, exp);
    }
}
