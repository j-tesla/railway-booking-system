//
// Created by j-tesla on 31/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_DIVYAANG_H
#define RAILWAYBOOKINGSYSTEM_DIVYAANG_H

#include <string>
using std::string;

template<typename T>
class DivyaangTypes;       //! Forward declaration of templatized class

/**
    * Abstract base class to disabilty categories
    */
class Divyaang {
    /**
     * tag type to initiate template
     */
    struct BlindType {
    };
    /**
     * tag type to initiate template
     */
    struct OrthopaedicallyHandicappedType {
    };
    /**
     * tag type to initiate template
     */
    struct CancerPatientsType {
    };
    /**
     * tag type to initiate template
     */
    struct TBPatientsType {
    };

protected:
    Divyaang();

    virtual ~Divyaang();

public:

    virtual const string &GetName() const = 0;

    using Blind = DivyaangTypes<BlindType>;
    using OrthopaedicallyHandicapped = DivyaangTypes<OrthopaedicallyHandicappedType>;
    using CancerPatients = DivyaangTypes<CancerPatientsType>;
    using TBPatients = DivyaangTypes<TBPatientsType>;
};

template<typename T>
class DivyaangTypes : Divyaang {
    static const string sName;      //! respective name of the gender

    DivyaangTypes();

    ~DivyaangTypes() override;

public:
    static const Divyaang &Type();

private:
    const string &GetName() const override;
};

template<typename T>
DivyaangTypes<T>::DivyaangTypes(): Divyaang() {
}

template<typename T>
const Divyaang &DivyaangTypes<T>::Type() {
    static const DivyaangTypes<T> sObject;
    return sObject;
}

template<typename T>
const string &DivyaangTypes<T>::GetName() const {
    return sName;
}

template<typename T>
DivyaangTypes<T>::~DivyaangTypes() = default;


#endif //RAILWAYBOOKINGSYSTEM_DIVYAANG_H
