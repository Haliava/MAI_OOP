#include <iomanip>
#include "../include/convertTimeTo24h.h"

std::string convertTimeTo24h(std::string timeIn12h, const std::string& timePeriod) {
    std::stringstream buffer;
    // 1 <= hours <= 12
    int hours;
    // 0 <= minutes <= 59
    int minutes;
    bool isAM;

    hours = std::stoi(timeIn12h.substr(0, timeIn12h.find(':')));
    minutes = std::stoi(timeIn12h.erase(0, timeIn12h.find(':') + 1));
    isAM = timePeriod == "am";

    buffer
        << std::setw(2)
        << std::setfill('0')
        << ((isAM ? 0: 12) + hours) % 24
        << minutes;

    return buffer.str();
}