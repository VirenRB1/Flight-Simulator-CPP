// CLASS: SuperPlane.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the SuperPlane class. The SuperPlane class is a subclass of the Plane class and is used to represent the super planes in the simulation. The class contains the wake time of the plane. The class also contains a constructor with parameters, a method to get the wake time of the plane
//
//-----------------------------------------
#pragma once
#include "Plane.h"

class SuperPlane : public Plane
{
    private:
        int wakeTime;
    
    public:
        SuperPlane();
        SuperPlane(string,int,string,int);
        int getWakeTime() override;

};