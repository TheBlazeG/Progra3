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


```c++

//si no esta definida la clase entra dentro de este if

#ifndef FLOATCELL_H

//se comienza a definir la clase

#define FLOATCELL_H

  

class FloatCell {

//miembros públicos que pueden ser accesados fuera de la clase

public:

//este constructor implícito actúa cuando no se le da valor al inicializar el objeto (corregí el código como nos dijo)

    Float(float newValue = 0);

//este constructor se utiliza cuando si se le asigna un valor al objeto, y con esto se le asigna

    explicit FloatCell(const FloatCell &rhs);

//Funciona para asignar la dirección de memoria de los datos del lado derecho

    explicit FloatCell(FloatCell &&rhs) noexcept;

//este es el destructor, se puede llamar manualmente para borrar news por ejemplo y también se llama automáticamente cuando un valor se deja de utilizar con el propósito de liberar recursos.

    ~FloatCell() = default;

  
//se establecen los operadores de copia y mover 
    FloatCell &operator=(const FloatCell &rhs);

    FloatCell &operator=(FloatCell &&rhs) noexcept;

  

    // Overloaded assignment operator to accept primitive float
    //se sobrecarga el operador para aceptar datos de tipo flotante utilizando el =

    FloatCell &operator=(int rhs);

  
//función para obtener valores
    int getValue() const;
//función para asignar valores enteros
    void setValue(int newValue);

  

private:
//variable en la que se guarda el valor entero
    int storedValue;

};

  

//final del if que actua si no está definido

#endif  // INTCELL_H

```
