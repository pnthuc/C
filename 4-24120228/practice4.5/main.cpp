#include "process1.h"
#include <iostream>

int main(){
    Fraction f1, f2;
    input(f1, f2);

    std::cout << "Sum: ";
    Fraction add = addFractions(f1, f2);
    printFraction(add);

    std::cout << "Inverse of first fraction: ";
    Fraction inverseF1 = inverseFraction(f1);
    printFraction(inverseF1);

    std::cout << "Inverse of second fraction: ";
    Fraction inverseF2 = inverseFraction(f2);
    printFraction(inverseF2);

    std::cout << "Product: ";
    Fraction product = multiplyFractions(f1, f2);
    printFraction(product);

    std::cout << "Reduced of first fraction: ";
    Fraction reducedF1 = reduceFraction(f1);
    printFraction(reducedF1);

    std::cout << "Reduced of second fraction: ";
    Fraction reducedF2 = reduceFraction(f2);
    printFraction(reducedF2);
}