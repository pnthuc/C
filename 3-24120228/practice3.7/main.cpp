#include <iostream>
#include <sstream>
long long computeBill(long long consumedKWh) {
    long long bill = 0;
    if (consumedKWh <= 100)
        bill = consumedKWh * 1549;
    else if (consumedKWh <= 150)
        bill = 100 * 1549 + (consumedKWh - 100) * 1600;
    else if (consumedKWh <= 200)
        bill = 100 * 1549 + 50 * 1600 + (consumedKWh - 150) * 1858;
    else if (consumedKWh <= 300)
        bill = 100 * 1549 + 50 * 1600 + 50 * 1858 + (consumedKWh - 200) * 2340;
    else if (consumedKWh <= 400)
        bill = 100 * 1549 + 50 * 1600 + 50 * 1858 + 100 * 2340 + (consumedKWh - 300) * 2615;
    else
        bill = 100 * 1549 + 50 * 1600 + 50 * 1858 + 100 * 2340 + 100 * 2615 + (consumedKWh - 400) * 2701;
    return bill;
}

int main() {
    long long oldKWh, newKWh;
    char line[100];
    do {
        std::cout << "Enter old and new kWh: ";
        fgets(line, 100, stdin);
    } while ((std::stringstream(line) >> oldKWh >> newKWh).fail() || oldKWh < 0 || newKWh < oldKWh);

    long long consumedKWh = newKWh - oldKWh;
    long long bill = computeBill(consumedKWh);
    std::cout << "Electricity bill = " << bill << " d.";

    return 0;
}