// CLASS: SmallPlane.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the SmallPlane class.
//
//-----------------------------------------

#include "SmallPlane.h"

//Null Constructor
SmallPlane::SmallPlane() : wakeTime(0) {}

//Constructor with parameters
SmallPlane::SmallPlane(string airline, int flightNum, string size, int id) :wakeTime(0) ,Plane(airline,flightNum,size,id) {}

//Returns the wake time of the plane
int SmallPlane::getWakeTime(){
    return wakeTime;
}