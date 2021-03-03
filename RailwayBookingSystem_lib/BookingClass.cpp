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

float ACFirstClass::sLoadFactor = 3.00;

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
    return true;
}

unsigned int ACFirstClass::GetNumberOfTiers() const {
    return 2;
}

float ACFirstClass::GetLoadFactor() const {
    return sLoadFactor;
}

void ACFirstClass::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// AC2Tier:

float AC2Tier::sLoadFactor = 2.00;

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
    return false;
}

unsigned int AC2Tier::GetNumberOfTiers() const {
    return 2;
}

float AC2Tier::GetLoadFactor() const {
    return sLoadFactor;
}

void AC2Tier::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// FirstClass:

float FirstClass::sLoadFactor = 2.00;

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
    return true;
}

unsigned int FirstClass::GetNumberOfTiers() const {
    return 2;
}

float FirstClass::GetLoadFactor() const {
    return sLoadFactor;
}

void FirstClass::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// AC3Tier:

float AC3Tier::sLoadFactor = 1.75;

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
    return false;
}

unsigned int AC3Tier::GetNumberOfTiers() const {
    return 3;
}

float AC3Tier::GetLoadFactor() const {
    return sLoadFactor;
}

void AC3Tier::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// ACChairCar:

float ACChairCar::sLoadFactor = 1.25;

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
    return false;
}

unsigned int ACChairCar::GetNumberOfTiers() const {
    return 0;
}

float ACChairCar::GetLoadFactor() const {
    return sLoadFactor;
}

void ACChairCar::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// Sleeper:

float Sleeper::sLoadFactor = 1.00;

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
    return false;
}

unsigned int Sleeper::GetNumberOfTiers() const {
    return 3;
}

float Sleeper::GetLoadFactor() const {
    return sLoadFactor;
}

void Sleeper::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}

// SecondSitting:

float SecondSitting::sLoadFactor = 0.50;

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
    return false;
}

unsigned int SecondSitting::GetNumberOfTiers() const {
    return 0;
}

float SecondSitting::GetLoadFactor() const {
    return sLoadFactor;
}

void SecondSitting::SetLoadFactor(float loadFactor) const {
    sLoadFactor = loadFactor;
}
