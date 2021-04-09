/**
 * @file Date.h
 * @brief contains implementations and declarations of all exception classes required in the library
 * @author Jayanth PSY - 19CS10068
 */

#include "Exceptions.h"


Exception::Exception() noexcept: std::exception(), cause_(strdup("Bad Date")) {
}

Exception::Exception(const char *cause) noexcept: std::exception(), cause_(strdup(cause)) {

}

Exception::Exception(const Exception &other) noexcept: std::exception(), cause_(strdup(other.cause_)) {

}

const char *Exception::what() const noexcept {

    return cause_;
}

Exception::~Exception() noexcept {
    delete cause_;
}

Bad_Date::Bad_Date() noexcept: Exception() {
}

Bad_Date::Bad_Date(const char *cause) noexcept: Exception(cause) {
}

Bad_Date::Bad_Date(const Bad_Date &other) noexcept: Exception(other) {
}

Bad_Passenger::Bad_Passenger() noexcept: Exception() {
}

Bad_Passenger::Bad_Passenger(const char *cause) noexcept: Exception(cause) {
}

Bad_Passenger::Bad_Passenger(const Bad_Passenger &other) noexcept: Exception(other) {
}

Bad_Name::Bad_Name() noexcept: Bad_Passenger() {
}

Bad_Name::Bad_Name(const char *cause) noexcept: Bad_Passenger(cause) {
}

Bad_Name::Bad_Name(const Bad_Name &other) noexcept: Bad_Passenger(other) {
}

Bad_Aadhaar::Bad_Aadhaar() noexcept: Bad_Passenger() {
}

Bad_Aadhaar::Bad_Aadhaar(const char *cause) noexcept: Bad_Passenger(cause) {
}

Bad_Aadhaar::Bad_Aadhaar(const Bad_Aadhaar &other) noexcept: Bad_Passenger(other) {
}

Bad_PhoneNumber::Bad_PhoneNumber() noexcept: Bad_Passenger() {
}

Bad_PhoneNumber::Bad_PhoneNumber(const char *cause) noexcept: Bad_Passenger(cause) {
}



Bad_PhoneNumber::Bad_PhoneNumber(const Bad_PhoneNumber &other) noexcept: Bad_Passenger(other) {
}

Bad_Booking::Bad_Booking() noexcept: Exception() {
}

Bad_Booking::Bad_Booking(const char *cause) noexcept: Exception(cause) {
}

Bad_Booking::Bad_Booking(const Bad_Booking &other) noexcept: Exception(other) {
}
