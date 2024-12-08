#include <iostream>
#include <math.h>
using namespace std;
#define int long long
double pow6(double x){
    return x * x * x * x * x * x;
}
signed main(){
    cout << "Enter p, q = ";
    double p, q;
    cin >> p >> q;
    double x = cbrt(sqrt(pow6(p) / 27 + q * q / 4) - q / 2) - cbrt(sqrt(pow6(p) / 27 + q * q / 4) + q / 2);
    cout << "Solution = " << x;
}