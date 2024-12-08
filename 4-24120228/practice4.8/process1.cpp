#include <iostream>
#include "process1.h"

bool isLater( Date d1,  Date d2) {
    if (d1.year != d2.year) 
        return d1.year > d2.year;
    if (d1.month != d2.month) 
        return d1.month > d2.month;
    return d1.day > d2.day;
}

void outputwhichlater(Date d1, Date d2) {
    if (isLater(d1, d2)) 
        std::cout << "Date 1 is later than Date 2" << std::endl;
    else 
        std::cout << "Date 2 is later than Date 1" << std::endl;
}

Date getTomorrow(Date date) {
    Date tomorrow = date;
    tomorrow.day++;
    
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((tomorrow.year % 4 == 0 && tomorrow.year % 100 != 0) || (tomorrow.year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (tomorrow.day > daysInMonth[tomorrow.month - 1]) {
        tomorrow.day = 1;
        tomorrow.month++;
        if (tomorrow.month > 12) {
            tomorrow.month = 1;
            tomorrow.year++;
        }
    }
    return tomorrow;
}

Date getYesterday( Date date) {
    Date yesterday = date;
    yesterday.day--;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((yesterday.year % 4 == 0 && yesterday.year % 100 != 0) || (yesterday.year % 400 == 0))
        daysInMonth[1] = 29;

    if (yesterday.day < 1) {
        yesterday.month--;
        if (yesterday.month < 1) {
            yesterday.month = 12;
            yesterday.year--;
        }
        yesterday.day = daysInMonth[yesterday.month - 1];
    }

    return yesterday;
}

void input(Date &date) {
    std::cout << "Enter year: ";
    std::cin >> date.year;
    std::cout << "Enter month: ";
    std::cin >> date.month;
    std::cout << "Enter day: ";
    std::cin >> date.day;
    std::cout << '\n';
}
void output(Date date) {
    std::cout << "Date: " << date.day << "/" << date.month << "/" << date.year << std::endl;
}