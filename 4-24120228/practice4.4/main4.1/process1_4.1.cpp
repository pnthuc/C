#include "process1_4.1.h"
#include "process2_4.1.h"
void in(ll &N){
    char line[100];
    std::cin.ignore(1000, '\n');
    do{
        std::cout << "Enter a positive integer N = ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> N).fail() || N <= 0);
}
std::vector <ll> FindPrimes(ll N){
    std::vector <ll> allPrimes;
    for (ll i = 2; i <= N; i ++) 
        if(isPrime(i)) 
            allPrimes.push_back(i);
    return allPrimes;
}
void output(ll N){
    std::vector<ll> allPrimes;
    allPrimes = FindPrimes(N);
    ll countPrime = 0;
    for (int i = 0; i < allPrimes.size(); i ++)
        std::cout << "#" << ++ countPrime << " = " << allPrimes[i] << std::endl;
    std::cout << "There are " << countPrime << " prime numbers.\n";
}