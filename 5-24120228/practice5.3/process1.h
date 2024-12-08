#pragma once
#include <string>
#include <iostream>
using ll = long long;

const ll MAX_N = 100;

struct Student {
    std::string id;
    std::string name;
    float math;
    float literature;
    float gpa;
    void calculateGPA() {
        gpa = (math * 3 + literature * 2) / 5;
    }
};

void input(Student student[], ll &N);
void output(Student student[], ll N);
