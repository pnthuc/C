#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
bool isDescending(int n) {
    std::string str = std::to_string(n);
    for (size_t i = 1; i < str.size(); ++i)
        if (str[i] > str[i - 1])
            return false;
    return true;
}

bool isSymmetric(int n) {
    std::string str = std::to_string(n);
    std::string rev_str = str;
    std::reverse(rev_str.begin(), rev_str.end());
    return str == rev_str;
}

int main() {
    int N;
    char line[100];
    do {
        std::cout << "Enter N = ";
        std::cin.getline(line, 100);
    } while ((std::stringstream(line) >> N).fail() || N < 0);

    if (isSymmetric(N))
        std::cout << "Symmetric." << std::endl;
    else 
        std::cout << "Not symmetric." << std::endl;

    return 0;
}