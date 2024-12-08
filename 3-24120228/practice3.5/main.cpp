#include <iostream>
#include <Windows.h>
int main() {
    int count = 1;

    for (int i = 100; i <= 999; ++i) {
        int hundreds = i / 100;
        int tens = (i / 10) % 10;
        int ones = i % 10;

        if (tens == hundreds + ones) {
            std::cout << count << ": " << i << std::endl;
            count++;
            Sleep(500);
        }
    }

    std::cout << "There are " << count - 1 << " satisfied numbers." << std::endl;
    return 0;
}