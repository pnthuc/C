#include "process1.h"
#include <iostream>
#include <sstream>
using namespace std;
void input(ll &N, ll a[]){
    char line[100];
    do {
        std::cout << "Enter N = ";
        fgets(line, 100, stdin);
    } while ((std::stringstream(line) >> N).fail() or N <= 0);
    for(ll i = 0; i < N; i++){
        do{
            std::cout << "Element " << i << " = ";
            fgets(line, 100, stdin);
        }while((std::stringstream(line) >> a[i]).fail());
    }
}
bool isPrime(ll n) {
    if(n < 2) 
        return false;
    
    for(ll i = 2; i * i <= n; i++) 
        if(n % i == 0) 
            return false;

    return true;
}
void output(ll N, ll a[]){
    ll negativeCount = 0;
    ll primeCount = 0;

    for(ll i = 0; i < N; i++) {
        if(a[i] < 0) 
            negativeCount++;
        if(isPrime(a[i])) 
            primeCount++;
    }
    cout << endl;
    cout << "Negative numbers : " << negativeCount << "." << endl;
    cout << "Prime numbers : " << primeCount << "." << endl;
}