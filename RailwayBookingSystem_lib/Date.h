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

class DateDelta;

class Date {
public:
    using Day = unsigned short;
    using Month = unsigned short;
    using Year = unsigned short;

private:
    Day day_;
    Month month_;
    Year year_;

public:

    Date(Day day, Month month, Year year) noexcept;

    ~Date() noexcept;

    Day GetDay() const;

    Month GetMonth() const;

    Year GetYear() const;

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

    static Date Today();

    inline bool operator==(const Date &other) const {
        return day_ == other.day_ and month_ == other.month_ and year_ == other.year_;
    };

    bool operator<(const Date &other) const noexcept;

    bool operator<=(const Date &other) const noexcept;

    DateDelta operator-(const Date &other) const noexcept(false);

    friend inline std::ostream &operator<<(std::ostream &os, const Date &date) {
        os << date.day_ << "/" << Date::sMonthNames.at(date.month_) << "/" << date.year_;
        return os;
    };

};

class DateDelta {
public:
    using Days = unsigned short;
    using Months = unsigned short;
    using Years = unsigned short;

    const Days days_;
    const Months months_;
    const Years years_;

private:
    DateDelta(Days days, Months months, Years years) noexcept;

public:
    DateDelta(const DateDelta &other) noexcept;

    ~DateDelta();

    static DateDelta Construct(Days days, Months months, Years years) noexcept(false);

    bool operator<(const DateDelta &other) const noexcept;

    bool operator>(const DateDelta &other) const noexcept;

    inline bool operator==(const DateDelta &rhs) const {
        return std::tie(days_, months_, years_) == std::tie(rhs.days_, rhs.months_, rhs.years_);
    }

    static inline const DateDelta OneYear() {
        return DateDelta(0, 0, 1);
    }

    static inline const DateDelta OneMonth() {
        return DateDelta(0, 1, 0);
    }

    static inline const DateDelta OneDay() {
        return DateDelta(1, 0, 0);
    }

};


#endif //RAILWAYBOOKINGSYSTEM_DATE_H
