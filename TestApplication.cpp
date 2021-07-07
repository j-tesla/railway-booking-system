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


    const Date dateOfReservation(10, 10, 2020);
    const Date dateOfBooking(dateOfReservation.GetDay(), dateOfReservation.GetMonth() + 1, dateOfReservation.GetYear());
    const Date twentytwo_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(),
                             dateOfReservation.GetYear() - 22);
    const Date ninty_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 90);
    const Date fiftynine_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(),
                             dateOfReservation.GetYear() - 59);
    const Date sixtyone_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 61);
    const Date fiftyeight_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(),
                              dateOfReservation.GetYear() - 58);


    const PassengerDetails::Name validName = PassengerDetails::Name::Construct("Valid", "Name");
    const PassengerDetails::AadhaarNumber validAadhaar = PassengerDetails::AadhaarNumber::Construct("123456789012");
    const PassengerDetails::PhoneNumber validPhoneNumber = PassengerDetails::PhoneNumber::Construct("1023456789");

    const Passenger man = Passenger::Construct(validName, twentytwo_yrs, Gender::Male::Type(), validAadhaar,
                                               validPhoneNumber);
    const Passenger lady = Passenger::Construct(validName, twentytwo_yrs, Gender::Female::Type(), validAadhaar,
                                                validPhoneNumber);
    const Passenger oldMan = Passenger::Construct(validName, ninty_yrs, Gender::Male::Type(), validAadhaar,
                                                  validPhoneNumber);
    const Passenger oldLady = Passenger::Construct(validName, ninty_yrs, Gender::Female::Type(), validAadhaar,
                                                   validPhoneNumber);
    const Passenger blind = Passenger::Construct(validName, twentytwo_yrs, Gender::Male::Type(), validAadhaar,
                                                 validPhoneNumber, &Divyaang::Blind::Type(), "blind-id");
    const Passenger cancer_patient = Passenger::Construct(validName, twentytwo_yrs, Gender::Male::Type(), validAadhaar,
                                                          validPhoneNumber, &Divyaang::CancerPatients::Type(),
                                                          "cancer-patient-id");

    Passenger pawan = Passenger::Construct(PassengerDetails::Name::Construct("Pawan", "Kumar"),
                                           Date::Construct(20, 11, 2001), Gender::Male::Type(),
                                           PassengerDetails::AadhaarNumber::Construct("111122223333"),
                                           PassengerDetails::PhoneNumber::Construct("9995123121"),
                                           &Divyaang::Blind::Type(), "55555444");

    const Booking &b1 = Booking::Construct(Station("Delhi"), Station("Mumbai"), Date::Construct(20, 8, 2021),
                                           BookingClass::AC3Tier::Type(), DivyaangCategory<Divyaang::Blind>::Type(),
                                           pawan, dateOfReservation);

    const Booking &b2 = Booking::Construct(Station("Delhi"), Station("Mumbai"), Date::Construct(20, 8, 2021),
                                           BookingClass::Sleeper::Type(), DivyaangCategory<Divyaang::Blind>::Type(),
                                           pawan, dateOfReservation);
    const Booking &b3 = Booking::Construct(Station("Kolkata"), Station("Delhi"), dateOfBooking,
                                           BookingClass::FirstClass::Type(), General::Type(), man, dateOfReservation);
    const Booking &b4 = Booking::Construct(Station("Chennai"), Station("Delhi"), dateOfBooking,
                                           BookingClass::ExecutiveChairCar::Type(), General::Type(), lady,
                                           dateOfReservation);
    const Booking &b5 = Booking::Construct(Station("Kolkata"), Station("Mumbai"), dateOfBooking,
                                           BookingClass::ACChairCar::Type(), SeniorCitizen::Type(), oldLady,
                                           dateOfReservation);

    try {
        Booking::Construct(Station("Wrong"), Station("Kolkata"), dateOfBooking, BookingClass::AC2Tier::Type(),
                           General::Type(), man, dateOfReservation);
    } catch (Bad_Booking &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Booking::Construct(Station("Wrong"), Station("Kolkata"), dateOfBooking, BookingClass::AC2Tier::Type(),
                           SeniorCitizen::Type(), man, dateOfReservation);
    } catch (Bad_Booking &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Passenger::Construct(PassengerDetails::Name::Construct("Name"),
                             Date::Construct(20, 10, 2000),
                             Gender::Female::Type(),
                             PassengerDetails::AadhaarNumber::Construct("012345678912"),
                             PassengerDetails::PhoneNumber::Construct("0123456789"),
                             nullptr, "DivyaangID");
    } catch (Bad_Passenger &e) {
        std::cout << e.what() << std::endl;
    }


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