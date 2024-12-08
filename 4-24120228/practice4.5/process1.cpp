#include <iostream>
#include <algorithm>
#include "process1.h"

using namespace std;

Fraction reduceFraction(Fraction f) {
    ll gcd = __gcd(f.numerator, f.denominator);
    f.numerator /= gcd;
    f.denominator /= gcd;
    return f;
}

Fraction addFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result = reduceFraction(result);
    return result;
}

Fraction multiplyFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    result = reduceFraction(result);
    return result;
}

Fraction inverseFraction(Fraction f) {
    Fraction result;
    result.numerator = f.denominator;
    result.denominator = f.numerator;
    return result;
}

void printFraction(Fraction f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

void input(Fraction &f1, Fraction &f2) {
    cout << "Enter first fraction (numerator and denominator): ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Enter second fraction (numerator and denominator): ";
    cin >> f2.numerator >> f2.denominator;
}