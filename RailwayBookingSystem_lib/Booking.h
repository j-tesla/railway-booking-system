/**
 * @file Booking.h
 * @brief contains BookingCase and Booking classes
 * @author Jayanth PSY - 19CS10068
 */

#ifndef RAILWAYBOOKINGSYSTEM_BOOKING_H
#define RAILWAYBOOKINGSYSTEM_BOOKING_H

#include <set>
#include <string>
#include <ostream>

#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include "Passenger.h"
#include "Railways.h"


using std::string;

/**
 * Abstract base for extension of Booking implementations
 */
class BookingBase {
    const unsigned PNR;

    static std::set<const BookingBase *> sBookings;
    static unsigned sBookingPNRSerial;

protected:
    const Station fromStation_;
    const Station toStation_;
    const Date date_;
    const BookingClass &bookingClass_;
    Passenger *passenger_;

    bool bookingStatus_ = false;
    string bookingMessage_{};

public:
    /**
     * constructor
     * @param fromStation
     * @param toStation
     * @param date
     * @param bookingClass Type object of BookingClasses
     * @param passenger
     */
    BookingBase(const Station &fromStation, const Station &toStation, const Date &date,
                const BookingClass &bookingClass,
                Passenger *passenger = nullptr);

    /**
     *  A BookingBase object should not be copyable
     * @param other
     */
    BookingBase(const BookingBase &other) = delete;

    virtual ~BookingBase();

    /*
     * pure virtual function to implemented in derived classes
     */
    virtual unsigned ComputeFare() const = 0;

    /**
     *
     * @return FromStation of the journey
     */
    const Station &GetFromStation() const;

    /**
     *
     * @return ToStation of the journey
     */
    const Station &GetToStation() const;

    /**
     *
     * @return date of the journey
     */
    const Date &GetDate() const;

    /**
     *
     * @return booking class
     */
    const BookingClass &GetBookingClass() const;

    /**
     *
     * @return passenger
     */
    Passenger *GetPassenger() const;

    /**
     * PNR is the unique identification code of the booking
     * @return PNR of the booking
     */
    unsigned int GetPNR() const;

    /**
     * Booking status is true if confirmed
     * @return booking status
     */
    bool GetBookingStatus() const;

    /**
     * Message related to the status of booking
     * @return booking message
     */
    const string &GetBookingMessage() const;

    /**
     * Booking is active if in created object is in scope and accessible
     * @return set of pointers to active bookings
     */
    static const std::set<const BookingBase *> &GetBookings();

    friend std::ostream &operator<<(std::ostream &os, const BookingBase &booking);
};


/**
 * Booking from anywhere to anywhere on any date is always available
 */
class Booking : public BookingBase {
    static const float sBaseFareRate;        //! needs initiate in application
    static const float sACSurcharge;        //! needs initiate in application
    static const float sLuxuryTaxPercent;       //! needs initiate in application

public:
    /**
     * constructor to always available booking
     * @param fromStation
     * @param toStation
     * @param date
     * @param bookingClass Type object of BookingClasses
     */
    Booking(const Station &fromStation, const Station &toStation, const Date &date, const BookingClass &bookingClass);

    /**
     * computes fare for the booking from with the business logic
     * @return fare in Rupees (rounded off to nearest integer)
     */
    unsigned ComputeFare() const override;
};


#endif //RAILWAYBOOKINGSYSTEM_BOOKING_H
