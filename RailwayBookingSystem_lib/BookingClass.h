//
// Created by j-tesla on 02/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H
#define RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H


#include <string>
#include <ostream>


using std::string;

class BookingClass {
    BookingClass(const BookingClass &other);

protected:
    BookingClass();

    virtual ~BookingClass();

public:
    virtual string GetName() const = 0;

    virtual bool IsSitting() const = 0;

    virtual bool IsAc() const = 0;

    virtual bool IsLuxury() const = 0;

    virtual unsigned GetNumberOfTiers() const = 0;

    virtual float GetLoadFactor() const = 0;

    virtual void SetLoadFactor(float loadFactor) const = 0;

    virtual bool operator==(const BookingClass &other) const;

    friend std::ostream &operator<<(std::ostream &os, const BookingClass &aClass);
};

class SeatClass : public BookingClass {
public:
    bool IsSitting() const override;
};

class BerthClass : public BookingClass {
public:
    bool IsSitting() const override;
};

class ACFirstClass : public BerthClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class AC2Tier : public BerthClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class FirstClass : public BerthClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class AC3Tier : public BerthClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class ACChairCar : public SeatClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class Sleeper : public SeatClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};

class SecondSitting : public SeatClass {
    static float sLoadFactor;

public:
    static const BookingClass &Type();

    string GetName() const override;

    bool IsAc() const override;

    bool IsLuxury() const override;

    unsigned int GetNumberOfTiers() const override;

    float GetLoadFactor() const override;

    void SetLoadFactor(float loadFactor) const override;
};


#endif //RAILWAYBOOKINGSYSTEM_BOOKINGCLASS_H
