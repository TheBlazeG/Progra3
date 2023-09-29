//
// Created by Alumnos on 28/09/2023.
//

#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
DoubleCell::DoubleCell()
:Storedvalue(0.0){}

// Constructor with value
DoubleCell::DoubleCell(double value)
: Storedvalue(value){}

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell& other)
: Storedvalue(other.Storedvalue){}

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell&&  other) noexcept
: Storedvalue(other.Storedvalue){
other.Storedvalue=0;}



// Assignment operator by copy implementacion para copiar valores
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
if (this != &other){
Storedvalue = other.Storedvalue;
}
return *this;
}

// Assignment operator by reference implementacion para mover valores
DoubleCell& DoubleCell::operator=(DoubleCell&& other){
if (this != &other){
Storedvalue = other.Storedvalue;
other.Storedvalue=0;
}
return *this;
}

// Assignment operator for double implementacion de asignacion por = de doubles
DoubleCell& DoubleCell::operator=(double value){
Storedvalue = value;
return *this;
}

// Arithmetic operators
//DoubleCell adding implementacion de suma con doublecells
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding implementacion de suma con DoubleCells
DoubleCell DoubleCell::operator +(double other) const{

return DoubleCell(Storedvalue + other);
}
//primitive double subtraction implementacion de resta con doubles
DoubleCell DoubleCell::operator -(double other) const {

return DoubleCell(Storedvalue - other);
}
//DoubleCell multiplication implementacion de multiplicacion usando doublecells
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication se define la implementacion usando doubles
DoubleCell DoubleCell::operator *(double other) const{

return DoubleCell(Storedvalue * other);}
//DoubleCell division se implementa la division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
if(other.Storedvalue == 0){
throw std::invalid_argument("Division by zero");
}
return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive double division se implementa la division con doubles y se agrega una excepcion en la division por 0
DoubleCell DoubleCell::operator /(double value) const{
if(value == 0){
throw std::invalid_argument("Division by zero");
}
return DoubleCell(Storedvalue / value);
}

// Setters, se utiliza para asignar valores
void DoubleCell::setValue(double newValue) {
Storedvalue = newValue;}

//getter, se utiliza para ver valores de un doublecell
double  DoubleCell::GetValue() const {return Storedvalue;}
//destructor implementation
DoubleCell::~DoubleCell() {

}