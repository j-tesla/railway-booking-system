//
// Created by Jayanth PSY (19CS10068) on 02/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H
#define RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H


#include <string>
#include <iostream>


using std::string;

/**
 * base class for all booking classes
 */
class BookingClass {

protected:
    BookingClass();

    virtual ~BookingClass();

public:
    /**
     * Booking class type objects are uncopyable
     * @param other
     */
    BookingClass(const BookingClass &other) = delete;

    /**
     *
     * @return name of booking class
     */
    virtual string GetName() const = 0;

    /**
     *
     * @return bool value if class is sitting type
     */
    virtual bool IsSitting() const = 0;

    /**
     *
     * @return bool value if class s of AC type
     */
    virtual bool IsAc() const = 0;

    /**
     *
     * @return bool value is class considered as luxury class
     */
    virtual bool IsLuxury() const = 0;

    /**
     *
     * @return number of tiers
     */
    virtual unsigned GetNumberOfTiers() const = 0;

    /**
     *
     * @return loadFactor
     */
    virtual float GetLoadFactor() const = 0;

    virtual bool operator==(const BookingClass &other) const;

    friend std::ostream &operator<<(std::ostream &os, const BookingClass &aClass);
};

/**
 * base class for all sitting classes
 */
class SeatClass : public BookingClass {
public:
    bool IsSitting() const override;
};

/**
 * base class for all sleeping classes
 */
class BerthClass : public BookingClass {
public:
    bool IsSitting() const override;
};

class ACFirstClass : public BerthClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class AC2Tier : public BerthClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class FirstClass : public BerthClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class AC3Tier : public BerthClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class ACChairCar : public SeatClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    // needs initiate in application
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class Sleeper : public SeatClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};

class SecondSitting : public SeatClass {
    static const float sLoadFactor;     //!< needs initiate in application
    static const bool sIsLuxury;        //!< needs initiate in application

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

};


#endif //RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H
