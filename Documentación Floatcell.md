```c++
#include "Floatcell.h"
//Se establece el constructor normal, en el cual se le puede asignar un valor al objeto

// Default constructor
Floatcell::Floatcell(float newValue) : storedValue(newValue) {}

// En este constructor se establece la posibilidad de copiar valores de otro objeto siendo independiente del original

// Copy constructor
Floatcell::Floatcell(const Floatcell &rhs) : storedValue(rhs.storedValue) {}

//Este constructor ayuda a copiar la dirección de memoria de un r valor asignado a un l valor de manera que si se cambia el original también cambiará este

// Move constructor
Floatcell::Floatcell(Floatcell &&rhs) noexcept : storedValue(rhs.storedValue) {
    // rhs.storedValue = 0;
}

// Aqui se establece el operador= para  copiar valores de otros intcell

// Copy assignment operator
Floatcell &Floatcell::operator=(const Floatcell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

//en este operador se mueve el valor del lado derecho y al mismo tiempo se establece en 0 el del lado derecho

// Remove Move assignment operator
Floatcell &Floatcell::operator=(Floatcell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Removed overloaded assignment operator to accept any data

//se sobrecarga el operador igual para recibir unicamente datos de tipo entero

// Overloaded assignment operator to accept only integer data
Floatcell &Floatcell::operator=(float rhs) {
    storedValue = rhs;
    return *this;}
```