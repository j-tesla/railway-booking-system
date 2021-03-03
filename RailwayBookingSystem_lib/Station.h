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
    Station(const string &name);

    ~Station();

    const string &GetName() const;

    bool operator<(const Station &other) const;

    bool operator==(const Station &other) const;
};


#endif //RAILWAYBOOKINGSYSTEM_STATION_H
