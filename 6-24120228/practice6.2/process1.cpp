#include "process1.h"
#include <iostream>
using namespace std;
void input(string &s){
    cout << "S = ";
    getline(cin, s);
}
void output(string s, int cnt[127], char cur[127]){
    for(char c : s)
        cnt[c] ++;
    for(char c = ' ' + 1; c <= '~'; c ++)
        cur[c] = c;
    for(char i = ' ' + 1; i <= '~'; i ++)
        for(char j = ' ' + 1; j < i; j ++)
            if(cnt[cur[i]] > cnt[cur[j]])
                swap(cur[i], cur[j]);
            else if(cnt[cur[i]] == cnt[cur[j]] and cur[i] < cur[j])
                swap(cur[i], cur[j]);
    int precnt = 0;
    bool leading = false;
    for(char c = ' ' + 1; c <= '~'; c ++) if(cnt[cur[c]]){
        if(precnt != cnt[cur[c]]){
            if(!leading)
                leading = true;
            else
                cout << endl;
            cout << cnt[cur[c]] << ":";
        }
        cout << ' ' << cur[c];
        precnt = cnt[cur[c]];
    }
}