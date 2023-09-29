//
// Created by Alumnos on 28/09/2023.
//

#ifndef EXAMEN1_DOUBLECELL_H
#define EXAMEN1_DOUBLECELL_H

class DoubleCell {
public:
// Default constructor definicion para doublecell sin valor al inicializar en parentesis
DoubleCell();
// Constructor with value definicion con valor double en el parentecis
explicit DoubleCell(double value);

// Copy constructor definicion de copia
DoubleCell(const DoubleCell& other);

//Reference constructor definicion de referencia
DoubleCell(DoubleCell&&other) noexcept;
// Destructor
~DoubleCell();

// Assignment operator by copy definicion de operador = por copia
DoubleCell& operator=(const DoubleCell & other);
// Assignment operator by reference definicion de operador = por referencia
DoubleCell& operator=(DoubleCell&& other);

// Assignment operator for double definicion de operador = para double
DoubleCell& operator=(double value);

// Arithmetic operators definicion de operadores aritmeticos con doublecells y doubles como -+* y /
DoubleCell operator +(const DoubleCell& other) const;
DoubleCell operator +(const double other) const;
DoubleCell operator -(const DoubleCell& other) const;
DoubleCell operator -(const double other) const;
DoubleCell operator *(const DoubleCell& other) const;
DoubleCell operator *(const double other) const;
DoubleCell operator /(const DoubleCell& other) const;
DoubleCell operator /(const double other) const;

// Setters
void setValue(double newValue);
// Getters

double GetValue() const;


private:
double Storedvalue;

};




#endif //EXAMEN1_DOUBLECELL_H
