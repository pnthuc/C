#include "process1.h"
#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i * i <= n; i ++)
        if(n % i == 0)
            return false;
    return true;
}
void inAndOut(fstream &f, fstream &o, int &N){
    while(true){
        if((f >> N).fail())
            continue;
        if(isPrime(N))
            o << N << ' ';   
    }
    f.close();
}
