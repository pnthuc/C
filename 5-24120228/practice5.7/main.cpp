#include "process1.h"
int main(){
    ll M, N;
    ll a[MAX_N][MAX_N];

    input(a, M, N);
    rright(a, M, N);
    std::cout << "After rotating 90 degrees to the right:\n";
    printmatrix(a, M, N);
    rleft(a, M, N);
    rleft(a, M, N);
    std::cout << "After rotating 90 degrees to the left:\n";
    printmatrix(a, M, N);
}
