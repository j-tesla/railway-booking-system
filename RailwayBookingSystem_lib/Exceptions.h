/**
 * @file Exceptions.h
 * @brief contains all exception classes required in the library
 * @author Jayanth PSY - 19CS10068
 */

#ifndef RAILWAYBOOKINGSYSTEM_EXCEPTIONS_H
#define RAILWAYBOOKINGSYSTEM_EXCEPTIONS_H

#include <cstring>

#include <exception>


/** \class
 * Exception for invalid dates
 */
class Exception : public std::exception {
    const char *const cause_;

public:

    Exception() noexcept;

    explicit Exception(const char *cause) noexcept;

    Exception(const Exception &other) noexcept;

    const char *what() const noexcept override;

    ~Exception() noexcept override;
};

class Bad_Date : public Exception {
public:
    Bad_Date() noexcept;

    explicit Bad_Date(const char *cause) noexcept;

    Bad_Date(const Bad_Date &other) noexcept;
};

class Bad_Passenger : public Exception {
public:
    Bad_Passenger() noexcept;

    explicit Bad_Passenger(const char *cause) noexcept;

    Bad_Passenger(const Bad_Passenger &other) noexcept;
};

class Bad_Name : public Bad_Passenger {
public:
    Bad_Name() noexcept;

    explicit Bad_Name(const char *cause) noexcept;

    Bad_Name(const Bad_Name &other) noexcept;
};

class Bad_Aadhaar : public Bad_Passenger {
public:
    Bad_Aadhaar() noexcept;

    explicit Bad_Aadhaar(const char *cause) noexcept;

    Bad_Aadhaar(const Bad_Aadhaar &other) noexcept;
};

class Bad_PhoneNumber : public Bad_Passenger {
public:
    Bad_PhoneNumber() noexcept;

    explicit Bad_PhoneNumber(const char *cause) noexcept;

    Bad_PhoneNumber(const Bad_PhoneNumber &other) noexcept;
};

class Bad_Booking : public Exception {
public:
    Bad_Booking() noexcept;

    explicit Bad_Booking(const char *cause) noexcept;

    Bad_Booking(const Bad_Booking &other) noexcept;
};

#endif //RAILWAYBOOKINGSYSTEM_EXCEPTIONS_H
