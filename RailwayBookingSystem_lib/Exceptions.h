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
class Bad_Date : public std::exception {
    const char *const cause_;

public:

    Bad_Date() noexcept;

    explicit Bad_Date(const char *cause) noexcept;

    Bad_Date(const Bad_Date &other) noexcept;

    const char *what() const noexcept override;

    ~Bad_Date() noexcept override;
};


#endif //RAILWAYBOOKINGSYSTEM_EXCEPTIONS_H
