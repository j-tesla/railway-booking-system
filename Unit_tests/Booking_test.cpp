//
// Created by j-tesla on 04/03/21.
//

#include "gtest/gtest.h"
#include "Booking.h"


class BookingClass_test : public ::testing::Test {
protected:
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

const Booking *BookingClass_test::b1 = nullptr;
const Booking *BookingClass_test::b1_ = nullptr;
const Booking *BookingClass_test::b2 = nullptr;

TEST_F(BookingClass_test, PNRSequenceCheck) {
    EXPECT_EQ(b1->GetPNR(), 1);
    EXPECT_EQ(b1_->GetPNR(), 2);
    EXPECT_EQ(b2->GetPNR(), 3);
}

TEST_F(BookingClass_test, DateIndependanceCheck) {
    EXPECT_EQ(b1->ComputeFare(), b1_->ComputeFare());
}

TEST_F(BookingClass_test, BookingsCheck) {
    EXPECT_EQ(Booking::GetBookings().size(), 3);
    {
        Booking bx(Station("Chennai"), Station("Delhi"), Date(2, 1, 2022), AC2Tier::Type());
        EXPECT_EQ(Booking::GetBookings().size(), 4);
    }
    EXPECT_EQ(Booking::GetBookings().size(), 3);
}

TEST_F(BookingClass_test, BookingStatusCheck) {
    EXPECT_EQ(b1->GetBookingStatus(), true);
    EXPECT_EQ(b1_->GetBookingStatus(), true);
    EXPECT_EQ(b2->GetBookingStatus(), true);
}

TEST_F(BookingClass_test, BookingClassCheck) {
    EXPECT_EQ(b1->GetBookingClass(), ACChairCar::Type());
    EXPECT_EQ(b1_->GetBookingClass(), ACChairCar::Type());
    EXPECT_EQ(b2->GetBookingClass(), Sleeper::Type());
}

TEST_F(BookingClass_test, FareCheck) {
    EXPECT_EQ(b1->ComputeFare(), 886);
    EXPECT_EQ(b2->ComputeFare(), 830);
}