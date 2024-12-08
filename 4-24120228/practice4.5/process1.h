#pragma once
using ll = long long;
struct Fraction {
    ll numerator;
    ll denominator;
};

Fraction addFractions( Fraction f1,  Fraction f2);
Fraction multiplyFractions( Fraction f1,  Fraction f2);
Fraction inverseFraction( Fraction f);
Fraction reduceFraction( Fraction f);
void printFraction( Fraction f);
void input(Fraction &f1, Fraction &f2);
