#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using ll = long long;
int main(){
    int WordCnt = 0, NumCnt = 0;
    fstream f ("INPUT.TXT", ios::in);
    char c;
    char prev = ' ';
    while(f.get(c)){
        if(isalpha(c))
            if(!isalpha(prev))
                ++ WordCnt;
        if(isdigit(c))
            if(!isdigit(prev))
                ++ NumCnt;
        prev = c;
    }
    cout << "Word count: " << WordCnt << '.' << endl;
    cout << "Number count: " << NumCnt << '.';
    f.close();
}