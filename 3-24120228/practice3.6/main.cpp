#include <iostream>
#include <cmath>
#include <sstream>
bool isValidTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

std::string classifyTriangle(double a, double b, double c) {
    if (a == b && b == c) {
        return "Equilateral triangle.";
    }
    bool isRight = (std::fabs(a * a + b * b - c * c) < 1e-9) ||
                   (std::fabs(a * a + c * c - b * b) < 1e-9) ||
                   (std::fabs(b * b + c * c - a * a) < 1e-9);
    bool isIsosceles = (a == b) || (a == c) || (b == c);
    
    if (isRight && isIsosceles)
        return "Right-isosceles triangle.";
    else if (isRight)
        return "Right triangle.";
    else if (isIsosceles)
        return "Isosceles triangle.";
    else
        return "Normal triangle.";
}

int main() {
    double a, b, c;
    char line[100];
    do{
        std::cout << "Enter 3 positive real numbers = ";
        std::fgets(line, 100, stdin);
    }while((std::stringstream(line) >> a >> b >> c).fail() || a <= 0 || b <= 0 || c <= 0);

    if (isValidTriangle(a, b, c)) {
        std::cout << "Can form a triangle." << std::endl;
        std::cout << classifyTriangle(a, b, c) ;
    } else {
        std::cout << "Cannot form a triangle!" ;
    }

    return 0;
}