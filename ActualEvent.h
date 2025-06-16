// CLASS: ActualEvent.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the ActualEvent class. The ActualEvent class is a subclass of the Event class and is used to represent the actual events that occur in the simulation. The class contains the plane, the action of the plane (landing or takeoff), the runway number, the start time of the event, and the end time of the event. The class also contains methods to set the end time of the event, set the start and end time of the event, find the time it takes to clear the runway, set the runway number, get the runway number, get the start and end time of the event, get the type of event, get the action of the plane, get the plane, print the event, and a destructor.
//
//-----------------------------------------

#pragma once
#include "Event.h"
//Forward reference to Plane class
class Plane;


class ActualEvent: public Event{
    private:
        Plane *plane;
        string action;
        int runway;
        int start;
        int end;
    
    public:
        ActualEvent(Plane*,string,int);
        int findClearingTime(); 
        int setEndTime(); 
        void setActualStartEnd(int);
        void setRunway(int);
        int getRunway();
        int getStartTime() override;
        int getEndTime() override;
        string getEventType() override;
        string getAction() override;
        Plane* getPlane() override;
        void printEvent() override;
        ~ActualEvent();
};