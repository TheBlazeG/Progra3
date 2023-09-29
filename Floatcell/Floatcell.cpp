//
// Created by santi on 9/28/2023.
//
#include "Floatcell.h"
// Default constructor
Floatcell::Floatcell(float newValue) : storedValue(newValue) {}

// Copy constructor
Floatcell::Floatcell(const Floatcell &rhs) : storedValue(rhs.storedValue) {}

// Move constructor
Floatcell::Floatcell(Floatcell &&rhs) noexcept : storedValue(rhs.storedValue) {
    // rhs.storedValue = 0;
}
// Copy assignment operator
Floatcell &Floatcell::operator=(const Floatcell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Remove Move assignment operator
Floatcell &Floatcell::operator=(Floatcell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Removed overloaded assignment operator to accept any data

// Overloaded assignment operator to accept only integer data
Floatcell &Floatcell::operator=(float rhs) {
    storedValue = rhs;
    return *this;}