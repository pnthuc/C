#include <iostream>
using namespace std;
#define int long long
signed main(){
    double Celsius;
    cout << "Celsius = ";
    cin >> Celsius;
    double Fahrenheit = (Celsius * 9 / 5) + 32;
    double Kelvin = Celsius + 273;
    cout << "Fahrenheit = " << Fahrenheit << endl;
    cout << "Kelvin = " << Kelvin;
}