//
// Created by j-tesla on 03/03/21.
//
#include "Railways.h"


//const std::set<Station> Railways::sStations = {};
//const std::map<std::pair<const Station, const Station>, unsigned> Railways::sDistances = {};

std::set<Station> IndianRailwayStations() {
    std::set<Station> stations;

    stations.emplace("Mumbai");
    stations.emplace("Delhi");
    stations.emplace("Bangalore");
    stations.emplace("Kolkata");
    stations.emplace("Chennai");
    return stations;
}

std::map<std::pair<const Station, const Station>, unsigned> IndianRailwayStationDistances() {
    // master data for Indian Railways Station details
    std::map<std::pair<const Station, const Station>, unsigned> distances;

    distances[{Station("Mumbai"), Station("Delhi")}] = distances[{Station("Delhi"), Station("Mumbai")}] = 1447;
    distances[{Station("Mumbai"), Station("Bangalore")}] = distances[{Station("Bangalore"),
                                                                      Station("Mumbai")}] = 981;
    distances[{Station("Mumbai"), Station("Kolkata")}] = distances[{Station("Kolkata"),
                                                                    Station("Mumbai")}] = 2014;
    distances[{Station("Mumbai"), Station("Chennai")}] = distances[{Station("Chennai"),
                                                                    Station("Mumbai")}] = 1338;
    distances[{Station("Delhi"), Station("Bangalore")}] = distances[{Station("Bangalore"),
                                                                     Station("Delhi")}] = 2150;
    distances[{Station("Delhi"), Station("Kolkata")}] = distances[{Station("Kolkata"), Station("Delhi")}] = 1472;
    distances[{Station("Delhi"), Station("Chennai")}] = distances[{Station("Chennai"), Station("Delhi")}] = 2180;
    distances[{Station("Bangalore"), Station("Kolkata")}] = distances[{Station("Kolkata"),
                                                                       Station("Bangalore")}] = 1871;
    distances[{Station("Bangalore"), Station("Chennai")}] = distances[{Station("Chennai"),
                                                                       Station("Bangalore")}] = 350;
    distances[{Station("Kolkata"), Station("Chennai")}] = distances[{Station("Chennai"),
                                                                     Station("Kolkata")}] = 1659;

    return distances;
}

const std::set<Station> Railways::sStations = IndianRailwayStations();

const std::map<std::pair<const Station, const Station>, unsigned> Railways::sDistances = IndianRailwayStationDistances();

const Railways &Railways::IndianRailways() {
    static Railways theRailways;
    return theRailways;
}

unsigned Railways::GetDistance(const Station &a, const Station &b) {
    return sDistances.at({a, b});
}

unsigned Railways::GetDistance(const string &a, const string &b) {
    return sDistances.at({Station(a), Station(b)});
}

Railways::Railways() = default;

Railways::~Railways() = default;
