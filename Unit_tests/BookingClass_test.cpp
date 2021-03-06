//
// Created by j-tesla on 03/03/21.
//

#include "gtest/gtest.h"
#include "BookingClass.h"


TEST(BookingClasses_test, NameCheck) {
    EXPECT_EQ(ACFirstClass::Type().GetName(), "AC First Class");
    EXPECT_EQ(AC2Tier::Type().GetName(), "AC 2 Tier");
    EXPECT_EQ(FirstClass::Type().GetName(), "First Class");
    EXPECT_EQ(AC3Tier::Type().GetName(), "AC 3 Tier");
    EXPECT_EQ(ACChairCar::Type().GetName(), "AC Chair Car");
    EXPECT_EQ(Sleeper::Type().GetName(), "Sleeper");
    EXPECT_EQ(SecondSitting::Type().GetName(), "Second Sitting");
}

TEST(BookingClasses_test, IsACCheck) {
    EXPECT_EQ(ACFirstClass::Type().IsAc(), true);
    EXPECT_EQ(AC2Tier::Type().IsAc(), true);
    EXPECT_EQ(FirstClass::Type().IsAc(), false);
    EXPECT_EQ(AC3Tier::Type().IsAc(), true);
    EXPECT_EQ(ACChairCar::Type().IsAc(), true);
    EXPECT_EQ(Sleeper::Type().IsAc(), false);
    EXPECT_EQ(SecondSitting::Type().IsAc(), false);
}

TEST(BookingClasses_test, IsLuxuryCheck) {
    EXPECT_EQ(ACFirstClass::Type().IsLuxury(), true);
    EXPECT_EQ(AC2Tier::Type().IsLuxury(), false);
    EXPECT_EQ(FirstClass::Type().IsLuxury(), true);
    EXPECT_EQ(AC3Tier::Type().IsLuxury(), false);
    EXPECT_EQ(ACChairCar::Type().IsLuxury(), false);
    EXPECT_EQ(Sleeper::Type().IsLuxury(), false);
    EXPECT_EQ(SecondSitting::Type().IsLuxury(), false);
}

TEST(BookingClasses_test, NumberOfTiersCheck) {
    EXPECT_EQ(ACFirstClass::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(AC2Tier::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(FirstClass::Type().GetNumberOfTiers(), 2);
    EXPECT_EQ(AC3Tier::Type().GetNumberOfTiers(), 3);
    EXPECT_EQ(ACChairCar::Type().GetNumberOfTiers(), 0);
    EXPECT_EQ(Sleeper::Type().GetNumberOfTiers(), 3);
    EXPECT_EQ(SecondSitting::Type().GetNumberOfTiers(), 0);
}

TEST(BookingClasses_test, DefaultLoadFactor) {
    EXPECT_FLOAT_EQ(ACFirstClass::Type().GetLoadFactor(), 3.00);
    EXPECT_FLOAT_EQ(AC2Tier::Type().GetLoadFactor(), 2.00);
    EXPECT_FLOAT_EQ(FirstClass::Type().GetLoadFactor(), 2.00);
    EXPECT_FLOAT_EQ(AC3Tier::Type().GetLoadFactor(), 1.75);
    EXPECT_FLOAT_EQ(ACChairCar::Type().GetLoadFactor(), 1.25);
    EXPECT_FLOAT_EQ(Sleeper::Type().GetLoadFactor(), 1.00);
    EXPECT_FLOAT_EQ(SecondSitting::Type().GetLoadFactor(), 0.50);
}
