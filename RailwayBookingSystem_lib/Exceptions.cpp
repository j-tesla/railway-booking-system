/**
 * @file Date.h
 * @brief contains implementations and declarations of all exception classes required in the library
 * @author Jayanth PSY - 19CS10068
 */

#include "Exceptions.h"


Bad_Date::Bad_Date() noexcept: std::exception(), cause_(strdup("Bad Date")) {
}

Bad_Date::Bad_Date(const char *cause) noexcept: std::exception(), cause_(strdup(cause)) {

}

Bad_Date::Bad_Date(const Bad_Date &other) noexcept: std::exception(), cause_(strdup(other.cause_)) {

}

const char *Bad_Date::what() const noexcept {

    return cause_;
}

Bad_Date::~Bad_Date() noexcept {
    delete cause_;
}


