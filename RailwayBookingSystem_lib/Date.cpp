/**
 * @file Date.cpp
 * @brief contains implementations and declarations of Date class
 * @author Jayanth PSY - 19CS10068
 */

#include <regex>
#include <chrono>

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


Date Date::Construct(Date::Day day, Date::Month month, Date::Year year) noexcept(false) {
    if ((year < 1900) or (year > 2099)) {
        throw Bad_Date("Bad Date: Invalid year, 1900 - 2099 are valid");
    }
    if ((month < 1) or (month > 12)) {
        throw Bad_Date("Bad Date: Invalid month, 1 - 12 are valid");
    }
    if (((month == 1 or month == 3 or month == 5 or month == 7 or
          month == 8 or month == 10 or month == 12)
         and (day > 31 or day < 1)) or
        ((month == 4 or month == 6 or month == 9 or month == 11)
         and (day > 30 or day < 1)) or
        ((month == 2) and (year % 4 == 0) and (day > 29 or day < 1)) or
        ((month == 2) and (year % 4 != 0) and (day > 28 or day < 1))) {
        throw Bad_Date("Bad Date: Invalid day");
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

Date Date::today() {
    std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    tm utc_tm = *gmtime(&current_time);

    auto year = utc_tm.tm_year + 1900;
    auto month = utc_tm.tm_mon + 1;
    auto day = utc_tm.tm_mday;

    auto today = Date::Construct(day, month, year);
    return today;
}

bool Date::operator<(const Date &other) const noexcept {
    if (year_ != other.year_) return this->year_ < other.year_;
    if (month_ != other.month_) return this->month_ < other.month_;
    if (day_ != other.day_) return this->day_ < other.day_;
    return false;
}

bool Date::operator<=(const Date &other) const noexcept {
    return not(other < *this);
}

DateDelta Date::operator-(const Date &other) const noexcept(false) {
    if (*this < other) {
        throw Bad_Date("Bad Date: DateDelta can't be negative");
    }

    int years = year_ - other.year_;

    int months = month_ - other.month_;

    if (months < 0) {
        months += 12;
        years--;
    }


    int days = day_ - other.day_;

    if (days < 0) {
        if (month_ == 1 or month_ == 3 or month_ == 5 or month_ == 7 or month_ == 8 or month_ == 10 or month_ == 12) {
            days += 31;
        } else if (month_ != 2) {
            days += 30;
        } else {
            if (year_ % 4) days += 28;
            else days += 29;
        }
        months--;
    }

    return DateDelta::Construct(days, months, years);
}

DateDelta::DateDelta(DateDelta::Days days, DateDelta::Months months, DateDelta::Years years) noexcept: days_(days),
                                                                                                       months_(months),
                                                                                                       years_(years) {
}

DateDelta::DateDelta(const DateDelta &other) noexcept: days_(other.days_),
                                                       months_(other.months_),
                                                       years_(other.years_) {
}

DateDelta
DateDelta::Construct(DateDelta::Days days, DateDelta::Months months, DateDelta::Years years) noexcept(false) {
    if (days < 0 or months < 0 or years < 0) {
        throw Bad_Date("Bad Date delta: days, months and years can't be negative");
    }

    if (days > 31) {
        throw Bad_Date("Bad Date delta: days can't be greater than 31");
    }

    if (months > 12) {
        throw Bad_Date("Bad Date delta: months can't be greater than 12");
    }

    return DateDelta(days, months, years);
}

bool DateDelta::operator<(const DateDelta &other) const noexcept {
    if (years_ != other.years_) return years_ < other.years_;
    if (months_ != other.months_) return months_ < other.months_;
    if (days_ != other.days_) return days_ < other.days_;
    return false;
}

const DateDelta DateDelta::OneYear(0, 0, 1);

const DateDelta DateDelta::OneMonth(0, 1, 0);

const DateDelta DateDelta::OneDay(1, 0, 0);

bool DateDelta::operator>(const DateDelta &other) const noexcept {
    return other < *this;
}


DateDelta::~DateDelta() = default;
