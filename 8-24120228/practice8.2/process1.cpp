#include <iostream>
#include <string.h>
#include "process1.h"
using namespace std;
void input(char *&s){
    char line[1000];
    cout << "Enter a sentence = ";
    cin.getline(line, 1000);
    s = new char[strlen(line) + 1]();
    strcpy(s, line);
}
void add(char *&ans, const char *dest){
    char *temp = new char[strlen(ans) + strlen(dest) + 1]();
    strcpy(temp, ans);
    strcpy(temp + strlen(ans), dest);
    ans = strdup(temp);
}
void output(char *s) {
    char *pre = s;
    char *p = s;
    for(;(p = strpbrk(p, "-.0123456789")); pre = p){
        cout << strncpy(new char[p - pre + 1](), pre, p - pre);
        cout << strtod(p, &p) + 1;
    }
    cout << pre;
    delete [] pre, p;
}