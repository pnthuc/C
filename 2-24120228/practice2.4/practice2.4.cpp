#include<iostream>
using namespace std;
#define int long long
signed main(){
    int h1, m1, s1, h2, m2, s2;
    cout << "T1 (h m s) = ";
    cin >> h1 >> m1 >> s1;
    cout << "T2 (h m s) = ";
    cin >> h2 >> m2 >> s2;
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    int Distance = t2 - t1;
    cout << "Distance = " << Distance;
}