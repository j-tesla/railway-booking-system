/**
 * @file Passenger.cpp
 * @brief contains implementations and declarations of Passenger class
 * @author Jayanth PSY - 19CS10068
 */

#include <utility>

#include "Passenger.h"
#include "Exceptions.h"


PassengerDetails::Name::Name(string firstName, string middleName, string lastName) : firstName_(std::move(firstName)),
                                                                                     middleName_(std::move(middleName)),
                                                                                     lastName_(std::move(lastName)) {
}

PassengerDetails::Name::Name(const Name &other) : firstName_(other.firstName_),
                                                  middleName_(other.middleName_),
                                                  lastName_(other.lastName_) {
}

PassengerDetails::Name
PassengerDetails::Name::Construct(const string &firstName, const string &middleName, const string &lastName) {
    if (firstName.empty() and lastName.empty()) {
        throw Bad_Name("Bad Name: both firstName and lastName can't be empty");
    }
    return Name(firstName, middleName, lastName);
}


PassengerDetails::AadhaarNumber::AadhaarNumber(const string &aadhaar) : basic_string(aadhaar) {
}

PassengerDetails::AadhaarNumber::AadhaarNumber(const AadhaarNumber &other) : basic_string(other) {
}

PassengerDetails::AadhaarNumber PassengerDetails::AadhaarNumber::Construct(const string &aadhaarNumber) {
    if (aadhaarNumber.size() != 12) {
        throw Bad_Aadhaar("Bad Aadhaar: aadhaar number should be 12 digits long");
    }
    for (char c: aadhaarNumber) {
        if (not isdigit(c)) {
            throw Bad_Aadhaar("Bad Aadhaar: aadhaar number should contain only numerical digits");
        }
    }
    return AadhaarNumber(aadhaarNumber);
}

PassengerDetails::PhoneNumber::PhoneNumber(const string &phoneNumber) : basic_string(phoneNumber) {
}

PassengerDetails::PhoneNumber::PhoneNumber(const PhoneNumber &other) : basic_string(other) {
}

PassengerDetails::PhoneNumber PassengerDetails::PhoneNumber::Construct(const string &phoneNumber) {
    if (phoneNumber.size() != 10) {
        throw Bad_PhoneNumber("Bad PhoneNumber: phone number should be 10 digits long");
    }
    for (char c: phoneNumber) {
        if (not isdigit(c)) {
            throw Bad_Aadhaar("Bad PhoneNumber: phone number should contain only numerical digits");
        }
    }
    return PhoneNumber(phoneNumber);
}

const Gender &Passenger::GetGender() const {
    return gender_;
}

const Date &Passenger::GetDateOfBirth() const {
    return dateOfBirth_;
}


const PassengerDetails::DivyaangID &Passenger::GetDisabilityId() const {
    return disabilityID_;
}

const Divyaang *const Passenger::GetDisabiltyType() const {
    return disabiltyType_;
}

Passenger::Passenger(const PassengerDetails::Name& name, const Date& dateOfBirth, const Gender& gender,
                     const PassengerDetails::AadhaarNumber& aadhaar, const PassengerDetails::PhoneNumber& phone,
                     const Divyaang *const disabilityType, PassengerDetails::DivyaangID disabilityID)
        : name_(name), dateOfBirth_(dateOfBirth), gender_(gender), aadhaar_(aadhaar), phone_(phone),
          disabiltyType_(disabilityType), disabilityID_(std::move(disabilityID)) {
}

Passenger Passenger::Construct(const PassengerDetails::Name& name, const Date& dateOfBirth, const Gender& gender,
                               const PassengerDetails::AadhaarNumber& aadhaar, const PassengerDetails::PhoneNumber& phone,
                               const Divyaang *const disabilityType,
                               const PassengerDetails::DivyaangID& disabilityID) noexcept(false) {
    return Passenger(name, dateOfBirth, gender, aadhaar, phone, disabilityType, disabilityID);
}

Passenger::~Passenger() = default;

template<> const string Divyaang::Blind::sName = "Blind";
template<> const string Divyaang::OrthopaedicallyHandicapped::sName = "OrthopaedicallyHandicapped";
template<> const string Divyaang::CancerPatients::sName = "CancerPatients";
template<> const string Divyaang::TBPatients::sName = "TBPatients";