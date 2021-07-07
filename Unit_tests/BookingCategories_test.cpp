/**
 * @file BookingCategories_test.cpp
 * @brief contains unit tests of base classes in BookingCategories.h
 * @author Jayanth PSY - 19CS10068
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BookingCategories.h"


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
                                                      validPhoneNumber, &Divyaang::CancerPatients::Type(), "cancer-patient-id");

TEST(General_test, EligiblePassengerCheck) {
    EXPECT_TRUE(General::Type().IsEligible(man, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(General::Type().IsEligible(lady, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(General::Type().IsEligible(oldMan, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(General::Type().IsEligible(oldLady, dateOfBooking, dateOfReservation));
}

TEST(Ladies_test, EligiblePassengerCheck) {
    EXPECT_FALSE(Ladies::Type().IsEligible(man, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(Ladies::Type().IsEligible(lady, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(Ladies::Type().IsEligible(oldMan, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(Ladies::Type().IsEligible(oldLady, dateOfBooking, dateOfReservation));
}

TEST(Priority_test, OnedayEligibilityCheck) {
    EXPECT_TRUE(Tatkal::Type().IsEligible(lady,
                                          Date::Construct(dateOfReservation.GetDay() + 1, dateOfReservation.GetMonth(),
                                                          dateOfReservation.GetYear()), dateOfReservation));
    EXPECT_FALSE(Tatkal::Type().IsEligible(lady, dateOfBooking, dateOfReservation));
}

TEST(SeniorCitizen_test, EligiblePassengerCheck) {
    const Passenger justOldMan = Passenger::Construct(validName, sixtyone_yrs, Gender::Male::Type(), validAadhaar,
                                                      validPhoneNumber);
    const Passenger justOldLady = Passenger::Construct(validName, fiftynine_yrs, Gender::Female::Type(), validAadhaar,
                                                       validPhoneNumber);
    EXPECT_TRUE(SeniorCitizen::Type().IsEligible(oldMan, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(SeniorCitizen::Type().IsEligible(oldLady, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(SeniorCitizen::Type().IsEligible(justOldMan, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(SeniorCitizen::Type().IsEligible(justOldLady, dateOfBooking, dateOfReservation));
}

TEST(SeniorCitizen_test, IneligiblePassengerCheck) {
    const Passenger justYoungMan = Passenger::Construct(validName, fiftynine_yrs, Gender::Male::Type(), validAadhaar,
                                                        validPhoneNumber);
    const Passenger justYoungLady = Passenger::Construct(validName, fiftyeight_yrs, Gender::Female::Type(),
                                                         validAadhaar, validPhoneNumber);

    EXPECT_FALSE(SeniorCitizen::Type().IsEligible(man, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(SeniorCitizen::Type().IsEligible(lady, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(SeniorCitizen::Type().IsEligible(justYoungMan, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(SeniorCitizen::Type().IsEligible(justYoungLady, dateOfBooking, dateOfReservation));
}

TEST(DivyaangCategory_test, EligiblePassengerCheck) {
    EXPECT_TRUE(DivyaangCategory<Divyaang::Blind>::Type().IsEligible(blind, dateOfBooking, dateOfReservation));
    EXPECT_TRUE(DivyaangCategory<Divyaang::CancerPatients>::Type().IsEligible(cancer_patient, dateOfBooking, dateOfReservation));
}

TEST(DivyaangCategory_test, WrongDisabilityPassengerCheck) {
    EXPECT_FALSE(DivyaangCategory<Divyaang::CancerPatients>::Type().IsEligible(blind, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(DivyaangCategory<Divyaang::Blind>::Type().IsEligible(cancer_patient, dateOfBooking, dateOfReservation));
}

TEST(DivyaangCategory_test, AbledPassengerCheck) {
    EXPECT_FALSE(DivyaangCategory<Divyaang::CancerPatients>::Type().IsEligible(man, dateOfBooking, dateOfReservation));
    EXPECT_FALSE(DivyaangCategory<Divyaang::Blind>::Type().IsEligible(oldLady, dateOfBooking, dateOfReservation));
}
