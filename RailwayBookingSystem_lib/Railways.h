/**
 * @file Railways.h
 * @brief contains Railways class
 * @author Jayanth PSY - 19CS10068
 */


#ifndef RAILWAYBOOKINGSYSTEM_RAILWAYS_H
#define RAILWAYBOOKINGSYSTEM_RAILWAYS_H

#include <set>
#include <map>
#include <utility>
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
     * IndianRailways is a singleton instance of Railways
     * @return reference to India Railways
     */
    static const Railways &IndianRailways();

    /**
     * Distance between two stations in the IndianRailways
     * @param a Station
     * @param b Station
     * @return distance
     */
    static unsigned GetDistance(const Station &a, const Station &b);

    /**
     * Distance between two stations in the IndianRailways
     * @param a name of Station
     * @param b name of Station
     * @return distance
     */
    inline static unsigned GetDistance(const string &a, const string &b) {
        return sDistances.at({Station(a), Station(b)});
    }

    inline static bool ValidStation(const Station &station) {
        return sStations.find(station) != sStations.end();
    }

};


#endif //RAILWAYBOOKINGSYSTEM_RAILWAYS_H
