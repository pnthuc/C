#include <iostream>
using namespace std;
#define int long long
signed main(){
    cout << "Exchange money = ";
    int money;
    cin >> money;
    int note20000, note10000, note5000, note1000;
    note20000 = note10000 = note5000 = note1000 = 0;
    note20000 = money / 20000;
    money %= 20000;
    note10000 = money / 10000;
    money %= 10000;
    note5000 = money / 5000;
    money %= 5000;
    note1000 = money / 1000;
    money %= 1000;
    cout << "Note 20000: " << note20000 << endl;
    cout << "Note 10000: " << note10000 << endl;
    cout << "Note 5000: " << note5000 << endl;
    cout << "Note 1000: " << note1000 << endl;
    cout << "Remain money = " << money;
}