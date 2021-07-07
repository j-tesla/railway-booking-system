//
// Created by j-tesla on 29/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_BOOKINGCATEGORIES_H
#define RAILWAYBOOKINGSYSTEM_BOOKINGCATEGORIES_H


#include <string>
#include <ostream>


using std::string;

#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"


class BookingCategory {
    const string name_;

protected:
    BookingCategory(string name);

    virtual ~BookingCategory() noexcept;

public:
    virtual float
    CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                  unsigned distance) const = 0;

    virtual bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const = 0;

    const string &GetName() const;

    friend std::ostream &operator<<(std::ostream &os, const BookingCategory &category);

};

class General : public BookingCategory {
    General();

public:

    ~General() noexcept override;

    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned distance) const override;

    bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const override;

    static const BookingCategory &Type();
};

class Concession : public BookingCategory {
protected:
    Concession(const string &name);

    ~Concession() noexcept override;

    static float CalculateFare(float loadedFare, float concessionFactor);

};

class Ladies : public Concession {
    static const string sName;
    static const float sConcessionFactor;       //! initiate in application code

public:
    Ladies();

    ~Ladies() noexcept override;

    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned distance) const override;

    bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const override;

    static const BookingCategory &Type();

};

class SeniorCitizen : public Concession {
    static const string sName;
    static const float sMaleConcessionFactor;
    static const float sFemaleConcessionFactor;

public:
    SeniorCitizen();

    ~SeniorCitizen() noexcept override;

    bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const override;

    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned distance) const override;

    static const BookingCategory &Type();

};

class Priority : public BookingCategory {
protected:
    Priority(const string &name);

    ~Priority() noexcept override;

public:

    bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const override;

};

class Tatkal : public Priority {
    static const string sName;
    Tatkal();

public:
    ~Tatkal() override;

    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned int distance) const override;

    static const BookingCategory &Type();

};

class PremiumTatkal : public Priority {
    static const string sName;
    PremiumTatkal();

public:
    ~PremiumTatkal() override;

    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned int distance) const override;
};

template<typename D>
class DivyaangCategory : public Concession {
    static const string sName;
protected:
    DivyaangCategory();

    ~DivyaangCategory() override;

public:
    float CalculateFare(float loadedFare, const BookingClass &bookingClass, const Passenger &passenger,
                        unsigned int distance) const override;

    bool
    IsEligible(const Passenger &passenger, const Date &dateOfBooking, const Date &dateOfReservation) const override;

public:
    static const BookingCategory &Type();
};


template<typename D>
const string DivyaangCategory<D>::sName = "Divyaang";

template<typename D>
DivyaangCategory<D>::DivyaangCategory(): Concession(sName) {
}

template<typename D>
const BookingCategory &DivyaangCategory<D>::Type() {
    static const DivyaangCategory<D> sObject;
    return sObject;
}

template<typename D>
bool DivyaangCategory<D>::IsEligible(const Passenger &passenger, const Date &dateOfBooking,
                                     const Date &dateOfReservation) const {
    if (passenger.GetDisabiltyType() == &D::Type() and not passenger.GetDisabilityId().empty()) {
        return true;
    }
    return false;
}

template<typename D>
DivyaangCategory<D>::~DivyaangCategory() = default;


#endif //RAILWAYBOOKINGSYSTEM_BOOKINGCATEGORIES_H
