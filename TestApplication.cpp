/**
 * @file TestApplication.cpp
 * @brief test application for BookingSystem library
 * @author Jayanth PSY - 19CS10068
 */


#include <iostream>

#include "Booking.h"



// consts initialisations

const float Booking::sBaseFareRate = 0.50;      // Rs/km

template<> const float BookingClass::ACFirstClass::sFareLoadFactor = 6.50;
template<> const float BookingClass::ExecutiveChairCar::sFareLoadFactor = 5.00;
template<> const float BookingClass::AC2Tier::sFareLoadFactor = 4.00;
template<> const float BookingClass::FirstClass::sFareLoadFactor = 3.00;
template<> const float BookingClass::AC3Tier::sFareLoadFactor = 2.50;
template<> const float BookingClass::ACChairCar::sFareLoadFactor = 2.00;
template<> const float BookingClass::Sleeper::sFareLoadFactor = 1.00;
template<> const float BookingClass::SecondSitting::sFareLoadFactor = 0.60;

template<> const float BookingClass::ACFirstClass::sReservationCharge = 60.00;
template<> const float BookingClass::ExecutiveChairCar::sReservationCharge = 60.00;
template<> const float BookingClass::AC2Tier::sReservationCharge = 50.00;
template<> const float BookingClass::FirstClass::sReservationCharge = 50.00;
template<> const float BookingClass::AC3Tier::sReservationCharge = 40.00;
template<> const float BookingClass::ACChairCar::sReservationCharge = 40.00;
template<> const float BookingClass::Sleeper::sReservationCharge = 20.00;
template<> const float BookingClass::SecondSitting::sReservationCharge = 15.00;

template<> const bool BookingClass::ACFirstClass::sIsLuxury = true;
template<> const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;
template<> const bool BookingClass::AC2Tier::sIsLuxury = false;
template<> const bool BookingClass::FirstClass::sIsLuxury = true;
template<> const bool BookingClass::AC3Tier::sIsLuxury = false;
template<> const bool BookingClass::ACChairCar::sIsLuxury = false;
template<> const bool BookingClass::Sleeper::sIsLuxury = false;
template<> const bool BookingClass::SecondSitting::sIsLuxury = false;

template<> const float BookingClass::ACFirstClass::sMinimumTatkalCharges = 400.00;
template<> const float BookingClass::ExecutiveChairCar::sMinimumTatkalCharges = 400.00;
template<> const float BookingClass::AC2Tier::sMinimumTatkalCharges = 400.00;
template<> const float BookingClass::FirstClass::sMinimumTatkalCharges = 400.00;
template<> const float BookingClass::AC3Tier::sMinimumTatkalCharges = 300.00;
template<> const float BookingClass::ACChairCar::sMinimumTatkalCharges = 125.00;
template<> const float BookingClass::Sleeper::sMinimumTatkalCharges = 100.00;
template<> const float BookingClass::SecondSitting::sMinimumTatkalCharges = 10.00;

template<> const float BookingClass::ACFirstClass::sMaximumTatkalCharges = 500.00;
template<> const float BookingClass::ExecutiveChairCar::sMaximumTatkalCharges = 500.00;
template<> const float BookingClass::AC2Tier::sMaximumTatkalCharges = 500.00;
template<> const float BookingClass::FirstClass::sMaximumTatkalCharges = 500.00;
template<> const float BookingClass::AC3Tier::sMaximumTatkalCharges = 400.00;
template<> const float BookingClass::ACChairCar::sMaximumTatkalCharges = 225.00;
template<> const float BookingClass::Sleeper::sMaximumTatkalCharges = 200.00;
template<> const float BookingClass::SecondSitting::sMaximumTatkalCharges = 15.00;

template<> const unsigned BookingClass::ACFirstClass::sMinimumDistanceForTatkalCharge = 500;
template<> const unsigned BookingClass::ExecutiveChairCar::sMinimumDistanceForTatkalCharge = 250;
template<> const unsigned BookingClass::AC2Tier::sMinimumDistanceForTatkalCharge = 500;
template<> const unsigned BookingClass::FirstClass::sMinimumDistanceForTatkalCharge = 500;
template<> const unsigned BookingClass::AC3Tier::sMinimumDistanceForTatkalCharge = 500;
template<> const unsigned BookingClass::ACChairCar::sMinimumDistanceForTatkalCharge = 250;
template<> const unsigned BookingClass::Sleeper::sMinimumDistanceForTatkalCharge = 500;
template<> const unsigned BookingClass::SecondSitting::sMinimumDistanceForTatkalCharge = 100;

template<> const float BookingClass::ACFirstClass::sTatkalChargeRate = 0.30;
template<> const float BookingClass::ExecutiveChairCar::sTatkalChargeRate = 0.30;
template<> const float BookingClass::AC2Tier::sTatkalChargeRate = 0.30;
template<> const float BookingClass::FirstClass::sTatkalChargeRate = 0.30;
template<> const float BookingClass::AC3Tier::sTatkalChargeRate = 0.30;
template<> const float BookingClass::ACChairCar::sTatkalChargeRate = 0.30;
template<> const float BookingClass::Sleeper::sTatkalChargeRate = 0.30;
template<> const float BookingClass::SecondSitting::sTatkalChargeRate = 0.10;

template<> const float BookingClass::ACFirstClass::sBlindConcessionFactor = 0.50;
template<> const float BookingClass::ExecutiveChairCar::sBlindConcessionFactor = 0.75;
template<> const float BookingClass::AC2Tier::sBlindConcessionFactor = 0.50;
template<> const float BookingClass::FirstClass::sBlindConcessionFactor = 0.75;
template<> const float BookingClass::AC3Tier::sBlindConcessionFactor = 0.75;
template<> const float BookingClass::ACChairCar::sBlindConcessionFactor = 0.75;
template<> const float BookingClass::Sleeper::sBlindConcessionFactor = 0.75;
template<> const float BookingClass::SecondSitting::sBlindConcessionFactor = 0.75;

template<> const float BookingClass::ACFirstClass::sOrthopaedicallyHandicappedConcessionFactor = 0.50;
template<> const float BookingClass::ExecutiveChairCar::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const float BookingClass::AC2Tier::sOrthopaedicallyHandicappedConcessionFactor = 0.50;
template<> const float BookingClass::FirstClass::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const float BookingClass::AC3Tier::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const float BookingClass::ACChairCar::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const float BookingClass::Sleeper::sOrthopaedicallyHandicappedConcessionFactor = 0.75;
template<> const float BookingClass::SecondSitting::sOrthopaedicallyHandicappedConcessionFactor = 0.75;

template<> const float BookingClass::ACFirstClass::sCancerPatientsConcessionFactor = 0.50;
template<> const float BookingClass::ExecutiveChairCar::sCancerPatientsConcessionFactor = 0.75;
template<> const float BookingClass::AC2Tier::sCancerPatientsConcessionFactor = 0.50;
template<> const float BookingClass::FirstClass::sCancerPatientsConcessionFactor = 0.75;
template<> const float BookingClass::AC3Tier::sCancerPatientsConcessionFactor = 1.00;
template<> const float BookingClass::ACChairCar::sCancerPatientsConcessionFactor = 1.00;
template<> const float BookingClass::Sleeper::sCancerPatientsConcessionFactor = 1.00;
template<> const float BookingClass::SecondSitting::sCancerPatientsConcessionFactor = 1.00;

template<> const float BookingClass::ACFirstClass::sTBPatientsConcessionFactor = 0.00;
template<> const float BookingClass::ExecutiveChairCar::sTBPatientsConcessionFactor = 0.00;
template<> const float BookingClass::AC2Tier::sTBPatientsConcessionFactor = 0.00;
template<> const float BookingClass::FirstClass::sTBPatientsConcessionFactor = 0.75;
template<> const float BookingClass::AC3Tier::sTBPatientsConcessionFactor = 0.00;
template<> const float BookingClass::ACChairCar::sTBPatientsConcessionFactor = 0.00;
template<> const float BookingClass::Sleeper::sTBPatientsConcessionFactor = 0.75;
template<> const float BookingClass::SecondSitting::sTBPatientsConcessionFactor = 0.75;

const float Ladies::sConcessionFactor = 0.00;
const float SeniorCitizen::sMaleConcessionFactor = 0.40;
const float SeniorCitizen::sFemaleConcessionFactor = 0.40;


/** \test
 * Test Application
 */
void BookingApplication() {
// Bookings by different booking classes
    Passenger pawan = Passenger::Construct(PassengerDetails::Name::Construct("Pawan", "Kumar"),
                                           Date::Construct(20, 11, 2001), Gender::Male::Type(),
                                           PassengerDetails::AadhaarNumber::Construct("111122223333"),
                                           PassengerDetails::PhoneNumber::Construct("9995123121"),
                                           &Divyaang::Blind::Type(), "55555444");

    const Booking &b1 = Booking::Construct(Station("Delhi"), Station("Mumbai"), Date::Construct(20, 8, 2021),
                                           BookingClass::AC3Tier::Type(), DivyaangCategory<Divyaang::Blind>::Type(),
                                           pawan);

    const Booking &b2 = Booking::Construct(Station("Delhi"), Station("Mumbai"), Date::Construct(20, 8, 2021),
                                           BookingClass::Sleeper::Type(), DivyaangCategory<Divyaang::Blind>::Type(),
                                           pawan);


//    Booking b1(Station("Mumbai"), Station("Delhi"), Date::Construct(15, 2, 2021), ACFirstClass::Type());
//    Booking b2(Station("Kolkata"), Station("Delhi"), Date::Construct(5, 3, 2021), AC2Tier::Type());
//    Booking b3(Station("Mumbai"), Station("Kolkata"), Date::Construct(17, 3, 2021), FirstClass::Type());
//    Booking b4(Station("Mumbai"), Station("Delhi"), Date::Construct(23, 3, 2021), AC3Tier::Type());
//    Booking b5(Station("Chennai"), Station("Delhi"), Date::Construct(25, 4, 2021), ACChairCar::Type());
//    Booking b6(Station("Chennai"), Station("Kolkata"), Date::Construct(7, 5, 2021), Sleeper::Type());
//    Booking b7(Station("Mumbai"), Station("Delhi"), Date::Construct(19, 5, 2021), SecondSitting::Type());
//    Booking b8(Station("Delhi"), Station("Mumbai"), Date::Construct(22, 5, 2021), SecondSitting::Type());

// Output the bookings done
    for (auto it : Booking::GetBookings()) {
        std::cout << *it << "\n";
    }

    Booking::ClearBookings();
}

int main() {
    BookingApplication();
    return 0;
}