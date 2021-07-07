/**
 * @file BookingClasses_test.cpp
 * @brief contains unit tests of base classes in BookingClasses.h
 * @author Jayanth PSY - 19CS10068
 */


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BookingClasses.h"


/** \test
 * checks names of the classes
 */
TEST(BookingClasses_test, NameCheck) {
    EXPECT_EQ(BookingClass::ACFirstClass::Type().GetName(), "AC First Class");
    EXPECT_EQ(BookingClass::AC2Tier::Type().GetName(), "AC 2 Tier");
    EXPECT_EQ(BookingClass::FirstClass::Type().GetName(), "First Class");
    EXPECT_EQ(BookingClass::AC3Tier::Type().GetName(), "AC 3 Tier");
    EXPECT_EQ(BookingClass::ACChairCar::Type().GetName(), "AC Chair Car");
    EXPECT_EQ(BookingClass::Sleeper::Type().GetName(), "Sleeper");
    EXPECT_EQ(BookingClass::SecondSitting::Type().GetName(), "Second Sitting");
}

/** \test
 * checks number of tiers of classes
 */
TEST(BookingClasses_test, NumberOfTiersCheck) {
    EXPECT_EQ(BookingClass::Sleeper::Type().GetNumberOfTiers(), 3);
    EXPECT_EQ(BookingClass::SecondSitting::Type().GetNumberOfTiers(), 0);
}

/** \test
 * checks format of ostream << overload output
 */
TEST(BookingClasses_test, OstreamFormatCheck) {
    std::stringstream buffer;
    buffer << BookingClass::ACFirstClass::Type();
    std::string line;
    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(.*)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Mode: (Sitting|Sleeping))"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - AC: (Yes)|(No))"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Bunks: [0-9]*)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Luxury: (Yes)|(No))"));
}
