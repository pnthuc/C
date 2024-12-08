#include <iostream>
#include <vector>
#include <sstream>
#define int long long
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

signed main() {
    int N;
    char line[100];
    do{
        std::cout << "Enter a positive integer N = ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> N).fail() || N <= 0);
    int countPrime = 0;
    for (int i = 2; i <= N; i ++) {
        if(isPrime(i)) {
            std::cout << "#" << ++ countPrime << " = " << i << std::endl;
        }
    }
    std::cout << "There are " << countPrime << " prime numbers.";

    return 0;
}