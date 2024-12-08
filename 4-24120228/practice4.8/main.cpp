#include "process1.h"
#include <iostream>
int main(){
    Date date1, date2;
    input(date1);
    input(date2);
    outputwhichlater(date1, date2);
    Date tomorrow = getTomorrow(date1);
    Date yesterday = getYesterday(date1);
    std::cout << "Tomorrow and yesterday of date 1" << std::endl;
    output(tomorrow);
    output(yesterday);
    tomorrow = getTomorrow(date2);
    yesterday = getYesterday(date2);
    std::cout << "Tomorrow and yesterday of date 2" << std::endl;
    output(tomorrow);
    output(yesterday);
    return 0;
}