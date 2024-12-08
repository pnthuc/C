#pragma once
struct Date {
    int day;
    int month;
    int year;
};

bool isLater( Date d1,  Date d2);
void outputwhichlater(Date d1, Date d2);
Date getTomorrow( Date date);
Date getYesterday( Date date);
void input(Date& date);
void output(Date date);