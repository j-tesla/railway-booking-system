/**
 * @file Passenger.h
 * @brief contains of Passenger class
 * @author Jayanth PSY - 19CS10068
 */

#ifndef RAILWAYBOOKINGSYSTEM_PASSENGER_H
#define RAILWAYBOOKINGSYSTEM_PASSENGER_H

#include <string>

#include "Date.h"
#include "Gender.h"
#include "Divyaang.h"


using std::string;


namespace PassengerDetails {
    class Name {
        explicit Name(string firstName, string middleName, string lastName);

    public:
        const string firstName_;
        const string middleName_;
        const string lastName_;


        Name(const Name &other);

        static Name Construct(const string &firstName, const string &middleName = "", const string &lastName = "");
    };

    class AadhaarNumber : string {
        explicit AadhaarNumber(const string &aadhaar);

    public:
        AadhaarNumber(const AadhaarNumber &other);

        static AadhaarNumber Construct(const string &aadhaarNumber);
    };

    class PhoneNumber : string {
        explicit PhoneNumber(const string &phoneNumber);

    public:
        PhoneNumber(const PhoneNumber &other);

        static PhoneNumber Construct(const string &phoneNumber);
    };


    using DivyaangID = string;
}

class Passenger {
    const PassengerDetails::Name name_;
    const Date dateOfBirth_;
    const Gender &gender_;
    const PassengerDetails::AadhaarNumber aadhaar_;
    const PassengerDetails::PhoneNumber phone_;
    const Divyaang *const disabiltyType_;
    const PassengerDetails::DivyaangID disabilityID_;


    Passenger(const PassengerDetails::Name& name, const Date& dateOfBirth, const Gender& gender, const PassengerDetails::AadhaarNumber& aadhaar,
              const PassengerDetails::PhoneNumber& phone, const Divyaang *disabilityType,
              PassengerDetails::DivyaangID disabilityID);

public:

    static Passenger
    Construct(const PassengerDetails::Name& name, const Date& dateOfBirth, const Gender& gender, const PassengerDetails::AadhaarNumber& aadhaar,
              const PassengerDetails::PhoneNumber& phone, const Divyaang *disabilityType = nullptr,
              const PassengerDetails::DivyaangID& disabilityID = "") noexcept(false);

    virtual ~Passenger();

    const Gender &GetGender() const;

    const Date &GetDateOfBirth() const;

    const Divyaang *GetDisabiltyType() const;

    const PassengerDetails::DivyaangID &GetDisabilityId() const;
};


#endif //RAILWAYBOOKINGSYSTEM_PASSENGER_H
