//
// Created by j-tesla on 29/03/21.
//

#include "Gender.h"


Gender::Gender() = default;

Gender::~Gender() = default;

template<> const string Gender::Male::sName = "Male";       //! name defined as static constant

template<> const string Gender::Female::sName = "Female";       //! name defined as static constant

template<>
bool Gender::Male::IsMale() const { return true; }

template<>
bool Gender::Female::IsMale() const { return false; }