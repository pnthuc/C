#include "process1_4.2.h"
#include <iostream>
void in(ll &num1, ll &num2, char &op){
    std::cout << "Enter two integers = ";
    std::cin >> num1 >> num2;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter an operator (+, -, *, /, %) = ";
    std::cin >> op;
}
std::string process(ll num1, ll num2, char op){
    switch (op) {
        case '+':
            return "Result = " + std::to_string(num1 + num2) + "\n";
            break;
        case '-':
            return "Result = " + std::to_string(num1 - num2) + "\n";
            break;
        case '*':
            return "Result = " + std::to_string(num1 * num2) + "\n";
            break;
        case '/':
            if (num2 != 0) {
                return "Result = " + std::to_string((float)num1 / num2) + "\n";
            } else {
                return "Error: divided by zero.\n";
            }
            break;
        case '%':
            if (num2 != 0) {
                return "Result = " + std::to_string(num1 % num2) + "\n";
            } else {
                return "Error: divided by zero.\n";
            }
            break;
        default:
            return "Error: invalid operator.\n";
            break;
    }
}
void output(ll num1, ll num2, char op)
{
    std::string Result = process(num1, num2, op);
    std::cout << Result;
}