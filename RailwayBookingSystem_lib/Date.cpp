/**
 * @file Date.cpp
 * @brief contains implementations and declarations of Date class
 * @author Jayanth PSY - 19CS10068
 */

#include <regex>

#include "Date.h"


Date::Date(Date::Day day, Date::Month month, Date::Year year) noexcept: day_(day), month_(month), year_(year) {}

Date::~Date() noexcept = default;

std::map<unsigned short, string> MonthNames() {
    std::map<unsigned short, string> monthNames = {};
    monthNames[1] = "JAN";
    monthNames[2] = "FEB";
    monthNames[3] = "MAR";
    monthNames[4] = "APR";
    monthNames[5] = "MAY";
    monthNames[6] = "JUN";
    monthNames[7] = "JUL";
    monthNames[8] = "AUG";
    monthNames[9] = "SEP";
    monthNames[10] = "OCT";
    monthNames[11] = "NOV";
    monthNames[12] = "DEC";
    return monthNames;
}

const std::map<Date::Month, string> Date::sMonthNames = MonthNames();

bool Date::operator==(const Date &other) const {
    return day_ == other.day_ and month_ == other.month_ and year_ == other.year_;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day_ << "/" << Date::sMonthNames.at(date.month_) << "/" << date.year_;
    return os;
}

Date Date::Construct(Date::Day day, Date::Month month, Date::Year year) noexcept(false) {
    if (((month == 1 or month == 3 or month == 5 or month == 7 or
          month == 8 or month == 10 or month == 12)
         and (day > 31 or day < 1)) or
        ((month == 4 or month == 6 or month == 9 or month == 11)
         and (day > 30 or day < 1)) or
        ((month == 2) and (year % 4 == 0) and (day > 29 or day < 1)) or
        ((month == 2) and (year % 4 != 0) and (day > 28 or day < 1))) {
        throw Bad_Date("Bad Date: Invalid day");
    } else if ((year < 1900) or (year > 2099)) {
        throw Bad_Date("Bad Date: Invalid year, 1900 - 2099 are valid");
    }
    if ((month < 1) or (month > 12)) {
        throw Bad_Date("Bad Date: Invalid month, 1 - 12 are valid");
    }
    return Date(day, month, year);
}

Date Date::Construct(const string &date) noexcept(false) {
    std::regex datePattern1(R"((\d{2})/(\d{2})/(\d{4}))");
    std::regex datePattern2(R"((\d{2})/([A-Z]{3})/(\d{4}))");
    std::smatch matches;
    if (std::regex_match(date, matches, datePattern1)) {
        Day day = std::stoul(matches[1]);
        Month month = std::stoul(matches[2]);
        Year year = std::stoul(matches[3]);
        return Construct(day, month, year);
    }

    if (std::regex_match(date, matches, datePattern2)) {
        Day day = std::stoul(matches[1]);
        Year year = std::stoul(matches[3]);
        for (const auto &p: sMonthNames) {
            if (p.second == matches[2]) {
                return Construct(day, p.first, year);
            }
        }
        throw Bad_Date("Bad Date: Invalid month");
    }
    throw Bad_Date("Bad Date: Invalid pattern, dd/MMM/yyyy and dd//mm/yyyy are valid");
}
