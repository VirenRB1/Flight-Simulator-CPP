// CLASS: HeavyPlane.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the HeavyPlane class.
//
//-----------------------------------------

#include "HeavyPlane.h"

//Null Constructor
HeavyPlane::HeavyPlane() : wakeTime(2) {}

//Constructor with parameters
HeavyPlane::HeavyPlane(string airline, int flight, string size, int id) :wakeTime(2) ,Plane(airline,flight,size,id) {}

//Returns the wake time of the plane
int HeavyPlane::getWakeTime(){
    return wakeTime;
}