#include "process1.h"
#include <iostream>
using ll = long long;
using namespace std;
void input(fstream &f, int a[][MAX_N], ll &M, ll &N){
    f >> M >> N;
    for (ll i = 0; i < M; i ++)
        for (ll j = 0; j < N; j ++)
            f >> a[i][j];
    f.close();
}
void rleft(int a[][MAX_N], ll &M, ll &N) {
    int b[MAX_N][MAX_N] = {0};
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
void output(fstream &o, int a[][MAX_N], ll M, ll N){
    rleft(a, M, N);
    o << M << " " << N << endl;
    for (ll i = 0; i < M; i ++){
        for (ll j = 0; j < N; j ++)
            o << a[i][j] << " ";
        o << endl;
    }
    o.close();
}