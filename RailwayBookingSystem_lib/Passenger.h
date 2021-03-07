/**
 * @file Passenger.h
 * @brief contains of Passenger class
 * @author Jayanth PSY - 19CS10068
 */

#ifndef RAILWAYBOOKINGSYSTEM_PASSENGER_H
#define RAILWAYBOOKINGSYSTEM_PASSENGER_H


/**
 * abstract class for future extension
 */
class Passenger {
public:
    Passenger();

    virtual ~Passenger() = 0;
};


#endif //RAILWAYBOOKINGSYSTEM_PASSENGER_H
