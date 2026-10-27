#pragma once

#include <string>

namespace date_independent {

class clock {
public:
    static clock at(int hour, int minute);

    operator std::string() const;

    clock plus(int minutes) const;

    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;

private:
    int minutes;

    clock(int hour, int minute);
};

}

