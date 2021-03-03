//
// Created by j-tesla on 03/03/21.
//

#include "gtest/gtest.h"
#include "Railways.h"

// check whether distance between stations is symmetric
TEST(Railways, DistanceSymmetry) {
    EXPECT_EQ(Railways::IndianRailways().GetDistance("Kolkata", "Mumbai"),
              Railways::IndianRailways().GetDistance("Mumbai", "Kolkata"));
    EXPECT_EQ(Railways::IndianRailways().GetDistance(Station("Kolkata"), Station("Mumbai")),
              Railways::IndianRailways().GetDistance(Station("Mumbai"), Station("Kolkata")));
}