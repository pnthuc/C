#pragma once
#include <string>
#include <algorithm>

using ll = long long;

const ll MAX_N = 100;

struct Date {
    ll day;
    ll month;
    ll year;
};

void input(Date dates[], ll &N);
void output(Date dates[], ll N);