#include <iostream>
#include <cmath>

using namespace std;
long long factorial(int N) {
    unsigned long long result = 1;
    for (int i = 1; i <= N; ++i) {
        result *= i;
    }
    return result;
}

double computeLn2(int N) {
    double result = 0.0;
    for (int i = 1; i <= N; ++i)
        result += pow(-1, i + 1) / i;
    return result;
}

double computePI(int N) {
    double result = 0.0;
    for (int i = 0; i <= N; ++i) 
        result += pow(-1, i) / (2 * i + 1);
    return result * 4;
}

int computeSumOfSquares(int N) {
    int result = 0;
    for (int i = 1; i * i <= N; ++i) 
        result += i * i;
    return result;
}

int main() {
    int N;
    cout << "Enter a positive integer N = ";
    cin >> N;

    long long fact = factorial(N);
    double ln2 = computeLn2(N);
    double pi = computePI(N);
    int sumOfSquares = computeSumOfSquares(N);

    cout << "N! = " << fact << endl;
    cout << "ln(2) = " << ln2 << endl;
    cout << "PI = " << pi << endl;
    cout << "S = " << sumOfSquares << endl;

    return 0;
}
