// CLASS: Plane.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the Plane class. The Plane class is an abstract class that is used to represent the planes in the simulation. The class contains the airline, flight number, size, and atc id of the plane. The class also contains methods to get the wake time of the plane, get the atc id of the plane, get the size of the plane, get the airline of the plane, get the flight number of the plane, and a destructor.
//
//-----------------------------------------

#pragma once
#include <iostream>
using namespace std;


class Plane
{
private:
    string airline;
    int flightNum;
    string size;
    int atcId;

public:
    Plane();
    Plane(string,int,string,int);
    virtual int getWakeTime() = 0;
    virtual int getAtcId();
    virtual string getPlaneSize();
    virtual string getAirline();
    virtual int getFlightNum();
    virtual ~Plane();
};
