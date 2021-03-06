//
// Created by j-tesla on 02/03/21.
//


#include "BookingClass.h"

// BookingClass:

BookingClass::BookingClass() = default;

BookingClass::~BookingClass() = default;

// SeatClass:

bool SeatClass::IsSitting() const {
    return true;
}

// BerthClass:

bool BerthClass::IsSitting() const {
    return false;
}

// ACFirstClass:

const BookingClass &ACFirstClass::Type() {
    static const ACFirstClass theObj;
    return theObj;
}

string ACFirstClass::GetName() const {
    return "AC First Class";
}

bool ACFirstClass::IsAc() const {
    return true;
}

bool ACFirstClass::IsLuxury() const {
    return sIsLuxury;
}

unsigned int ACFirstClass::GetNumberOfTiers() const {
    return 2;
}

float ACFirstClass::GetLoadFactor() const {
    return sLoadFactor;
}


// AC2Tier:

const BookingClass &AC2Tier::Type() {
    static const AC2Tier theObj;
    return theObj;
}

string AC2Tier::GetName() const {
    return "AC 2 Tier";
}

bool AC2Tier::IsAc() const {
    return true;
}

bool AC2Tier::IsLuxury() const {
    return sIsLuxury;
}

unsigned int AC2Tier::GetNumberOfTiers() const {
    return 2;
}

float AC2Tier::GetLoadFactor() const {
    return sLoadFactor;
}


// FirstClass:

const BookingClass &FirstClass::Type() {
    static const FirstClass theObj;
    return theObj;
}

string FirstClass::GetName() const {
    return "First Class";
}

bool FirstClass::IsAc() const {
    return false;
}

bool FirstClass::IsLuxury() const {
    return sIsLuxury;
}

unsigned int FirstClass::GetNumberOfTiers() const {
    return 2;
}

float FirstClass::GetLoadFactor() const {
    return sLoadFactor;
}


// AC3Tier:

const BookingClass &AC3Tier::Type() {
    static const AC3Tier theObj;
    return theObj;
}

string AC3Tier::GetName() const {
    return "AC 3 Tier";
}

bool AC3Tier::IsAc() const {
    return true;
}

bool AC3Tier::IsLuxury() const {
    return sIsLuxury;
}

unsigned int AC3Tier::GetNumberOfTiers() const {
    return 3;
}

float AC3Tier::GetLoadFactor() const {
    return sLoadFactor;
}


// ACChairCar:

const BookingClass &ACChairCar::Type() {
    static const ACChairCar theObj;
    return theObj;
}

string ACChairCar::GetName() const {
    return "AC Chair Car";
}

bool ACChairCar::IsAc() const {
    return true;
}

bool ACChairCar::IsLuxury() const {
    return sIsLuxury;
}

unsigned int ACChairCar::GetNumberOfTiers() const {
    return 0;
}

float ACChairCar::GetLoadFactor() const {
    return sLoadFactor;
}


// Sleeper:

const BookingClass &Sleeper::Type() {
    static const Sleeper theObj;
    return theObj;
}

string Sleeper::GetName() const {
    return "Sleeper";
}

bool Sleeper::IsAc() const {
    return false;
}

bool Sleeper::IsLuxury() const {
    return sIsLuxury;
}

unsigned int Sleeper::GetNumberOfTiers() const {
    return 3;
}

float Sleeper::GetLoadFactor() const {
    return sLoadFactor;
}


// SecondSitting:

const BookingClass &SecondSitting::Type() {
    static const SecondSitting theObj;
    return theObj;
}

string SecondSitting::GetName() const {
    return "Second Sitting";
}

bool SecondSitting::IsAc() const {
    return false;
}

bool SecondSitting::IsLuxury() const {
    return sIsLuxury;
}

unsigned int SecondSitting::GetNumberOfTiers() const {
    return 0;
}

float SecondSitting::GetLoadFactor() const {
    return sLoadFactor;
}


bool BookingClass::operator==(const BookingClass &other) const {
    return GetName() == other.GetName();
}

std::ostream &operator<<(std::ostream &os, const BookingClass &aClass) {
    os << "Travel Class = " << aClass.GetName() << "\n";
    os << "  - Mode: " << (aClass.IsSitting() ? "Sitting" : "Sleeping") << "\n";
    os << "  - AC: " << (aClass.IsAc() ? "Yes" : "No") << "\n";
    os << "  - Bunks: " << aClass.GetNumberOfTiers() << "\n";
    os << "  - Luxury: " << (aClass.IsLuxury() ? "Yes" : "No");
    return os;
}
