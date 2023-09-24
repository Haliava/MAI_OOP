#include <iostream>
#include "../header/convertTimeTo24h.h"

int main() {
    // hh:mm
    std::string timeString;
    // am | pm
    std::string timePeriod;

    std::cin >> timeString >> timePeriod;
    std::cout << convertTimeTo24h(timeString, timePeriod);
    return 0;
}
