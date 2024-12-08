#include <iostream>
#include <fstream>
#include "process1.h"
using namespace std;
int main(){
    fstream f ("NUMBER.TXT", ios::in);
    fstream o ("PRIME.TXT", ios::out);
    int n;
    inAndOut(f, o, n);
}