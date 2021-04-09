/**
 * @file BookingClass.cpp
 * @brief contains implementations and definitions of abstract class BookingClass and base classes
 * @author Jayanth PSY - 19CS10068
 */


#include "BookingClasses.h"


BookingClass::BookingClass() = default;


template<> const string BookingClass::ACFirstClass::sName = "AC First Class";
template<> const string BookingClass::ExecutiveChairCar::sName = "Executive Chair Car";
template<> const string BookingClass::AC2Tier::sName = "AC 2 Tier";
template<> const string BookingClass::FirstClass::sName = "First Class";
template<> const string BookingClass::AC3Tier::sName = "AC 3 Tier";
template<> const string BookingClass::ACChairCar::sName = "AC Chair Car";
template<> const string BookingClass::Sleeper::sName = "Sleeper";
template<> const string BookingClass::SecondSitting::sName = "Second Sitting";


template<> const bool BookingClass::ACFirstClass::sIsSeating = false;
template<> const bool BookingClass::ExecutiveChairCar::sIsSeating = true;
template<> const bool BookingClass::AC2Tier::sIsSeating = false;
template<> const bool BookingClass::FirstClass::sIsSeating = false;
template<> const bool BookingClass::AC3Tier::sIsSeating = false;
template<> const bool BookingClass::ACChairCar::sIsSeating = true;
template<> const bool BookingClass::Sleeper::sIsSeating = false;
template<> const bool BookingClass::SecondSitting::sIsSeating = true;

template<> const bool BookingClass::ACFirstClass::sIsAC = true;
template<> const bool BookingClass::ExecutiveChairCar::sIsAC = true;
template<> const bool BookingClass::AC2Tier::sIsAC = true;
template<> const bool BookingClass::FirstClass::sIsAC = false;
template<> const bool BookingClass::AC3Tier::sIsAC = true;
template<> const bool BookingClass::ACChairCar::sIsAC = true;
template<> const bool BookingClass::Sleeper::sIsAC = false;
template<> const bool BookingClass::SecondSitting::sIsAC = false;


template<> const unsigned BookingClass::ACFirstClass::sNumberOfTiers = 2;
template<> const unsigned BookingClass::ExecutiveChairCar::sNumberOfTiers = 0;
template<> const unsigned BookingClass::AC2Tier::sNumberOfTiers = 2;
template<> const unsigned BookingClass::FirstClass::sNumberOfTiers = 2;
template<> const unsigned BookingClass::AC3Tier::sNumberOfTiers = 3;
template<> const unsigned BookingClass::ACChairCar::sNumberOfTiers = 0;
template<> const unsigned BookingClass::Sleeper::sNumberOfTiers = 3;
template<> const unsigned BookingClass::SecondSitting::sNumberOfTiers = 0;

BookingClass::~BookingClass() = default;

std::ostream &operator<<(std::ostream &os, const BookingClass &aClass) {
    os << aClass.GetName() << "\n";
    os << "  - Mode: " << (aClass.IsSitting() ? "Sitting" : "Sleeping") << "\n";
    os << "  - AC: " << (aClass.IsAC() ? "Yes" : "No") << "\n";
    os << "  - Bunks: " << aClass.GetNumberOfTiers() << "\n";
    os << "  - Luxury: " << (aClass.IsLuxury() ? "Yes" : "No");
    return os;}
