#include <iostream>
#include "process1.h"

int main() {
    ll N;
    ll matrix[MAX_N][MAX_N];
    
    input(matrix, N);

    printA(matrix, N);
    printB(matrix, N);
    printC(matrix, N);

    return 0;
}