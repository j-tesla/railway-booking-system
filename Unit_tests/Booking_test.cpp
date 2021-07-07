/**
 * @file Booking_test.cpp
 * @brief contains unit tests of Booking class
 * @author Jayanth PSY - 19CS10068
 */


#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Booking.h"


const Date dateOfReservation(10, 10, 2020);
const Date dateOfBooking(dateOfReservation.GetDay(), dateOfReservation.GetMonth() + 1, dateOfReservation.GetYear());
const Date twentytwo_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 22);
const Date ninty_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 90);
const Date fiftynine_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 59);
const Date sixtyone_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 61);
const Date fiftyeight_yrs(dateOfReservation.GetDay(), dateOfReservation.GetMonth(), dateOfReservation.GetYear() - 58);


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


const Booking &b1 = Booking::Construct(Station("Kolkata"), Station("Delhi"), dateOfBooking,
                                       BookingClass::Sleeper::Type(), General::Type(), man, dateOfReservation);
const Booking &b2 = Booking::Construct(Station("Chennai"), Station("Delhi"), dateOfBooking,
                                       BookingClass::ExecutiveChairCar::Type(), General::Type(), lady,
                                       dateOfReservation);
const Booking &b3 = Booking::Construct(Station("Kolkata"), Station("Mumbai"), dateOfBooking,
                                       BookingClass::ACChairCar::Type(), SeniorCitizen::Type(), oldLady,
                                       dateOfReservation);

/** \test
 * checks PNR sequence
 */
TEST(Booking_test, PNRSequenceCheck) {
    EXPECT_EQ(b1.GetPNR(), 1);
    EXPECT_EQ(b2.GetPNR(), 2);
    EXPECT_EQ(b3.GetPNR(), 3);
}


/** \test
 * checks number of bookings active
 */
TEST(Booking_test, BookingsCountIncrementCheck) {
    auto initial = Booking::GetBookings().size();
    const Booking &bx = Booking::Construct(Station("Chennai"), Station("Delhi"), dateOfBooking,
                                           BookingClass::AC2Tier::Type(), SeniorCitizen::Type(), oldMan,
                                           dateOfReservation);
    EXPECT_EQ(Booking::GetBookings().size(), initial + 1);
}

/** \test
 * checks whether booking status is always true
 */
TEST(Booking_test, BookingStatusCheck) {
    EXPECT_EQ(b1.GetBookingStatus(), true);
    EXPECT_EQ(b2.GetBookingStatus(), true);
    EXPECT_EQ(b3.GetBookingStatus(), true);
}


/** \test
 * checks to stations_
 */
TEST(Booking_test, ToStationCheck) {
    EXPECT_EQ(b1.GetToStation(), Station("Delhi"));
    EXPECT_EQ(b2.GetToStation(), Station("Delhi"));
    EXPECT_EQ(b3.GetToStation(), Station("Mumbai"));
}

/** \test
 * checks from stations_
 */
TEST(Booking_test, FromStationCheck) {
    EXPECT_EQ(b1.GetFromStation(), Station("Kolkata"));
    EXPECT_EQ(b2.GetFromStation(), Station("Chennai"));
    EXPECT_EQ(b3.GetFromStation(), Station("Kolkata"));
}

/** \test
 * checks fares
 * depends on initialised const values
 */
TEST(Booking_test, FareCheck) {
    EXPECT_EQ(b1.ComputeFare(), 756);
    EXPECT_EQ(b2.ComputeFare(), 5510);
    EXPECT_EQ(b3.ComputeFare(), 1248);
}

/** \test
 * checks format of ostream << overload
 */
TEST(Booking_test, OstreamFormatCheck) {
    std::stringstream buffer;
    std::string line;
    buffer << b1;

    getline(buffer, line);
    EXPECT_EQ(line, "BOOKING SUCCEEDED:");

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(PNR Number = [0-9]+)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(From Station = .+)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(To Station = .+)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(Travel Date = .+)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(Travel Class = .+)"));
    getline(buffer, line);
    getline(buffer, line);
    getline(buffer, line);
    getline(buffer, line);

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(Booking Category = .+)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(Fare = [0-9]+)"));
}

TEST(Booking_test, InvalidStationCheck) {
    EXPECT_THROW(Booking::Construct(Station("Wrong"), Station("Kolkata"), dateOfBooking, BookingClass::AC2Tier::Type(),
                                    General::Type(), man, dateOfReservation), Bad_Booking);
    EXPECT_THROW(
            Booking::Construct(Station("Chennai"), Station("Wrong"), dateOfBooking, BookingClass::ACChairCar::Type(),
                               General::Type(), oldLady, dateOfReservation), Bad_Booking);
}

TEST(Booking_test, IneligiblePassengerCheck) {
    EXPECT_THROW(Booking::Construct(Station("Wrong"), Station("Kolkata"), dateOfBooking, BookingClass::AC2Tier::Type(),
                                    SeniorCitizen::Type(), man, dateOfReservation), Bad_Booking);
}

TEST(Booking_test, PastBookingDateCheck) {
    EXPECT_THROW(Booking::Construct(Station("Wrong"), Station("Kolkata"), dateOfReservation, BookingClass::AC2Tier::Type(),
                                    SeniorCitizen::Type(), man, dateOfBooking), Bad_Booking);
}

TEST(Booking_test, MoreThanAfterOneYearBookingDateCheck) {
    EXPECT_THROW(Booking::Construct(Station("Wrong"), Station("Kolkata"), Date::Construct(10, 10, dateOfReservation.GetYear() + 2), BookingClass::AC2Tier::Type(),
                                    SeniorCitizen::Type(), man, dateOfReservation), Bad_Booking);
}

