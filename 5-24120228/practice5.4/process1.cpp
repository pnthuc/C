#include "process1.h"
#include <iostream>
#include <sstream>
void input(Date dates[], ll &N) {
    char line[100];
    do {
        std::cout << "Enter the number of dates: ";
        fgets(line, 100, stdin);
    } while ((std::stringstream(line) >> N).fail() or N <= 0);
    for (int i = 0; i < N; ++i) {
        do{
            std::cout << "Enter date " << i + 1 << " (day month year): ";
            fgets(line, 100, stdin);
        }while ((std::stringstream(line) >> dates[i].day >> dates[i].month >> dates[i].year).fail() 
                    or dates[i].day <= 0 or dates[i].month <= 0 or dates[i].year <= 0
                        or dates[i].day > 31 or dates[i].month > 12);
    }
}

bool compareDates(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) return d1.year > d2.year;
    if (d1.month != d2.month) return d1.month > d2.month;
    return d1.day > d2.day;
}

void output(Date dates[], ll N) {
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < i; j ++)
            if(compareDates(dates[i], dates[j]))
                std::swap(dates[i], dates[j]);
    for (int c = 0; c < N; ++c) 
        std::cout << dates[c].day << "/" << dates[c].month << "/" << dates[c].year << std::endl;
}