/**
 * @file Date.h
 * @brief contains implementations and declarations of all exception classes required in the library
 * @author Jayanth PSY - 19CS10068
 */

#include "Exceptions.h"


Bad_Date::Bad_Date() noexcept: std::exception(), cause(strdup("Bad Date")) {
}

Bad_Date::Bad_Date(const char *cause) noexcept: std::exception(), cause(strdup(cause)) {

}

Bad_Date::Bad_Date(const Bad_Date &other) noexcept: std::exception(), cause(strdup(other.cause)) {

}

const char *Bad_Date::what() const noexcept {

    return cause;
}

Bad_Date::~Bad_Date() noexcept {
    delete cause;
}


