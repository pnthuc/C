#pragma once
struct Fraction
{
    int numerator, denominator;
};
typedef struct Fraction * FractionPointer;

void input(int &N, FractionPointer &F);
void output(int N, FractionPointer &F);