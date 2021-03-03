//
// Created by j-tesla on 03/03/21.
//
#include "Railways.h"


std::set<Station> Railways::sStations = {};
std::map<std::pair<Station, Station>, unsigned> Railways::sDistances = {};

const Railways &Railways::IndianRailways() {
    static Railways theRailways;


    // Add Stations master data
    sStations.emplace("Mumbai");
    sStations.emplace("Delhi");
    sStations.emplace("Bangalore");
    sStations.emplace("Kolkata");
    sStations.emplace("Chennai");

    sDistances[{Station("Mumbai"), Station("Delhi")}] = sDistances[{Station("Delhi"), Station("Mumbai")}] = 1447;
    sDistances[{Station("Mumbai"), Station("Bangalore")}] = sDistances[{Station("Bangalore"),
                                                                        Station("Mumbai")}] = 981;
    sDistances[{Station("Mumbai"), Station("Kolkata")}] = sDistances[{Station("Kolkata"),
                                                                      Station("Mumbai")}] = 2014;
    sDistances[{Station("Mumbai"), Station("Chennai")}] = sDistances[{Station("Chennai"),
                                                                      Station("Mumbai")}] = 1338;
    sDistances[{Station("Delhi"), Station("Bangalore")}] = sDistances[{Station("Bangalore"),
                                                                       Station("Delhi")}] = 2150;
    sDistances[{Station("Delhi"), Station("Kolkata")}] = sDistances[{Station("Kolkata"), Station("Delhi")}] = 1472;
    sDistances[{Station("Delhi"), Station("Chennai")}] = sDistances[{Station("Chennai"), Station("Delhi")}] = 2180;
    sDistances[{Station("Bangalore"), Station("Kolkata")}] = sDistances[{Station("Kolkata"),
                                                                         Station("Bangalore")}] = 1871;
    sDistances[{Station("Bangalore"), Station("Chennai")}] = sDistances[{Station("Chennai"),
                                                                         Station("Bangalore")}] = 350;
    sDistances[{Station("Kolkata"), Station("Chennai")}] = sDistances[{Station("Chennai"),
                                                                       Station("Kolkata")}] = 1659;


    return theRailways;
}

unsigned Railways::GetDistance(const Station &a, const Station &b) {
    return sDistances[{a, b}];
}

unsigned Railways::GetDistance(const string &a, const string &b) {
    return sDistances[{Station(a), Station(b)}];
}

Railways::Railways() = default;

Railways::~Railways() = default;
