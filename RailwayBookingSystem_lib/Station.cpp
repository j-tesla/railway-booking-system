//
// Created by Jayanth PSY (19CS10068) on 02/03/21.
//

#include "Station.h"


Station::Station(const string &name) : name_(name) {

}

const string &Station::GetName() const {
    return name_;
}

bool Station::operator<(const Station &other) const {
    return name_ < other.name_;
}

bool Station::operator==(const Station &other) const {
    return name_ == other.name_;
}

Station::~Station() = default;
