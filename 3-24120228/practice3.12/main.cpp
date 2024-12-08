#include <iostream>
#include <sstream>
#include <string>

bool isValidPhoneNumber(long long phoneNumber) {
    return phoneNumber >= 100000000 && phoneNumber <= 9999999999;
}
std::string getDigits(int digit) {
    switch (digit) {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
    }
    return "";
}
void printNumberInWords(long long phoneNumber) {
    long long divisor = 1000000000;
    bool leadingZero = true;
    int count = 0;
    while (divisor > 0) {
        int digit = (phoneNumber / divisor) % 10;
        if (digit != 0 || !leadingZero) {
            if(count == 0) {
                std::string s = getDigits(digit);
                s[0] = toupper(s[0]);
                std::cout << s;
            } else
                std::cout << getDigits(digit);
            leadingZero = false;
            count ++;
        } else if(leadingZero)
            std::cout << "Zero", count ++;
        divisor /= 10;

        if(count < 10) std::cout << " ";
    }
    std::cout << '.';
}

int main(){
    long long phoneNumber;
    char line[100];
    do{
        std::cout << "Phone number: ";
        fgets(line, 100, stdin);
    } while ((std::stringstream(line) >> phoneNumber).fail() || !isValidPhoneNumber(phoneNumber));

    printNumberInWords(phoneNumber);

    return 0;
}