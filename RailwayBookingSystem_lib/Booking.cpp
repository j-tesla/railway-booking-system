/**
 * @file Booking.cpp
 * @brief contains implementations and definitions of BookingCase and Booking classes
 * @author Jayanth PSY - 19CS10068
 */

#include <cmath>

#include "Booking.h"


BookingBase::BookingBase(const Station &fromStation, const Station &toStation, const Date &dateOfBooking,
                         const Date &dateOfReservation, const BookingClass &bookingClass,
                         const BookingCategory &bookingCategory, const Passenger &passenger)
        : fromStation_(fromStation),
          toStation_(toStation),
          dateOfBooking_(dateOfBooking),
          dateOfReservation_(dateOfReservation),
          bookingClass_(bookingClass),
          bookingCategory_(bookingCategory),
          passenger_(passenger),
          PNR(sBookingPNRSerial++) {
    sBookings.push_back(this);
}

std::vector<const BookingBase *> BookingBase::sBookings = {};
unsigned BookingBase::sBookingPNRSerial = 1;

BookingBase::~BookingBase() = default;

const Station &BookingBase::GetFromStation() const {
    return fromStation_;
}

const Station &BookingBase::GetToStation() const {
    return toStation_;
}

const Date &BookingBase::GetDate() const {
    return dateOfBooking_;
}

const Date &BookingBase::GetDateOfReservation() const {
    return dateOfReservation_;
}


const BookingClass &BookingBase::GetBookingClass() const {
    return bookingClass_;
}

unsigned int BookingBase::GetPNR() const {
    return PNR;
}

bool BookingBase::GetBookingStatus() const {
    return bookingStatus_;
}

const string &BookingBase::GetBookingMessage() const {
    return bookingMessage_;
}


const std::vector<const BookingBase *> &BookingBase::GetBookings() {
    return sBookings;
}

std::ostream &operator<<(std::ostream &os, const BookingBase &booking) {
    os << booking.bookingMessage_ << ":\n";
    os << "PNR Number = " << booking.PNR << "\n";
    os << "From Station = " << booking.fromStation_.GetName() << "\n";
    os << "To Station = " << booking.toStation_.GetName() << "\n";
    os << "Travel Date = " << booking.dateOfBooking_ << "\n";
    os << "Travel Class = " << booking.bookingClass_ << "\n";
    os << "Fare = " << booking.ComputeFare() << "\n";
    return os;
}

void BookingBase::ClearBookings() {
    for (auto &pBooking: sBookings) {
        delete pBooking;
    }
    sBookings.clear();

}

Booking::Booking(const Station &fromStation,
                 const Station &toStation,
                 const Date &dateOfBooking,
                 const Date &dateOfReservation,
                 const BookingClass &bookingClass,
                 const BookingCategory &bookingCategory,
                 const Passenger &passenger) : BookingBase(fromStation, toStation, dateOfBooking, dateOfReservation,
                                                           bookingClass, bookingCategory, passenger) {
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
}

unsigned Booking::ComputeFare() const {
    float baseFare = sBaseFareRate * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    float loadedFare = baseFare * bookingClass_.GetFareLoadFactor();

    return std::round(
            bookingCategory_.CalculateFare(loadedFare, bookingClass_, passenger_,
                                           Railways::IndianRailways().GetDistance(fromStation_, toStation_))
            + bookingClass_.GetReservationCharge()
    );
}


const Booking &Booking::Construct(const Station &fromStation, const Station &toStation, const Date &dateOfBooking,
                                  const BookingClass &bookingClass,
                                  const BookingCategory &bookingCategory, const Passenger &passenger) noexcept(false) {

    if (not Railways::IndianRailways().ValidStation(fromStation)) {
        throw Bad_Booking("Bad Booking: invalid from station");
    }
    if (not Railways::IndianRailways().ValidStation(toStation)) {
        throw Bad_Booking("Bad Booking: invalid to station");
    }

    Date today = Date::today();
    if (not(today < dateOfBooking)) {
        throw Bad_Booking("Bad Booking: date of travel must be later than date of reservation");
    }

    if (dateOfBooking - today > DateDelta::OneYear) {
        throw Bad_Booking("Bad Booking: date of travel should be within one year from today");
    }

    if (not bookingCategory.IsEligible(passenger, dateOfBooking, today)) {
        throw Bad_Booking("Bad Booking: details provided are ineligible to the selected booking category");
    }

    auto pBooking = new const Booking(fromStation, toStation, dateOfBooking, today, bookingClass, bookingCategory,
                                      passenger);
    return *pBooking;
}
