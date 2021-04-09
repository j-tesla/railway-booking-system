/**
 * @file Station.cpp
 * @brief contains implementations and declarations of Station class
 * @author Jayanth PSY - 19CS10068
 */


#include "Station.h"

#include <utility>


Station::Station(string name) noexcept: name_(std::move(name)) {

}



Station::~Station() noexcept = default;
