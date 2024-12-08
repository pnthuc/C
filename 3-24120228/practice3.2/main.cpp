#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "Enter coefficients a, b, c = ";
    std::cin >> a >> b >> c;
    std::cin.ignore(1000, '\n');
    if (a == 0) {
        if (b == 0)
            return std::cout << "No solution!", 0;
        std::cout << "Solution 1 = " << -c / b;
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root2 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root1 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Solution 1 = " << root1 << std::endl;
        std::cout << "Solution 2 = " << root2 ;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "Solution 1 = " << root ;
    } else {
        std::cout << "No solution!" ;
    }

    return 0;
}