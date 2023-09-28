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
DoubleCell::DoubleCell(DoubleCell&&  other)
        : Storedvalue(other.Storedvalue){}


// Destructor


// Assignment operator by copy
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference


// Assignment operator for double
DoubleCell& DoubleCell::operator=(double value){
    Storedvalue = value;
    return *this;
}

// Arithmetic operators
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell::operator +(double value) const{

    return DoubleCell(Storedvalue + value);
}
//primitive double subtraction
DoubleCell DoubleCell::operator -(double value) const {

    return DoubleCell(Storedvalue - value);
}
//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const{

    return DoubleCell(Storedvalue * value);}
//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive double division
DoubleCell DoubleCell::operator /(double value) const{
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Setters
void DoubleCell::SetValue(double value){
    Storedvalue = value;
}