/**
 * @file Station_test.cpp
 * @brief contains unit tests of Station class
 * @author Jayanth PSY - 19CS10068
 */


#include "gtest/gtest.h"

#include "Station.h"


/** \test
 * tests whether name is saved properly
 */
TEST(Station_test, NameCheck) {
    Station kolkata = Station("Kolkata");
    EXPECT_EQ(kolkata.GetName(), "Kolkata");
}

/** \test
 * checks equality of two objects
 */
TEST(Station_test, EqualityCheck) {
    Station k("Kolkata");
    Station k_("Kolkata");
    Station d("Delhi");

    EXPECT_EQ(k, k_);
    EXPECT_FALSE(k == d);
}