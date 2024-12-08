#include <iostream>
#include "process1.h"
#include <sstream>
using namespace std;

void input(Student student[], ll &N) {
    char line[100];
    do{
        cout << "Enter N = ";
        fgets(line, 100, stdin);
    }while((stringstream(line) >> N).fail() or N <= 0);
    for (ll i = 0; i < N; i++) {
        do
            cout << "Student " << i << " ID = ", getline(cin, student[i].id);
        while(student[i].id.empty());
        do
            cout << "Student " << i << " Name = ", getline(cin, student[i].name);
        while(student[i].name.empty());
        do{
            cout << "Student " << i << " Math = ";
            fgets(line, 100, stdin);
        }while((stringstream(line) >> student[i].math).fail() or student[i].math < 0 or student[i].math > 10);
        do{
            cout << "Student " << i << " Literature = ";
            fgets(line, 100, stdin);
        }while((stringstream(line) >> student[i].literature).fail() or student[i].literature < 0 or student[i].literature > 10);
        student[i].calculateGPA();
    }
}

void output(Student student[], ll N) {
    ll ExcellentStudent[MAX_N];
    cout << "Excellent students: " << endl;
    ll count = 0;
    for (ll i = 0; i < N; i++) 
        if (student[i].gpa >= 8.5) 
            ExcellentStudent[count ++] = i;
    for(ll i = 0; i < count; i ++)
        for(ll j = 0; j < i ; j ++)
            if(student[ExcellentStudent[i]].gpa > student[ExcellentStudent[j]].gpa)
                swap(ExcellentStudent[i], ExcellentStudent[j]);
    for (ll i = 0; i < count; i++) 
        cout << "Student " << ExcellentStudent[i] << ": Name = " << student[ExcellentStudent[i]].name << ", ID = " << student[ExcellentStudent[i]].id << " has GPA = " << student[ExcellentStudent[i]].gpa << endl;
}  