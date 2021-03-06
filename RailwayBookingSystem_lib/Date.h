//
// Created by j-tesla on 02/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_DATE_H
#define RAILWAYBOOKINGSYSTEM_DATE_H

#include <map>
#include <string>
#include <ostream>


using std::string;

class Date {
    using Day = unsigned short;
    using Month = unsigned short;
    using Year = unsigned short;

    const Day day_;
    const Month month_;
    const Year year_;

    static const std::map<Month, string> sMonthNames;

public:
    Date(Day day, Month month, Year year);

    ~Date();

    bool operator==(const Date &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

};


#endif //RAILWAYBOOKINGSYSTEM_DATE_H
