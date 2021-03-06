//
// Created by j-tesla on 03/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_BOOKING_H
#define RAILWAYBOOKINGSYSTEM_BOOKING_H

#include <set>
#include <string>
#include <ostream>


using std::string;

#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include "Passenger.h"
#include "Railways.h"


class Booking {
    const Station fromStation_;
    const Station toStation_;
    const Date date_;
    const BookingClass &bookingClass_;
    Passenger *passenger_;

    const unsigned PNR;
    bool bookingStatus_;
    string bookingMessage_;

    static float sBaseFareRate;
    static std::set<const Booking *> sBookings;
    static unsigned sBookingPNRSerial;
    static float sACSurcharge;
    static float sLuxuryTaxPercent;

    void DoBooking();

    Booking(const Booking &other);

public:
    Booking(const Station &fromStation, const Station &toStation, const Date &date, const BookingClass &bookingClass,
            Passenger *passenger = nullptr);

    virtual ~Booking();

    virtual unsigned ComputeFare() const;

    const Station &GetFromStation() const;

    const Station &GetToStation() const;

    const Date &GetDate() const;

    const BookingClass &GetBookingClass() const;

    Passenger *GetPassenger() const;

    unsigned int GetPNR() const;

    bool GetBookingStatus() const;

    const string &GetBookingMessage() const;

    static const std::set<const Booking *> &GetBookings();

    friend std::ostream &operator<<(std::ostream &os, const Booking &booking);
};


#endif //RAILWAYBOOKINGSYSTEM_BOOKING_H
