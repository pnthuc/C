#include <iostream>
#include "process1.h"
#include <string>
using namespace std;
int main(){
    char cur[127] = {0};
    int cnt[127] = {0};
    string s;
    input(s);
    output(s, cnt, cur);
}