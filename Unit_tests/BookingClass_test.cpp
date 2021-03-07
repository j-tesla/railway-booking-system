/**
 * @file BookingClasses_test.cpp
 * @brief contains unit tests of base classes in BookingClass.h
 * @author Jayanth PSY - 19CS10068
 */


#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BookingClass.h"


/** \test
 * checks names of the classes
 */
TEST(BookingClasses_test, NameCheck) {
    EXPECT_EQ(ACFirstClass::Type().GetName(), "AC First Class");
    EXPECT_EQ(AC2Tier::Type().GetName(), "AC 2 Tier");
    EXPECT_EQ(FirstClass::Type().GetName(), "First Class");
    EXPECT_EQ(AC3Tier::Type().GetName(), "AC 3 Tier");
    EXPECT_EQ(ACChairCar::Type().GetName(), "AC Chair Car");
    EXPECT_EQ(Sleeper::Type().GetName(), "Sleeper");
    EXPECT_EQ(SecondSitting::Type().GetName(), "Second Sitting");
}

/** \test
 * checks Ac property of classes
 */
TEST(BookingClasses_test, IsACCheck) {
    EXPECT_EQ(ACFirstClass::Type().IsAc(), true);
    EXPECT_EQ(AC2Tier::Type().IsAc(), true);
    EXPECT_EQ(FirstClass::Type().IsAc(), false);
    EXPECT_EQ(AC3Tier::Type().IsAc(), true);
    EXPECT_EQ(ACChairCar::Type().IsAc(), true);
    EXPECT_EQ(Sleeper::Type().IsAc(), false);
    EXPECT_EQ(SecondSitting::Type().IsAc(), false);
}

/** \test
 * checks Ac property of classes
 */
TEST(BookingClasses_test, IsSittingCheck) {
    EXPECT_EQ(ACFirstClass::Type().IsSitting(), false);
    EXPECT_EQ(AC2Tier::Type().IsSitting(), false);
    EXPECT_EQ(FirstClass::Type().IsSitting(), false);
    EXPECT_EQ(AC3Tier::Type().IsSitting(), false);
    EXPECT_EQ(ACChairCar::Type().IsSitting(), true);
    EXPECT_EQ(Sleeper::Type().IsSitting(), false);
    EXPECT_EQ(SecondSitting::Type().IsSitting(), true);
}

/** \test
 * checks luxury status of classes
 * depends on initialised const values
 */
TEST(BookingClasses_test, IsLuxuryCheck) {
    EXPECT_EQ(ACFirstClass::Type().IsLuxury(), true);
    EXPECT_EQ(AC2Tier::Type().IsLuxury(), false);
    EXPECT_EQ(FirstClass::Type().IsLuxury(), true);
    EXPECT_EQ(AC3Tier::Type().IsLuxury(), false);
    EXPECT_EQ(ACChairCar::Type().IsLuxury(), false);
    EXPECT_EQ(Sleeper::Type().IsLuxury(), false);
    EXPECT_EQ(SecondSitting::Type().IsLuxury(), false);
}

/** \test
 * checks number of tiers of classes
 */
TEST(BookingClasses_test, NumberOfTiersCheck) {
    EXPECT_EQ(ACFirstClass::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(AC2Tier::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(FirstClass::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(AC3Tier::Type().GetNumberOfTiers(), 3);
    EXPECT_EQ(ACChairCar::Type().GetNumberOfTiers(), 0);
    EXPECT_EQ(Sleeper::Type().GetNumberOfTiers(), 3);
    EXPECT_EQ(SecondSitting::Type().GetNumberOfTiers(), 0);
}

/** \test
 * checks load factor
 * depends on initialised const values
 */
TEST(BookingClasses_test, LoadFactorCheck) {
    EXPECT_FLOAT_EQ(ACFirstClass::Type().GetLoadFactor(), 3.00);
    EXPECT_FLOAT_EQ(AC2Tier::Type().GetLoadFactor(), 2.00);
    EXPECT_FLOAT_EQ(FirstClass::Type().GetLoadFactor(), 2.00);
    EXPECT_FLOAT_EQ(AC3Tier::Type().GetLoadFactor(), 1.75);
    EXPECT_FLOAT_EQ(ACChairCar::Type().GetLoadFactor(), 1.25);
    EXPECT_FLOAT_EQ(Sleeper::Type().GetLoadFactor(), 1.00);
    EXPECT_FLOAT_EQ(SecondSitting::Type().GetLoadFactor(), 0.50);
}

/** \test
 * checks format of ostream << overload output
 */
TEST(BookingClasses_test, OstreamFormatCheck) {
    std::stringstream buffer;
    buffer << ACFirstClass::Type();
    std::string line;
    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(Travel Class = .*)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Mode: (Sitting|Sleeping))"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - AC: (Yes)|(No))"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Bunks: [0-9]*)"));

    getline(buffer, line);
    EXPECT_THAT(line, testing::MatchesRegex(R"(  - Luxury: (Yes)|(No))"));
}
