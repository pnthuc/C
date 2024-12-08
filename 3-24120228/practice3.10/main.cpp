#include <iostream>
#include <sstream>
#define int long long
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

signed main() {
    int a, b;
    char line[100];
    do {
        std::cout << "Enter 2 positive integers = ";
        fgets(line, 100, stdin);
    } while ((std::stringstream(line) >> a >> b).fail() || a <= 0 || b <= 0);

    int gcd_result = gcd(a, b);
    int lcm_result = lcm(a, b);

    std::cout << "GCD = " << gcd_result << std::endl;
    std::cout << "LCM = " << lcm_result ;

    return 0;
}
