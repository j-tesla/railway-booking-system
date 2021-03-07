/**
 * @file Booking_test.cpp
 * @brief contains unit tests of Booking class
 * @author Jayanth PSY - 19CS10068
 */


#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Booking.h"


/** \class test fixture
 * fixture for Booking_test test suite
 */
class Booking_test : public ::testing::Test {
protected:
    // setup code for the test suite
    static void SetUpTestSuite() {
        b1 = new Booking(Station("Mumbai"), Station("Chennai"), Date(5, 5, 2021), ACChairCar::Type());
        b1_ = new Booking(Station("Mumbai"), Station("Chennai"), Date(5, 6, 2020), ACChairCar::Type());
        b2 = new Booking(Station("Kolkata"), Station("Chennai"), Date(6, 5, 2021), Sleeper::Type());
    }

    static void TearDownTestSuite() {
        delete b1;
        delete b1_;
        delete b2;
        b1 = b1_ = b2 = nullptr;
    }

    static const Booking *b1;
    static const Booking *b1_;
    static const Booking *b2;
};

const Booking *Booking_test::b1 = nullptr;
const Booking *Booking_test::b1_ = nullptr;
const Booking *Booking_test::b2 = nullptr;


/** \test
 * checks PNR sequence
 */
TEST_F(Booking_test, PNRSequenceCheck) {
    EXPECT_EQ(b1->GetPNR(), 1);
    EXPECT_EQ(b1_->GetPNR(), 2);
    EXPECT_EQ(b2->GetPNR(), 3);
}

/** \test
 * checks fare's independence of date
 */
TEST_F(Booking_test, DateIndependanceCheck) {
    EXPECT_EQ(b1->ComputeFare(), b1_->ComputeFare());
}

/** \test
 * checks number of bookings active
 */
TEST_F(Booking_test, BookingsCheck) {
    EXPECT_EQ(Booking::GetBookings().size(), 3);        // 3 bookings in Fixture
    {
        Booking bx(Station("Chennai"), Station("Delhi"), Date(2, 1, 2022), AC2Tier::Type());
        EXPECT_EQ(Booking::GetBookings().size(), 4);        // 3 + 1 bookings
    }
    EXPECT_EQ(Booking::GetBookings().size(), 3);        // 4 - 1 bookings (last booking went out of scope)
}

/** \test
 * checks whether booking status is always true
 */
TEST_F(Booking_test, BookingStatusCheck) {
    EXPECT_EQ(b1->GetBookingStatus(), true);
    EXPECT_EQ(b1_->GetBookingStatus(), true);
    EXPECT_EQ(b2->GetBookingStatus(), true);
}

/** \test
 * checks booking classes
 */
TEST_F(Booking_test, BookingClassCheck) {
    EXPECT_EQ(b1->GetBookingClass(), ACChairCar::Type());
    EXPECT_EQ(b1_->GetBookingClass(), ACChairCar::Type());
    EXPECT_EQ(b2->GetBookingClass(), Sleeper::Type());
}

/** \test
 * checks to stations
 */
TEST_F(Booking_test, ToStationCheck) {
    EXPECT_EQ(b1->GetToStation(), Station("Chennai"));
    EXPECT_EQ(b1_->GetToStation(), Station("Chennai"));
    EXPECT_EQ(b2->GetToStation(), Station("Chennai"));
}

/** \test
 * checks from stations
 */
TEST_F(Booking_test, FromStationCheck) {
    EXPECT_EQ(b1->GetFromStation(), Station("Mumbai"));
    EXPECT_EQ(b1_->GetFromStation(), Station("Mumbai"));
    EXPECT_EQ(b2->GetFromStation(), Station("Kolkata"));
}

/** \test
 * checks for passenger being null
 */
TEST_F(Booking_test, NullPassengerCheck) {
    EXPECT_EQ(b1->GetPassenger(), nullptr);
    EXPECT_EQ(b1_->GetPassenger(), nullptr);
    EXPECT_EQ(b2->GetPassenger(), nullptr);
}

/** \test
 * checks dates
 */
TEST_F(Booking_test, DateCheck) {
    EXPECT_EQ(b1->GetDate(), Date(5, 5, 2021));
    EXPECT_EQ(b1_->GetDate(), Date(5, 6, 2020));
    EXPECT_EQ(b2->GetDate(), Date(6, 5, 2021));
}

/** \test
 * checks fares
 * depends on initialised const values
 */
TEST_F(Booking_test, FareCheck) {
    EXPECT_EQ(b1->ComputeFare(), 886);
    EXPECT_EQ(b2->ComputeFare(), 830);
}

/** \test
 * checks format of ostream << overload
 */
TEST_F(Booking_test, OstreamFormatCheck) {
    std::stringstream buffer;
    std::string line;
    buffer << *b1;

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
    EXPECT_THAT(line, testing::MatchesRegex(R"(Fare = [0-9]+)"));
}