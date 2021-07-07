/**
 * @file BookingClass.h
 * @brief contains abstract class BookingClass and base classes
 * @author Jayanth PSY - 19CS10068
 */


#ifndef RAILWAYBOOKINGSYSTEM_BOOKINGCLASSES_H
#define RAILWAYBOOKINGSYSTEM_BOOKINGCLASSES_H

#include <ostream>
#include <string>


using std::string;


template<typename T>
class BookingClassTypes;      //! Forward declaration of templatized class

/**
 * Abstract base class to booking classes
 */
class BookingClass {


    /**
     * tag type to initiate template
     */
    struct ACFirstClassType {
    };
    /**
     * tag type to initiate template
     */
    struct ExecutiveChairCarType {
    };
    /**
     * tag type to initiate template
     */
    struct AC2TierType {
    };
    /**
     * tag type to initiate template
     */
    struct FirstClassType {
    };
    /**
     * tag type to initiate template
     */
    struct AC3TierType {
    };
    /**
     * tag type to initiate template
     */
    struct ACChairCarType {
    };
    /**
     * tag type to initiate template
     */
    struct SleeperType {
    };
    /**
     * tag type to initiate template
     */
    struct SecondSittingType {
    };

protected:
    BookingClass();

    virtual ~BookingClass() noexcept;

public:
    virtual const string &GetName() const = 0;

    virtual float GetFareLoadFactor() const = 0;

    virtual float GetReservationCharge() const = 0;

    virtual bool IsSitting() const = 0;

    virtual bool IsAC() const = 0;

    virtual unsigned GetNumberOfTiers() const = 0;

    virtual bool IsLuxury() const = 0;

    virtual float GetMinimumTatkalCharges() const = 0;

    virtual float GetMaximumTatkalCharges() const = 0;

    virtual unsigned GetMinimumDistanceForTatkalCharge() const = 0;

    virtual float GetTatkalChargeRate() const = 0;

    virtual float GetBlindConcessionFactor() const = 0;

    virtual float GetOrthopaedicallyHandicappedConcessionFactor() const = 0;

    virtual float GetCancerPatientsConcessionFactor() const = 0;

    virtual float GetTBPatientsConcessionFactor() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const BookingClass &aClass);

    using ACFirstClass = BookingClassTypes<ACFirstClassType>;
    using ExecutiveChairCar = BookingClassTypes<ExecutiveChairCarType>;
    using AC2Tier = BookingClassTypes<AC2TierType>;
    using FirstClass = BookingClassTypes<FirstClassType>;
    using AC3Tier = BookingClassTypes<AC3TierType>;
    using ACChairCar = BookingClassTypes<ACChairCarType>;
    using Sleeper = BookingClassTypes<SleeperType>;
    using SecondSitting = BookingClassTypes<SecondSittingType>;
};

template<typename T>
class BookingClassTypes : public BookingClass {
    static const string sName;
    static const bool sIsSeating;
    static const bool sIsAC;
    static const unsigned sNumberOfTiers;
    static const float sFareLoadFactor;        //! Need to define in application code
    static const bool sIsLuxury;        //! Need to define in application code
    static const float sReservationCharge;        //! Need to define in application code
    static const float sMinimumTatkalCharges;        //! Need to define in application code
    static const float sMaximumTatkalCharges;        //! Need to define in application code
    static const unsigned sMinimumDistanceForTatkalCharge;        //! Need to define in application code
    static const float sTatkalChargeRate;       //! Need to define in application code
    static const float sBlindConcessionFactor;        //! Need to define in application code
    static const float sOrthopaedicallyHandicappedConcessionFactor;        //! Need to define in application code
    static const float sCancerPatientsConcessionFactor;        //! Need to define in application code
    static const float sTBPatientsConcessionFactor;        //! Need to define in application code


    BookingClassTypes();

public:
    ~BookingClassTypes() noexcept override;

    static const BookingClass &Type();

    const string &GetName() const override;

    float GetFareLoadFactor() const override;

    float GetReservationCharge() const override;

    bool IsSitting() const override;

    bool IsAC() const override;

    unsigned GetNumberOfTiers() const override;

    bool IsLuxury() const override;

    float GetMinimumTatkalCharges() const override;

    float GetMaximumTatkalCharges() const override;

    unsigned GetMinimumDistanceForTatkalCharge() const override;

    float GetTatkalChargeRate() const override;

    float GetBlindConcessionFactor() const override;

    float GetOrthopaedicallyHandicappedConcessionFactor() const override;

    float GetCancerPatientsConcessionFactor() const override;

    float GetTBPatientsConcessionFactor() const override;

};

template<typename T>
BookingClassTypes<T>::BookingClassTypes(): BookingClass() {
}

template<typename T>
const BookingClass &BookingClassTypes<T>::Type() {
    static const BookingClassTypes<T> sObject;

    return sObject;
}

template<typename T>
float BookingClassTypes<T>::GetFareLoadFactor() const {
    return sFareLoadFactor;
}

template<typename T>
float BookingClassTypes<T>::GetReservationCharge() const {
    return sReservationCharge;
}

template<typename T>
bool BookingClassTypes<T>::IsSitting() const {
    return sIsSeating;
}

template<typename T>
bool BookingClassTypes<T>::IsAC() const {
    return sIsAC;
}

template<typename T>
unsigned BookingClassTypes<T>::GetNumberOfTiers() const {
    return sNumberOfTiers;
}

template<typename T>
bool BookingClassTypes<T>::IsLuxury() const {
    return sIsLuxury;
}

template<typename T>
float BookingClassTypes<T>::GetMinimumTatkalCharges() const {
    return sMinimumTatkalCharges;
}

template<typename T>
float BookingClassTypes<T>::GetMaximumTatkalCharges() const {
    return sMaximumTatkalCharges;
}

template<typename T>
unsigned BookingClassTypes<T>::GetMinimumDistanceForTatkalCharge() const {
    return sMinimumDistanceForTatkalCharge;
}

template<typename T>
float BookingClassTypes<T>::GetTatkalChargeRate() const {
    return sTatkalChargeRate;
}

template<typename T>
float BookingClassTypes<T>::GetBlindConcessionFactor() const {
    return sBlindConcessionFactor;
}

template<typename T>
float BookingClassTypes<T>::GetOrthopaedicallyHandicappedConcessionFactor() const {
    return sOrthopaedicallyHandicappedConcessionFactor;
}

template<typename T>
float BookingClassTypes<T>::GetCancerPatientsConcessionFactor() const {
    return sCancerPatientsConcessionFactor;
}

template<typename T>
float BookingClassTypes<T>::GetTBPatientsConcessionFactor() const {
    return sTBPatientsConcessionFactor;
}

template<typename T>
const string &BookingClassTypes<T>::GetName() const {
    return sName;
}

template<typename T>
BookingClassTypes<T>::~BookingClassTypes() noexcept = default;


#endif //RAILWAYBOOKINGSYSTEM_BOOKINGCLASSES_H
