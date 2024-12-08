#include "process1.h"
#include <iostream>
#include <sstream>
void input(ll &N, ll a[]){
    char line[100];
    do{
        std::cout << "Enter N = ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> N).fail() or N <= 0);
    for(ll i = 0; i < N; i++){
        do{
            std::cout << "Element " << i << " = ";
            fgets(line, 100, stdin);
        }while((std::stringstream(line) >> a[i]).fail());
    }
}
void output(ll N, ll a[]){
    bool isAscending = true, isSymmetric = true, isArithmetic = true;
    ll diff = a[1] - a[0];

    for (ll i = 0; i < N - 1; i++) {
        isAscending = a[i] < a[i + 1];
        isSymmetric = a[i] == a[N - i - 1];
        if (i > 0 && a[i + 1] - a[i] != diff) isArithmetic = false;
    }

    std::cout << "Array " << (isAscending ? "is" : "is not") << " ascending." << std::endl;
    std::cout << "Array " << (isSymmetric ? "is" : "is not") << " symmetric." << std::endl;
    std::cout << "Array " << (isArithmetic ? "is" : "is not") << " an arithmetic progression." << std::endl;
}