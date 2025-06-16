// CLASS: SmallPlane.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the SmallPlane class. The SmallPlane class is a subclass of the Plane class and is used to represent the small planes in the simulation. The class contains the wake time of the plane. The class also contains a constructor with parameters, a method to get the wake time of the plane
//
//-----------------------------------------
#pragma once
#include "Plane.h"

class SmallPlane : public Plane
{
    private:
        int wakeTime;
    
    public:
        SmallPlane();
        SmallPlane(string,int,string,int);
        int getWakeTime() override;
        //Will make use of the default destructor since there is no dynamic memory allocation
};
