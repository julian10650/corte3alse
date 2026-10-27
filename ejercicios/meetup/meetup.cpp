#include "meetup.h"
#include <stdexcept>

namespace meetup {

using namespace boost::gregorian;

scheduler::scheduler(greg_month month, int year)
    : month(month), year(year) {
}

// BUSCAR UN DIA DE LA SEMANA

date scheduler::find_day(greg_weekday weekday, int start, int end) const {
    if (start <= end) {
        for (int day = start; day <= end; day++) {
            date current(
                static_cast<unsigned short>(year),
                static_cast<unsigned short>(month.as_number()),
                static_cast<unsigned short>(day)
            );

            if (current.day_of_week() == weekday.as_number()) {
                return current;
            }
        }
    } else {
        for (int day = start; day >= end; day--) {
            date current(
                static_cast<unsigned short>(year),
                static_cast<unsigned short>(month.as_number()),
                static_cast<unsigned short>(day)
            );

            if (current.day_of_week() == weekday.as_number()) {
                return current;
            }
        }
    }

    throw std::invalid_argument("Date not found");
}

// FIRST

date scheduler::first_monday() const {
    return find_day(Monday, 1, 7);
}

date scheduler::first_tuesday() const {
    return find_day(Tuesday, 1, 7);
}

date scheduler::first_wednesday() const {
    return find_day(Wednesday, 1, 7);
}

date scheduler::first_thursday() const {
    return find_day(Thursday, 1, 7);
}

date scheduler::first_friday() const {
    return find_day(Friday, 1, 7);
}

date scheduler::first_saturday() const {
    return find_day(Saturday, 1, 7);
}

date scheduler::first_sunday() const {
    return find_day(Sunday, 1, 7);
}

// SECOND

date scheduler::second_monday() const {
    return find_day(Monday, 8, 14);
}

date scheduler::second_tuesday() const {
    return find_day(Tuesday, 8, 14);
}

date scheduler::second_wednesday() const {
    return find_day(Wednesday, 8, 14);
}

date scheduler::second_thursday() const {
    return find_day(Thursday, 8, 14);
}

date scheduler::second_friday() const {
    return find_day(Friday, 8, 14);
}

date scheduler::second_saturday() const {
    return find_day(Saturday, 8, 14);
}

date scheduler::second_sunday() const {
    return find_day(Sunday, 8, 14);
}

// THIRD

date scheduler::third_monday() const {
    return find_day(Monday, 15, 21);
}

date scheduler::third_tuesday() const {
    return find_day(Tuesday, 15, 21);
}

date scheduler::third_wednesday() const {
    return find_day(Wednesday, 15, 21);
}

date scheduler::third_thursday() const {
    return find_day(Thursday, 15, 21);
}

date scheduler::third_friday() const {
    return find_day(Friday, 15, 21);
}

date scheduler::third_saturday() const {
    return find_day(Saturday, 15, 21);
}

date scheduler::third_sunday() const {
    return find_day(Sunday, 15, 21);
}

// FOURTH

date scheduler::fourth_monday() const {
    return find_day(Monday, 22, 28);
}

date scheduler::fourth_tuesday() const {
    return find_day(Tuesday, 22, 28);
}

date scheduler::fourth_wednesday() const {
    return find_day(Wednesday, 22, 28);
}

date scheduler::fourth_thursday() const {
    return find_day(Thursday, 22, 28);
}

date scheduler::fourth_friday() const {
    return find_day(Friday, 22, 28);
}

date scheduler::fourth_saturday() const {
    return find_day(Saturday, 22, 28);
}

date scheduler::fourth_sunday() const {
    return find_day(Sunday, 22, 28);
}

// LAST

date scheduler::last_monday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Monday, ultimo, 1);
}

date scheduler::last_tuesday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Tuesday, ultimo, 1);
}

date scheduler::last_wednesday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Wednesday, ultimo, 1);
}

date scheduler::last_thursday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Thursday, ultimo, 1);
}

date scheduler::last_friday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Friday, ultimo, 1);
}

date scheduler::last_saturday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Saturday, ultimo, 1);
}

date scheduler::last_sunday() const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(Sunday, ultimo, 1);
}

// TEENTH: DEL 13 AL 19

date scheduler::monteenth() const {
    return find_day(Monday, 13, 19);
}

date scheduler::tuesteenth() const {
    return find_day(Tuesday, 13, 19);
}

date scheduler::wednesteenth() const {
    return find_day(Wednesday, 13, 19);
}

date scheduler::thursteenth() const {
    return find_day(Thursday, 13, 19);
}

date scheduler::friteenth() const {
    return find_day(Friday, 13, 19);
}

date scheduler::saturteenth() const {
    return find_day(Saturday, 13, 19);
}

date scheduler::sunteenth() const {
    return find_day(Sunday, 13, 19);
}

// GENERIC METHODS

date scheduler::first(greg_weekday weekday) const {
    return find_day(weekday, 1, 7);
}

date scheduler::second(greg_weekday weekday) const {
    return find_day(weekday, 8, 14);
}

date scheduler::third(greg_weekday weekday) const {
    return find_day(weekday, 15, 21);
}

date scheduler::fourth(greg_weekday weekday) const {
    return find_day(weekday, 22, 28);
}

date scheduler::last(greg_weekday weekday) const {
    int ultimo = gregorian_calendar::end_of_month_day(
        static_cast<greg_year>(year), month);
    return find_day(weekday, ultimo, 1);
}

date scheduler::teenth(greg_weekday weekday) const {
    return find_day(weekday, 13, 19);
}

} // namespace meetup
