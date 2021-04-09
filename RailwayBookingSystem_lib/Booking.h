/**
 * @file Booking.h
 * @brief contains BookingCase and Booking classes
 * @author Jayanth PSY - 19CS10068
 */

#ifndef RAILWAYBOOKINGSYSTEM_BOOKING_H
#define RAILWAYBOOKINGSYSTEM_BOOKING_H

#include <vector>
#include <string>
#include <ostream>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "BookingCategories.h"
#include "Passenger.h"
#include "Railways.h"


using std::string;

/**
 * Abstract base for extension of Booking implementations
 */
class BookingBase {
    const unsigned PNR;

    static std::vector<const BookingBase *> sBookings;
    static unsigned sBookingPNRSerial;

protected:
    const Station fromStation_;
    const Station toStation_;
    const Date dateOfBooking_;
    const Date dateOfReservation_;
    const Passenger &passenger_;

    const BookingClass &bookingClass_;
    const BookingCategory &bookingCategory_;

    bool bookingStatus_ = false;
    string bookingMessage_{};

    BookingBase(const Station &fromStation, const Station &toStation, const Date &dateOfBooking,
                const Date &dateOfReservation,
                const BookingClass &bookingClass,
                const BookingCategory &bookingCategory,
                const Passenger &passenger);

    /**
     *  A BookingBase object should not be copyable
     * @param other
     */
    BookingBase(const BookingBase &other) = delete;

    virtual ~BookingBase();

public:
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
     * @return vector of pointers to active bookings
     */
    static const std::vector<const BookingBase *> &GetBookings();

    static void ClearBookings();

    const Date &GetDateOfReservation() const;

    friend std::ostream &operator<<(std::ostream &os, const BookingBase &booking);
};


/**
 * Booking from anywhere to anywhere on any date is always available
 */
class Booking : public BookingBase {
    static const float sBaseFareRate;        //! needs initiate in application

    Booking(const Station &fromStation, const Station &toStation, const Date &dateOfBooking,
            const Date &dateOfReservation, const BookingClass &bookingClass,
            const BookingCategory &bookingCategory, const Passenger &passenger);

public:

    static const Booking &Construct(const Station &fromStation, const Station &toStation, const Date &dateOfBooking,
                                    const BookingClass &bookingClass, const BookingCategory &bookingCategory,
                                    const Passenger &passenger) noexcept(false);

    /**
     * computes fare for the booking from with the business logic
     * @return fare in Rupees (rounded off to nearest integer)
     */
    unsigned ComputeFare() const override;
};


#endif //RAILWAYBOOKINGSYSTEM_BOOKING_H
