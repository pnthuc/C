#include "process1.h"
#include "main4.1/main4.1.h"
#include "main4.2/main4.2.h"
#include "main4.3/main4.3.h"
#include <iostream>
void input(ll &N){
    std::cout << "1. Practice 4.1. \n";
    std::cout << "2. Practice 4.2. \n";
    std::cout << "3. Practice 4.3. \n";
    std::cout << "4. Exit. \n";
    std::cout << "Selection (1-4): ";
    std::cin >> N;
}
bool solve(ll N){
    switch(N){
        case 1:
            return main4_1(), 1;
        case 2:
            return main4_2(), 1;
        case 3:
            return main4_3(), 1;
        case 4:
            return 0;
        default:
            return 0;
    }
}