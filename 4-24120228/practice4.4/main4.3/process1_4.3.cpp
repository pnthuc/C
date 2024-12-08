#include <sstream>
#include <iostream>
#include "process1_4.3.h"
#include "process2_4.3.h"
void in(double &a, double &b, double &c){
    std::cin.ignore(1000, '\n');
    char line[100];
    do{
        std::cout << "Enter 3 positive real numbers = ";
        std::fgets(line, 100, stdin);
    }while((std::stringstream(line) >> a >> b >> c).fail() || a <= 0 || b <= 0 || c <= 0);
}
void out(double a, double b, double c){
    if (isValidTriangle(a, b, c)) {
        std::cout << "Can form a triangle." << std::endl;
        std::cout << classifyTriangle(a, b, c) << std::endl;
    } else {
        std::cout << "Cannot form a triangle!" << std::endl;
    }
}