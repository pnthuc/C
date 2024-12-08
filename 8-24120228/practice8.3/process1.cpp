#include <string.h>
#include <iostream>
#include "process1.h"
using namespace std;
bool check(char pre, char c){
    if(pre == '.' and c == '\n') return false;
    return true;
}
void add(char *&s, char c){
    char *temp = new char[strlen(s) + 2]();
    strcpy(temp, s);
    *(temp + strlen(s)) = c;
    s = strdup(temp);
    delete [] temp;
}
void inout(char *&s){
    for(char pre = 0, c = 0; check(pre, (c = getchar())); add(s, c), pre = c);
    cout << s ;
    delete [] s;
}
