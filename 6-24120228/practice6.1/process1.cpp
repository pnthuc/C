#include "process1.h"
#include <iostream>
using namespace std;
void input(string &s){
    getline(cin, s);
}
void output(string s){
    int indxfirst = 0, indxlast = s.size() - 1;
    while(isspace(s[indxfirst]) and indxfirst + 1 < s.size())
        indxfirst ++;
    while(isspace(s[indxlast]) and indxlast - 1 >= 0)
        indxlast --;
    bool flag = false;
    for(int i = indxfirst; i <= indxlast; i ++)
        if(!isspace(s[i]))
            cout << s[i], flag = true;
        else if(isspace(s[i]))
            if(flag)
                cout << ' ', flag = false;
}