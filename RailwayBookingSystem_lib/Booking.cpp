//
// Created by j-tesla on 03/03/21.
//

#include <cmath>

#include "Booking.h"


BookingBase::BookingBase(const Station &fromStation, const Station &toStation, const Date &date,
                         const BookingClass &bookingClass, Passenger *passenger)
        : fromStation_(fromStation),
          toStation_(toStation),
          date_(date),
          bookingClass_(bookingClass),
          passenger_(passenger),
          PNR(sBookingPNRSerial++) {
    sBookings.insert(this);
}

std::set<const BookingBase *> BookingBase::sBookings = {};
unsigned BookingBase::sBookingPNRSerial = 1;

BookingBase::~BookingBase() {
    sBookings.erase(this);
}

const Station &BookingBase::GetFromStation() const {
    return fromStation_;
}

const Station &BookingBase::GetToStation() const {
    return toStation_;
}

const Date &BookingBase::GetDate() const {
    return date_;
}

const BookingClass &BookingBase::GetBookingClass() const {
    return bookingClass_;
}

Passenger *BookingBase::GetPassenger() const {
    return passenger_;
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

const std::set<const BookingBase *> &BookingBase::GetBookings() {
    return sBookings;
}

std::ostream &operator<<(std::ostream &os, const BookingBase &booking) {
    os << booking.bookingMessage_ << ":\n";
    os << "PNR Number = " << booking.PNR << "\n";
    os << "From Station = " << booking.fromStation_.GetName() << "\n";
    os << "To Station = " << booking.toStation_.GetName() << "\n";
    os << "Travel Date = " << booking.date_ << "\n";
    os << "Travel Class = " << booking.bookingClass_ << "\n";
    os << "Fare = " << booking.ComputeFare() << "\n";
    return os;
}

Booking::Booking(const Station &fromStation,
                 const Station &toStation,
                 const Date &date,
                 const BookingClass &bookingClass) : BookingBase(fromStation, toStation, date, bookingClass) {
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
}

unsigned Booking::ComputeFare() const {
    float baseFare = sBaseFareRate * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    float loadedFare = baseFare * bookingClass_.GetLoadFactor();
    if (bookingClass_.IsAc()) {
        loadedFare += sACSurcharge;
    }
    if (bookingClass_.IsLuxury()) {
        loadedFare *= 1 + sLuxuryTaxPercent;
    }
    return std::round(loadedFare);
}
