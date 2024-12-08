#include <iostream>

bool isLeapYear(int year) {
    if (year % 4 == 0)
        if (year % 100 == 0)
            if (year % 400 == 0)
                return true;
            else
                return false;
        else
            return true;
    else
        return false;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return -1; 
    }
}

int main() {
    int month, year;
    std::cout << "Enter month and year = ";
    std::cin >> month >> year;
    int days = getDaysInMonth(month, year);
    std::cout << "Month " << month << " in year " << year << " has " << days << " days.";

    return 0;
}