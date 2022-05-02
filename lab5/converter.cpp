#include "converter.h"

bool isOperator(string character) {
    return character == "-" || character == "+" || character == "*" || character == "/" || character == "^";
}

string infixToPostfix(const string infix) {
    stack<string> operatorsStack;
    string result;

    for (const string &value : parseString(infix)) {
        if (isOperator(value))
            operatorsStack.push(value);
        else if (value == ")") {
            result += ((operatorsStack.top()) + ' ');
            operatorsStack.pop();
        } else if (value != "(") {
            result += (value + ' ');
        }
    }
    return result;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string result = infixToPostfix(infix);
    reverse(result.begin(), result.end());

    return result;
}

string postfixToInfix(const string postfix) {
    stack<string> stringStack;

    for (const string &value : parseString(postfix)) {
        if (isOperator(value)) {
            string second = stringStack.top();
            stringStack.pop();
            string first = stringStack.top();
            stringStack.pop();
            string result = "(" + first + value + second + ")";
            stringStack.push(result);
        } else if (value != ")" && value != "(")
            stringStack.push(value);
    }
    return stringStack.top();
}

string prefixToInfix(string prefix) {
    reverse(prefix.begin(), prefix.end());
    stack<string> stringStack;

    for (const string &value : parseString(prefix)) {
        if (isOperator(value)) {
            string first = stringStack.top();
            stringStack.pop();
            string second = stringStack.top();
            stringStack.pop();
            string result = "(" + first + value + second + ")";
            stringStack.push(result);
        } else if (value != ")" && value != "(")
            stringStack.push(value);
    }
    return stringStack.top();
}

vector<string> parseString(string input)
{
    int startIndex = -1;
    int endIndex = -1;
    vector<string> result;
    for (int i = 0; i < input.size(); ++i) {
        char character = input.at(i);
        if (isOperator({character}) || character == ')' || character == '(' || character == ' ') {
            if (startIndex != -1)
                result.push_back(input.substr(startIndex, endIndex - startIndex + 1));
            if (character != ' ')
                result.push_back({character});
            startIndex = -1;
            endIndex = -1;
        } else {
            if (startIndex == -1) startIndex = i;
            endIndex = i;
        }
    }
    return result;
}
