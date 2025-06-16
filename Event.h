// CLASS: Event.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the Event class. The Event class is an abstract class that is used to represent the events that occur in the simulation. It has abstract methods to get the start time, end time, event type, action, plane, and print the event.
//
//-----------------------------------------
#pragma once
#include <iostream>
using namespace std;
class Plane;

class Event{
    public:
        virtual int getStartTime() = 0;
        virtual int getEndTime() = 0;
        virtual string getEventType() = 0;
        virtual string getAction() = 0;
        virtual Plane* getPlane() = 0;
        virtual void printEvent() = 0;
};