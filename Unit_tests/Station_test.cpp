//
// Created by j-tesla on 02/03/21.
//

#include "gtest/gtest.h"

#include "Station.h"


// tests whether name is saved properly
TEST(Station_test, NameCheck) {
    Station kolkata = Station("Kolkata");
    EXPECT_EQ(kolkata.GetName(), "Kolkata");
}

// checks equality of two objects
TEST(Station_test, EqualityCheck) {
    Station k("Kolkata");
    Station k_("Kolkata");
    Station d("Delhi");

    EXPECT_EQ(k, k_);
    EXPECT_FALSE(k == d);
}