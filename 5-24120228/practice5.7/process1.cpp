#include "process1.h"
#include <sstream>
void input(ll a[][MAX_N], ll& M, ll& N) {
    char line[100];
    do{
        std::cout << "Enter the number of rows and columns: ";
        fgets(line, 100, stdin);
    }while((std::stringstream(line) >> M >> N).fail() or M <= 0 or N <= 0);
    std::cout << "Enter the elements of the matrix:\n";
    for (ll i = 0; i < M; i++)
        for (ll j = 0; j < N; j++)
            std::cin >> a[i][j];
}

void rright(ll a[][MAX_N], ll &M, ll &N) {
    ll b[MAX_N][MAX_N] = {0};
    for (ll i = 0; i < N; i ++)
        for (ll j = M - 1; j >= 0; j --)
            b[i][M - 1 - j] = a[j][i];
    for(int i = 0; i < MAX_N; i ++)
        for(int j = 0; j < MAX_N; j ++)
            a[i][j] = 0;
    for (ll i = 0; i < N; i ++)
        for (ll j = 0; j < M; j ++)
            a[i][j] = b[i][j];
    std::swap(M, N);
}

void rleft(ll a[][MAX_N], ll &M, ll &N) {
    ll b[MAX_N][MAX_N] = {0};
    for (ll i = N - 1; i >= 0; i --)
        for (ll j = 0; j < M; j ++)
            b[N - 1 - i][j] = a[j][i];
    for(int i = 0; i < MAX_N; i ++)
        for(int j = 0; j < MAX_N; j ++)
            a[i][j] = 0;
    for (ll i = 0; i < N; i ++)
        for (ll j = 0; j < M; j ++)
            a[i][j] = b[i][j];
    std::swap(M, N);
}

void printmatrix(ll a[][MAX_N], ll M, ll N) {
    std::cout << "Matrix:\n";
    for (ll i = 0; i < M; i ++){
        for (ll j = 0; j < N; j ++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}