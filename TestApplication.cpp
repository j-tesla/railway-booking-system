#include <iostream>

#include "Booking.h"


// consts initialisations
const float ACFirstClass::sLoadFactor = 3.00;
const float AC2Tier::sLoadFactor = 2.00;
const float FirstClass::sLoadFactor = 2.00;
const float AC3Tier::sLoadFactor = 1.75;
const float ACChairCar::sLoadFactor = 1.25;
const float Sleeper::sLoadFactor = 1.00;
const float SecondSitting::sLoadFactor = 0.50;

const bool ACFirstClass::sIsLuxury = true;
const bool AC2Tier::sIsLuxury = false;
const bool FirstClass::sIsLuxury = true;
const bool AC3Tier::sIsLuxury = false;
const bool ACChairCar::sIsLuxury = false;
const bool Sleeper::sIsLuxury = false;
const bool SecondSitting::sIsLuxury = false;

const float Booking::sBaseFareRate = 0.50; // Rs/km
const float Booking::sACSurcharge = 50.00; // Rs
const float Booking::sLuxuryTaxPercent = 25.0 / 100;


void BookingApplication() {
// Bookings by different booking classes
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());

// Output the bookings done
    for (auto it : Booking::GetBookings()) {
        std::cout << *it << "\n";
    }
}

int main() {
    BookingApplication();
    return 0;
}