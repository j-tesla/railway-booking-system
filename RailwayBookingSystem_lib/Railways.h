//
// Created by j-tesla on 03/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_RAILWAYS_H
#define RAILWAYBOOKINGSYSTEM_RAILWAYS_H

#include <set>
#include <map>
#include <utility>
#include <vector>
#include <string>

#include "Station.h"


using std::string;


class Railways {
    Railways();

    ~Railways();

    static const std::set<Station> sStations;
    static const std::map<std::pair<const Station, const Station>, unsigned> sDistances;

public:

    /**
     * IndianRailways is the singleton Railways object
     * @return IndianRailways object
     */
    static const Railways &IndianRailways();

    /**
     * Distance between Stations
     * @param a some Station
     * @param b other Station
     * @return distance
     */
    static unsigned GetDistance(const Station &a, const Station &b);

    /**
     * Distance between Stations overload
     * @param a some Station name
     * @param b other Station name
     * @return distance
     */
    static unsigned GetDistance(const string &a, const string &b);

};


#endif //RAILWAYBOOKINGSYSTEM_RAILWAYS_H
