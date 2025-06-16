// CLASS: LargePlane.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the LargePlane class. 
//
//-----------------------------------------

#include "LargePlane.h"

//Null Constructor
LargePlane::LargePlane() : wakeTime(1) {}

//Constructor with parameters
LargePlane::LargePlane(string airline, int flight, string size, int id) : wakeTime(1) ,Plane(airline,flight,size,id) {}

//Returns the wake time of the plane
int LargePlane::getWakeTime(){
    return wakeTime;
}