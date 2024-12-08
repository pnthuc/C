#include "process2_4.3.h"
#include <string>
#include <cmath>
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