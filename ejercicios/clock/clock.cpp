#include "clock.h"

#include <iomanip>
#include <sstream>

namespace date_independent {

clock::clock(int hour, int minute) {
    minutes = (hour * 60 + minute) % 1440;

    if (minutes < 0) {
        minutes += 1440;
    }
}

clock clock::at(int hour, int minute) {
    return clock(hour, minute);
}

clock::operator std::string() const {
    int hour = minutes / 60;
    int minute = minutes % 60;

    std::ostringstream output;
    output << std::setfill('0') << std::setw(2) << hour
           << ":" << std::setw(2) << minute;

    return output.str();
}

clock clock::plus(int minutes_to_add) const {
    return clock(0, minutes + minutes_to_add);
}

bool clock::operator==(const clock& other) const {
    return minutes == other.minutes;
}

bool clock::operator!=(const clock& other) const {
    return minutes != other.minutes;
}

}

