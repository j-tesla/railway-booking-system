//
// Created by j-tesla on 02/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_STATION_H
#define RAILWAYBOOKINGSYSTEM_STATION_H

#include <string>

using std::string;

class Station {
    const string name_;

public:
    explicit Station(const string &name);

    const string &GetName();
};


#endif //RAILWAYBOOKINGSYSTEM_STATION_H
