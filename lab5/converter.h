#ifndef CONVERTER_H
#define CONVERTER_H

#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isOperator(string character);

string infixToPostfix(const string infix);
string infixToPrefix(string infix);

string postfixToInfix(const string postfix);
string prefixToInfix(string prefix);

vector<string> parseString(string input);

#endif // CONVERTER_H
