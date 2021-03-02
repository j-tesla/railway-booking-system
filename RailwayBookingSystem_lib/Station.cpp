//
// Created by j-tesla on 02/03/21.
//

#include "Station.h"

Station::Station(const string &name): name_(name) {

}

const string &Station::GetName() {
    return name_;
}
