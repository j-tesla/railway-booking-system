//
// Created by j-tesla on 02/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_DATE_H
#define RAILWAYBOOKINGSYSTEM_DATE_H


class Date {
    enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum WeekDay {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
    using Day = unsigned int;
    using Year = unsigned int;
    Day day_;
    Month month_;
    Year year_;

public:
    // todo errors like day > 30
    Date(Day day, Month month, Year year);

    ~Date();

    // todo statics
};


#endif //RAILWAYBOOKINGSYSTEM_DATE_H
