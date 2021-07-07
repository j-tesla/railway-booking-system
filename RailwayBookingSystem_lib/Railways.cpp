/**
 * @file Railways.cpp
 * @brief contains implementations and declarations of Railways class
 * @author Jayanth PSY - 19CS10068
 */


#include <utility>

#include "Exceptions.h"
#include "Railways.h"


std::set<Station> IndianRailwayStations() {
    std::set<Station> stations;

    stations.emplace("Mumbai");
    stations.emplace("Delhi");
    stations.emplace("Bangalore");
    stations.emplace("Kolkata");
    stations.emplace("Chennai");
    return stations;
}

/**
 * master data for Indian Railways Station details
 * @return
 */
std::map<std::pair<const Station, const Station>, unsigned> IndianRailwayStationDistances() {

    std::map<std::pair<const Station, const Station>, unsigned> distances;

    distances[{Station("Mumbai"), Station("Delhi")}] = 1447;
    distances[{Station("Mumbai"), Station("Bangalore")}] = 981;
    distances[{Station("Mumbai"), Station("Kolkata")}] = 2014;
    distances[{Station("Mumbai"), Station("Chennai")}] = 1338;
    distances[{Station("Delhi"), Station("Bangalore")}] = 2150;
    distances[{Station("Delhi"), Station("Kolkata")}] = 1472;
    distances[{Station("Delhi"), Station("Chennai")}] = 2180;
    distances[{Station("Bangalore"), Station("Kolkata")}] = 1871;
    distances[{Station("Bangalore"), Station("Chennai")}] = 350;
    distances[{Station("Kolkata"), Station("Chennai")}] = 1659;

    return distances;
}

/**
 * Meyer's singleton Railways
 * @return reference to singleton object
 */
const Railways &Railways::IndianRailways() {
    auto stations = IndianRailwayStations();
    auto distances = IndianRailwayStationDistances();
    for (const auto &s1: stations) {
        for (const auto &s2: stations) {
            auto it1 = distances.find({s1, s2});
            auto it2 = distances.find({s2, s1});
            if (s1 == s2) {
                if (it1 != distances.end() or it2 != distances.end()) {
                    throw Bad_Railways("Bad Railways: Distance from a station to same station should not be defined");
                }
            } else {
                if (it1 != distances.end() and it2 != distances.end()) {
                    throw Bad_Railways("Bad Railways: Duplicated inter-station distance");
                } else if (it1 == distances.end() and it2 == distances.end()) {
                    throw Bad_Railways("Bad Railways: Missing station distance");
                }
            }
        }
    }
    static Railways theRailways(stations, distances);


    return theRailways;
}

unsigned Railways::GetDistance(const Station &a, const Station &b) const {
    if (distances_.find({a, b}) != distances_.end()) {
        return distances_.at({a, b});
    } else if (distances_.find({b, a}) != distances_.end()) {
        return distances_.at({b, a});
    } else {
        return 0;
    }
}

Railways::Railways(std::set<Station> stations,
                   std::map<std::pair<const Station, const Station>, unsigned int> distances) :
        stations_(std::move(stations)), distances_(std::move(distances)) {
}


Railways::~Railways() = default;
