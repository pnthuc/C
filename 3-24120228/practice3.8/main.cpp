#include <iostream>
#include <limits.h>
#include <sstream>
int main() {
    int number;
    int max = INT_MIN;
    int min = INT_MAX;
    char line[100];
    int count = 0;
    while (true) {
        count ++;
        do{
            std::cout << "Number " << count << " = ";
            fgets(line, 100, stdin);
        }while((std::stringstream(line) >> number).fail() || number < 0);
        if (number == 0) 
            break;
        if (number > max) 
            max = number;
        if (number < min) 
            min = number;
    }

    if (max == INT_MIN || min == INT_MAX) {
        std::cout << "No valid positive integers were entered." ;
    } else {
        std::cout << "Max = " << max << std::endl;
        std::cout << "Min = " << min ;
    }

    return 0;
}