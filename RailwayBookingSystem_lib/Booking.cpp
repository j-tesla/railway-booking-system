//
// Created by j-tesla on 03/03/21.
//

#include <cmath>

#include "Booking.h"


Booking::Booking(const Station &fromStation, const Station &toStation, const Date &date,
                 const BookingClass &bookingClass, Passenger *passenger)
        : fromStation_(fromStation),
          toStation_(toStation),
          date_(date),
          bookingClass_(bookingClass),
          passenger_(passenger),
          PNR(sBookingPNRSerial++){
    DoBooking();
    sBookings.insert(this);
}

float Booking::sBaseFareRate = 0.50; // Rs/km
std::set<const Booking *> Booking::sBookings = {};
unsigned Booking::sBookingPNRSerial = 1;
float Booking::sACSurcharge = 50.00; // Rs
float Booking::sLuxuryTaxPercent = 25.0 / 100;

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

void Booking::DoBooking() {
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";

}

Booking::~Booking() {
    sBookings.erase(this);
}

const Station &Booking::GetFromStation() const {
    return fromStation_;
}

const Station &Booking::GetToStation() const {
    return toStation_;
}

const Date &Booking::GetDate() const {
    return date_;
}

const BookingClass &Booking::GetBookingClass() const {
    return bookingClass_;
}

Passenger *Booking::GetPassenger() const {
    return passenger_;
}

unsigned int Booking::GetPNR() const {
    return PNR;
}

bool Booking::GetBookingStatus() const {
    return bookingStatus_;
}

const string &Booking::GetBookingMessage() const {
    return bookingMessage_;
}

const std::set<const Booking *> &Booking::GetBookings() {
    return sBookings;
}

std::ostream &operator<<(std::ostream &os, const Booking &booking) {
    os << booking.bookingMessage_ << ":\n";
    os << "PNR Number = " << booking.PNR << "\n";
    os << "From Station = " << booking.fromStation_.GetName() << "\n";
    os << "To Station = " << booking.toStation_.GetName() << "\n";
    os << "Travel Date = " << booking.date_ << "\n";
    os << "Travel Class = " << booking.bookingClass_ << "\n";
    os << "Fare = " << booking.ComputeFare() << "\n";
    return os;
}
