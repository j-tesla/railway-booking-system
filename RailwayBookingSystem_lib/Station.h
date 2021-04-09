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
    Station(string name) noexcept;

    ~Station() noexcept;


    /**
     *
     * @return name of station
     */
    inline const string &GetName() const {
        return name_;
    };

    /**
     * compare names (strings)
     * @param other
     * @return bool
     */
    inline bool operator<(const Station &other) const {
        return name_ < other.name_;
    }

    inline bool operator==(const Station &other) const {
        return name_ == other.name_;
    }
};


#endif //RAILWAYBOOKINGSYSTEM_STATION_H
