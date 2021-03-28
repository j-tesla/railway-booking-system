/**
 * @file Station.h
 * @brief contains Station class
 * @author Jayanth PSY - 19CS10068
 */


#ifndef RAILWAYBOOKINGSYSTEM_STATION_H
#define RAILWAYBOOKINGSYSTEM_STATION_H

#include <string>


using std::string;

class Station {
    const string name_;        //! name of the station

public:
    /**
     * Station identified by its name
     * @param name
     */
    Station(const string &name);

    ~Station();

    /**
     *
     * @return name of station
     */
    const string &GetName() const;

    /**
     * compare names (strings)
     * @param other
     * @return bool
     */
    bool operator<(const Station &other) const;

    bool operator==(const Station &other) const;
};


#endif //RAILWAYBOOKINGSYSTEM_STATION_H
