#include "process1.h"
#include <iostream>
#include <sstream>
void input(ll matrix[][MAX_N], ll& rows, ll& cols) {
    char line[100];
    do{
        std::cout << "Enter the number of rows and colums: ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> rows >> cols).fail() or rows <= 0 or cols <= 0);

    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            std::cin >> matrix[i][j];

}

void output(ll matrix[][MAX_N], ll rows, ll cols) {
    ll COL[MAX_N] = {0};
    ll ROW[MAX_N] = {0};
    for(int i = 0; i < rows; ++i) 
        for(int j = 0; j < cols; ++j) 
            ROW[i] += matrix[i][j];

    for(int j = 0; j < cols; ++j)
        for(int i = 0; i < rows; ++i)
            COL[j] += matrix[i][j];
    std::cout << "Special elements in the matrix are:\n";
    bool flag = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ll sumRowAndCol = ROW[i] + COL[j] - 2 * matrix[i][j];
            if(sumRowAndCol == matrix[i][j]) {
                std::cout << "(" << i << "," << j << ") : value = " << matrix[i][j] << std::endl;
                flag = true;
            }
        }
    }
    if(!flag)
        std::cout << "No special elements in the matrix.\n";
}