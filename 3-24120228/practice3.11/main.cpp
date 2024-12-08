#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void printBits(int N, int M) {
    std::cout << "The first " << M << " bit from the right of " << N << ": ";
    std::string s;
    s.clear();
    for (int i = 0; i < M; ++i) {
        s.push_back(char(N % 2 + '0'));
        N /= 2;
    }
    reverse(s.begin(), s.end());
    std::cout << s;
}

int main() {
    int N, M;
    std::cout << "Enter N, M = ";
    std::cin >> N >> M;
    printBits(N, M);
    return 0;
}