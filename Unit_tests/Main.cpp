/**
 * @file Main.cpp
 * @brief runs all the unit tests
 * @author Jayanth PSY - 19CS10068
 */

#include <iostream>

#include "gtest/gtest.h"

#include "Booking.h"


// consts initialisations
const float ACFirstClass::sLoadFactor = 3.00;
const float AC2Tier::sLoadFactor = 2.00;
const float FirstClass::sLoadFactor = 2.00;
const float AC3Tier::sLoadFactor = 1.75;
const float ACChairCar::sLoadFactor = 1.25;
const float Sleeper::sLoadFactor = 1.00;
const float SecondSitting::sLoadFactor = 0.50;

const bool ACFirstClass::sIsLuxury = true;
const bool AC2Tier::sIsLuxury = false;
const bool FirstClass::sIsLuxury = true;
const bool AC3Tier::sIsLuxury = false;
const bool ACChairCar::sIsLuxury = false;
const bool Sleeper::sIsLuxury = false;
const bool SecondSitting::sIsLuxury = false;

const float Booking::sBaseFareRate = 0.50; // Rs/km
// Rs


/**
 * Initialises Google tests and runs all the tests
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    std::cout << "Running main() for tests from " << __FILE__ << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}