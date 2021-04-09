//
// Created by j-tesla on 29/03/21.
//

#include "BookingCategories.h"

#include <utility>


const string General::sName = "General";
const string Tatkal::sName = "Tatkal";
const string PremiumTatkal::sName = "Premium Tatkal";
const string Ladies::sName = "Ladies";
const string SeniorCitizen::sName = "Senior Citizen";

BookingCategory::BookingCategory(string name) : name_(std::move(name)) {
}

const string &BookingCategory::GetName() const {
    return name_;
}

std::ostream &operator<<(std::ostream &os, const BookingCategory &category) {
    os << category.name_;
    return os;
}

BookingCategory::~BookingCategory() noexcept = default;

General::General() : BookingCategory(sName) {
}

float General::CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                             unsigned distance) const {
    return loadedFare;
}

bool General::IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const {
    return true;
}

const BookingCategory &General::Type() {
    static const General sObject;
    return sObject;
}

General::~General() noexcept = default;

Concession::Concession(const string &name) : BookingCategory(name) {
}

float Concession::CalculateFare(float loadedFare, float concessionFactor) {
    return loadedFare * (1 - concessionFactor);
}

Concession::~Concession() noexcept = default;


Ladies::Ladies() : Concession(sName) {
}

bool Ladies::IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const {
    return not passenger.GetGender().IsMale();
}

float Ladies::CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                            unsigned distance) const {
    return Concession::CalculateFare(loadedFare, sConcessionFactor);
}

const BookingCategory &Ladies::Type() {
    static const Ladies sObject;
    return sObject;
}

Ladies::~Ladies() noexcept = default;

SeniorCitizen::SeniorCitizen() : Concession(sName) {
}

bool
SeniorCitizen::IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const {
    DateDelta age = dateOfReservation - passenger.GetDateOfBirth();
    return (passenger.GetGender().IsMale() and age > DateDelta::Construct(0, 0, 60))
           or (not passenger.GetGender().IsMale() and age > DateDelta::Construct(0, 0, 58));
}

float
SeniorCitizen::CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                             unsigned distance) const {
    float concessionFactor = passenger.GetGender().IsMale() ? sMaleConcessionFactor : sFemaleConcessionFactor;
    return Concession::CalculateFare(loadedFare, concessionFactor);
}

const BookingCategory &SeniorCitizen::Type() {
    static const SeniorCitizen sObject;
    return sObject;
}

SeniorCitizen::~SeniorCitizen() noexcept = default;


bool Priority::IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const {
    if (dateOfBooking - dateOfReservation == DateDelta::OneDay) {
        return true;
    }

    return false;
}

Priority::~Priority() noexcept = default;

Priority::Priority(const string &name) : BookingCategory(name) {}

Tatkal::Tatkal() : Priority(sName) {
}

float Tatkal::CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                            unsigned distance) const {
    if (distance < bookingClass.GetMinimumDistanceForTatkalCharge()) {
        return loadedFare;
    }

    float tatkalCharge = bookingClass.GetTatkalChargeRate() * loadedFare;

    if (tatkalCharge > bookingClass.GetMaximumTatkalCharges()) {
        return loadedFare + bookingClass.GetMaximumTatkalCharges();
    }

    if (tatkalCharge < bookingClass.GetMinimumTatkalCharges()) {
        return loadedFare + bookingClass.GetMaximumTatkalCharges();
    }

    return loadedFare + tatkalCharge;
}

const BookingCategory &Tatkal::Type() {
    static const Tatkal sObject;
    return sObject;
}

Tatkal::~Tatkal() = default;

PremiumTatkal::PremiumTatkal() : Priority(sName) {
}

float PremiumTatkal::CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                                   unsigned int distance) const {
    if (distance < bookingClass.GetMinimumDistanceForTatkalCharge()) {
        return loadedFare;
    }

    float tatkalCharge = bookingClass.GetTatkalChargeRate() * loadedFare;

    if (tatkalCharge > bookingClass.GetMaximumTatkalCharges()) {
        return loadedFare + 2 * bookingClass.GetMaximumTatkalCharges();
    }

    if (tatkalCharge < bookingClass.GetMinimumTatkalCharges()) {
        return loadedFare + 2 * bookingClass.GetMaximumTatkalCharges();
    }

    return loadedFare + 2 * tatkalCharge;
}

PremiumTatkal::~PremiumTatkal() = default;

template<>
float DivyaangCategory<Divyaang::Blind>::CalculateFare(float loadedFare, const BookingClass &bookingClass,
                                                       const Passenger &passenger,
                                                       unsigned int distance) const {
    return Concession::CalculateFare(loadedFare, bookingClass.GetBlindConcessionFactor());
}

template<>
float DivyaangCategory<Divyaang::OrthopaedicallyHandicapped>::CalculateFare(float loadedFare,
                                                                            const BookingClass &bookingClass,
                                                                            const Passenger &passenger,
                                                                            unsigned int distance) const {
    return Concession::CalculateFare(loadedFare, bookingClass.GetOrthopaedicallyHandicappedConcessionFactor());
}

template<>
float DivyaangCategory<Divyaang::CancerPatients>::CalculateFare(float loadedFare, const BookingClass &bookingClass,
                                                                const Passenger &passenger,
                                                                unsigned int distance) const {
    return Concession::CalculateFare(loadedFare, bookingClass.GetCancerPatientsConcessionFactor());
}

template<>
float DivyaangCategory<Divyaang::TBPatients>::CalculateFare(float loadedFare, const BookingClass &bookingClass,
                                                            const Passenger &passenger,
                                                            unsigned int distance) const {
    return Concession::CalculateFare(loadedFare, bookingClass.GetTBPatientsConcessionFactor());
}

