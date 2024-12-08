#include <iostream>
#include "process1.h"
#include <sstream>
void input(ll matrix[][MAX_N], ll& N) { 
    char line[100];   
    do{
        std::cout << "Enter N (matrix NxN): ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> N).fail() or N <= 0);
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            std::cin >> matrix[i][j];  
}

void printA(ll matrix[][MAX_N], ll N) {
    int mainDiagonalSum = 0, antiDiagonalSum = 0;
    for (int i = 0; i < N; ++i) {
        mainDiagonalSum += matrix[i][i];
        antiDiagonalSum += matrix[i][N - i - 1];
    }
    std::cout << "Main diagonal = " << mainDiagonalSum << "\n";
    std::cout << "Anti-diagonal = " << antiDiagonalSum << "\n";
}

void printB(ll matrix[][MAX_N], ll N) {
    int maxRowSum = 0;
    for (int i = 0; i < N; ++i) {
        int rowSum = 0;
        for (int j = 0; j < N; ++j) 
            rowSum += matrix[i][j];
        if (rowSum > maxRowSum) 
            maxRowSum = rowSum;
    }
    std::cout << "Maximum row sum = " << maxRowSum << "\n";
}
void printC(ll matrix[][MAX_N], ll N) {
    int sum = 0;
    for (int i = 0; i < N; ++i) 
        sum += matrix[0][i];
    for (int i = 1; i < N; ++i) {
        int rowSum = 0;
        for (int j = 0; j < N; ++j) 
            rowSum += matrix[i][j];
        if (rowSum != sum) {
            std::cout << "It is not a magic square";
            return;
        }
    }
    for (int i = 0; i < N; ++i) {
        int colSum = 0;
        for (int j = 0; j < N; ++j) 
            colSum += matrix[j][i];
        if (colSum != sum) {
            std::cout << "It is not a magic square";
            return;
        }
    }
    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < N; ++i) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][N - i - 1];
    }
    if (primaryDiagonalSum != sum || secondaryDiagonalSum != sum) {
        std::cout << "It is not a magic square";
    } else {
        std::cout << "It is a magic square";
    }
}
