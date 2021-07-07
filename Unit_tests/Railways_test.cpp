/**
 * @file Railways_test.cpp
 * @brief contains unit tests of Railways class
 * @author Jayanth PSY - 19CS10068
 */


#include "gtest/gtest.h"

#include "Railways.h"


/** \test
 * checks whether distance between stations_ is symmetric
 */
TEST(Railways_test, DistanceSymmetry) {
    EXPECT_EQ(Railways::IndianRailways().GetDistance("Kolkata", "Mumbai"),
              Railways::IndianRailways().GetDistance("Mumbai", "Kolkata"));
    EXPECT_EQ(Railways::IndianRailways().GetDistance(Station("Kolkata"), Station("Mumbai")),
              Railways::IndianRailways().GetDistance(Station("Mumbai"), Station("Kolkata")));
}

TEST(Railways_test, InvalidStation) {
    EXPECT_FALSE(Railways::IndianRailways().ValidStation(Station("Not a Valid Station")));
}

TEST(Railways_test, ValidStation) {
    EXPECT_TRUE(Railways::IndianRailways().ValidStation(Station("Kolkata")));
}
