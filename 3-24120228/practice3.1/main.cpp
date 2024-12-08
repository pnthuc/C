#include <iostream>
#define int long long
signed main() {
    int num1, num2;
    char op;

    std::cout << "Enter two integers = ";
    std::cin >> num1 >> num2;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter an operator (+, -, *, /, %) = ";
    std::cin >> op;

    switch (op) {
        case '+':
            std::cout << "Result = " << num1 + num2 ;
            break;
        case '-':
            std::cout << "Result = " << num1 - num2 ;
            break;
        case '*':
            std::cout << "Result = " << num1 * num2 ;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result = " << double(num1) / num2 ;
            } else {
                std::cout << "Error: divided by zero.";
            }
            break;
        case '%':
            if (num2 != 0) {
                std::cout << "Result = " << num1 % num2 ;
            } else {
                std::cout << "Error: divided by zero." ;
            }
            break;
    }

    return 0;
}