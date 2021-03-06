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
public:
    using Day = unsigned short;
    using Month = unsigned short;
    using Year = unsigned short;

private:
    const Day day_;
    const Month month_;
    const Year year_;

public:
    Date(Day day, Month month, Year year);

    ~Date();

    /**
     * 3 letter month codes
     */
    static const std::map<Month, string> sMonthNames;

    bool operator==(const Date &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

};


#endif //RAILWAYBOOKINGSYSTEM_DATE_H
