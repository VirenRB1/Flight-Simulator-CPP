// CLASS: Plane.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the Plane class.
//
//-----------------------------------------
#include "Plane.h"

//Null Constructor
Plane::Plane() : airline(""), flightNum(0), size(""), atcId(0){}

//Constructor with parameters
Plane::Plane(string myAirline,int flightNumber,string mySize, int id) : airline(myAirline) ,flightNum(flightNumber) ,size(mySize),atcId(id) {}

//Returns the size of the plane
string Plane::getPlaneSize(){
    return size;
}

//Returns the atc id of the plane
int Plane::getAtcId(){
    return atcId;
}

//Returns the airline of the plane
string Plane::getAirline(){
    return airline;
}

//Returns the flight number of the plane
int Plane::getFlightNum(){
    return flightNum;
}

//Destructor, is empty since there is no dynamic memory allocation
Plane::~Plane(){
    
}