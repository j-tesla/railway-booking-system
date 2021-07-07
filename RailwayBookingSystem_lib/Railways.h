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
    Railways(std::set<Station>  stations, std::map<std::pair<const Station, const Station>, unsigned>  distances);

    ~Railways();

    const std::set<Station> stations_;
    const std::map<std::pair<const Station, const Station>, unsigned> distances_;

public:
    /**
     * IndianRailways is a singleton instance of Railways
     * @return reference to India Railways
     */
    static const Railways &IndianRailways();

    /**
     * Distance between two stations_ in the IndianRailways
     * @param a Station
     * @param b Station
     * @return distance
     */
    unsigned GetDistance(const Station &a, const Station &b) const;

    /**
     * Distance between two stations_ in the IndianRailways
     * @param a name of Station
     * @param b name of Station
     * @return distance
     */
    inline unsigned GetDistance(const string &a, const string &b) const{
        return GetDistance(Station(a), Station(b));
    }

    inline bool ValidStation(const Station &station) const {
        return stations_.find(station) != stations_.end();
    }

};


#endif //RAILWAYBOOKINGSYSTEM_RAILWAYS_H
