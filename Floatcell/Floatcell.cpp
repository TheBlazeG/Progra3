//
// Created by santi on 9/28/2023.
//
#include "Floatcell.h"

//Se establece el constructor normal, en el cual se le puede asignar un valor al objeto
Floatcell::Floatcell(float newValue) : storedValue(newValue) {}
// En este constructor se establece la posibilidad de copiar valores de otro objeto siendo independiente del original

// Copy constructor
Floatcell::Floatcell(const Floatcell &rhs) : storedValue(rhs.storedValue) {}
//Este constructor ayuda a copiar la dirección de memoria de un r valor asignado a un l valor de manera que si se cambia el original también cambiará este

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
// Aqui se establece el operador= para  copiar valores de otros intcell


// Remove Move assignment operator
Floatcell &Floatcell::operator=(Floatcell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}
//en este operador se mueve el valor del lado derecho y al mismo tiempo se establece en 0 el del lado derecho
// Removed overloaded assignment operator to accept any data

// Overloaded assignment operator to accept only integer data
Floatcell &Floatcell::operator=(float rhs) {
    storedValue = rhs;
    return *this;}

float  FloatCell::getValue() const {
    return  storeValue;
}

void FloatCell::SetValue(float newValue) {
    storeValue = newValue;
} //get y set implementado