//
// Created by j-tesla on 02/03/21.
//

#include "gtest/gtest.h"
#include "Station.h"


// tests whether name is saved properly
TEST(Station, NameCheck) {
    Station kolkata = Station("Kolkata");
    ASSERT_EQ(kolkata.GetName(), "Kolkata");
}