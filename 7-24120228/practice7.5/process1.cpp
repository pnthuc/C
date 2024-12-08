#include "process1.h"
#include <iostream>
#include <sstream>
using namespace std;

void input(int &N, FractionPointer &F){
    cout << "Number of fractions = ";
    cin >> N;
    F = new Fraction[N];
    for (int i = 0; i < N; i ++){
        char slash;
        do{
            cout << "Fraction " << i << " = ";
            cin >> (F + i)->numerator >> slash >> (F + i)->denominator;
            if((F + i)->denominator == 0)
                cout << "Error: denominator must not zero. " << endl;
        }while((F + i)->denominator == 0);
    }
}
bool compare(Fraction a, Fraction b){
    return a.numerator * b.denominator == a.denominator * b.numerator;
}
void del(int index, int &N, FractionPointer &F){
    for (int i = index; i < N - 1; i ++)
        *(F + i) = *(F + i + 1);
    F = (Fraction *)realloc(F, --N * sizeof(Fraction));
}
void output(int N, FractionPointer &F){
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < i; j ++)
            if(compare(*(F + i), *(F + j)))
                del(i--, N, F);
    for (int i = 0; i < N; i ++)
        cout << (F + i)->numerator << "/" << (F + i)->denominator << " ";
    delete [] F;
}