/**
 * @file Passenger_test.cpp
 * @brief contains unit tests of Passenger class
 * @author Jayanth PSY - 19CS10068
 */

#include "gtest/gtest.h"

#include "Passenger.h"


TEST(PassengerDetails_test, ValidFullNameCheck) {
    EXPECT_NO_THROW(PassengerDetails::Name n = PassengerDetails::Name::Construct("Jayanth", "Phani Sai", "Yindukuri"));
}

TEST(PassengerDetails_test, FullNameCheck) {
    PassengerDetails::Name n = PassengerDetails::Name::Construct("Jayanth", "Phani Sai", "Yindukuri");
    EXPECT_EQ(n.firstName_, "Jayanth");
    EXPECT_EQ(n.middleName_, "Phani Sai");
    EXPECT_EQ(n.lastName_, "Yindukuri");
}

TEST(PassengerDetails_test, OnlyFirstNameCheck) {
    EXPECT_NO_THROW(PassengerDetails::Name::Construct("Jayanth"));
}

TEST(PassengerDetails_test, OnlyLastName) {
    EXPECT_NO_THROW(PassengerDetails::Name::Construct("", "", "Yindukuri"));
}

TEST(PassengerDetails_test, EmptyFirstAndLastNameCheck) {
    EXPECT_THROW(PassengerDetails::Name::Construct("", "Phani Sai"), Bad_Name);
}

TEST(PassengerDetails_test, ValidAadhaarCheck) {
    EXPECT_NO_THROW(PassengerDetails::AadhaarNumber::Construct("123456789012"));
}

TEST(PassengerDetails_test, NonNumericAadhaarCheck) {
    EXPECT_THROW(PassengerDetails::AadhaarNumber::Construct("1ABC56789012"), Bad_Aadhaar);
}

TEST(PassengerDetails_test, InvalidLengthAadhaarCheck) {
    EXPECT_THROW(PassengerDetails::AadhaarNumber::Construct("1112"), Bad_Aadhaar);
    EXPECT_THROW(PassengerDetails::AadhaarNumber::Construct("1234567890123456"), Bad_Aadhaar);
}

TEST(PassengerDetails_test, ValidPhoneNumberCheck) {
    EXPECT_NO_THROW(PassengerDetails::PhoneNumber::Construct("1234567890"));
}

TEST(PassengerDetails_test, NonNumericPhoneNumberCheck) {
    EXPECT_THROW(PassengerDetails::PhoneNumber::Construct("123456789A"), Bad_PhoneNumber);
}

TEST(PassengerDetails_test, InvalidLengthPhoneNumberCheck) {
    EXPECT_THROW(PassengerDetails::PhoneNumber::Construct("1112"), Bad_PhoneNumber);
    EXPECT_THROW(PassengerDetails::PhoneNumber::Construct("12345678900"), Bad_PhoneNumber);
}

TEST(Passenger_test, OnlyDivyaangCategoryCheck) {
    EXPECT_THROW(Passenger::Construct(PassengerDetails::Name::Construct("Name"),
                                      Date::Construct(20, 10, 2000),
                                      Gender::Male::Type(),
                                      PassengerDetails::AadhaarNumber::Construct("012345678912"),
                                      PassengerDetails::PhoneNumber::Construct("0123456789"),
                                      &Divyaang::Blind::Type()), Bad_Passenger);
}

TEST(Passenger_test, OnlyDivyaangIDCheck) {
    EXPECT_THROW(Passenger::Construct(PassengerDetails::Name::Construct("Name"),
                                      Date::Construct(20, 10, 2000),
                                      Gender::Female::Type(),
                                      PassengerDetails::AadhaarNumber::Construct("012345678912"),
                                      PassengerDetails::PhoneNumber::Construct("0123456789"),
                                      nullptr, "DivyaangID"), Bad_Passenger);
}

TEST(Passenger_test, NoDivyaangCheck) {
    EXPECT_NO_THROW(Passenger p = Passenger::Construct(PassengerDetails::Name::Construct("Jayanth"),
                                                       Date::Construct(20, 10, 2000),
                                                       Gender::Male::Type(),
                                                       PassengerDetails::AadhaarNumber::Construct("012345678912"),
                            PassengerDetails::PhoneNumber::Construct("0123456789")));
}

TEST(Passenger_test, ValidDivyaangCheck) {
    EXPECT_NO_THROW(Passenger p = Passenger::Construct(PassengerDetails::Name::Construct("Someone", "Middle name"),
                                                       Date::Construct(20, 10, 2000),
                                                       Gender::Female::Type(),
                                                       PassengerDetails::AadhaarNumber::Construct("012345678912"),
                                                       PassengerDetails::PhoneNumber::Construct("0123456789"),
                            &Divyaang::CancerPatients::Type(), "divyaang123"));
}

