//
// Created by j-tesla on 29/03/21.
//

#ifndef RAILWAYBOOKINGSYSTEM_GENDER_H
#define RAILWAYBOOKINGSYSTEM_GENDER_H

#include <string>


using std::string;


template<typename T>
class GenderTypes;      //! Forward declaration of templatized class

/**
 * Abstract base class to genders
 */
class Gender {

    /**
     * tag type to initiate template
     */
    struct MaleType {
    };
    /**
     * tag type to initiate template
     */
    struct FemaleType {
    };

protected:
    Gender();

    virtual ~Gender();

public:
    virtual const string &GetName() const = 0;

    virtual bool IsMale() const = 0;

    using Male = GenderTypes<MaleType>;
    using Female = GenderTypes<FemaleType>;
};

template<typename T>
class GenderTypes : public Gender {
    static const string sName;      //! respective name of the gender

    GenderTypes();

    ~GenderTypes() override;

public:
    static const Gender &Type();

    const string &GetName() const override;

    bool IsMale() const override;
};

template<typename T>
GenderTypes<T>::GenderTypes(): Gender() {
}

template<typename T>
const Gender &GenderTypes<T>::Type() {
    static const GenderTypes<T> sObject;

    return sObject;
}

template<typename T>
const string &GenderTypes<T>::GetName() const {
    return sName;
}

template<typename T>
GenderTypes<T>::~GenderTypes() = default;


#endif //RAILWAYBOOKINGSYSTEM_GENDER_H
