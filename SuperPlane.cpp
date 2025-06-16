// CLASS: SuperPlane.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the SuperPlane class.
//
//-----------------------------------------
#include "SuperPlane.h"

//Null Constructor
SuperPlane::SuperPlane() : wakeTime(3), Plane() {}

//Constructor with parameters
SuperPlane::SuperPlane(string airline, int flightNum, string size, int id) :wakeTime(3) ,Plane(airline,flightNum,size,id) {}

//Returns the wake time of the plane
int SuperPlane::getWakeTime(){
    return wakeTime;
}

