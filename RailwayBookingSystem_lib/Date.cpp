//
// Created by Jayanth PSY (19CS10068) on 02/03/21.
//

#include "Date.h"


Date::Date(Date::Day day, Date::Month month, Date::Year year) : day_(day), month_(month), year_(year) {}

Date::~Date() = default;

std::map<unsigned short, string> MonthNames() {
    std::map<unsigned short, string> monthNames = {};
    monthNames[1] = "Jan";
    monthNames[2] = "Feb";
    monthNames[3] = "Mar";
    monthNames[4] = "Apr";
    monthNames[5] = "May";
    monthNames[6] = "Jun";
    monthNames[7] = "Jul";
    monthNames[8] = "Aug";
    monthNames[9] = "Sep";
    monthNames[10] = "Oct";
    monthNames[11] = "Nov";
    monthNames[12] = "Dec";
    return monthNames;
};

const std::map<Date::Month, string> Date::sMonthNames = MonthNames();

bool Date::operator==(const Date &other) const {
    return day_ == other.day_ and month_ == other.month_ and year_ == other.year_;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day_ << "/" << Date::sMonthNames.at(date.month_) << "/" << date.year_;
    return os;
}
