#include <iostream>
#include <fstream>
#include "process1.h"
using namespace std;
int main(){
    fstream f ("MATRIX.TXT", ios::in);
    fstream o ("OUTPUT.TXT", ios::out);
    int a[MAX_N][MAX_N] = {0};
    ll M, N;
    input(f, a, M, N);
    output(o, a, M, N);
}