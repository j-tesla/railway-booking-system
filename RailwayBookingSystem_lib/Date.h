/**
 * @file Date.h
 * @brief contains Date class
 * @author Jayanth PSY - 19CS10068
 */


#ifndef RAILWAYBOOKINGSYSTEM_DATE_H
#define RAILWAYBOOKINGSYSTEM_DATE_H

#include <map>
#include <string>
#include <ostream>

#include "Exceptions.h"


using std::string;


class Date {
public:
    using Day = unsigned short;
    using Month = unsigned short;
    using Year = unsigned short;

private:
    const Day day_;
    const Month month_;
    const Year year_;

    Date(Day day, Month month, Year year) noexcept;

public:

    ~Date() noexcept;

    /**
     * 3 letter month codes
     */
    static const std::map<Month, string> sMonthNames;

    /**
     * Validates and constructs a Date
     * @param day between 1 and 31, both inclusive and should be valid according to the month parameter
     * @param month between 1 and 12, both inclusive
     * @param year between 1900 and 2099, both inclusive
     * @return constructed Date object
     */
    static Date Construct(Day day, Month month, Year year) noexcept(false);

    /**
     * Validates and Constructs a Date from string
     * @param date string in formats dd/mm/yyyy or dd/MMM/yyyy
     * @return constructed Date object
     */
    static Date Construct(const string &date) noexcept(false);

    inline bool operator==(const Date &other) const {
        return day_ == other.day_ and month_ == other.month_ and year_ == other.year_;
    };

    friend inline std::ostream &operator<<(std::ostream &os, const Date &date) {
        os << date.day_ << "/" << Date::sMonthNames.at(date.month_) << "/" << date.year_;
        return os;
    };

};


#endif //RAILWAYBOOKINGSYSTEM_DATE_H
