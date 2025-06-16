// CLASS: CompletedEvent.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the CompletedEvent class. The CompletedEvent class is a subclass of the Event class and is used to represent the completed events that occur in the simulation. The class contains the plane, the runway number, the start time of the event. The class also contains methods to get the start, get the type of event, get the action of the plane, get the runway number, get the plane, print the event, and a destructor.
//
//-----------------------------------------
#pragma once
#include "Event.h"
class Plane;

class CompletedEvent : public Event{
    private:
        Plane* plane;
        int runway;
        int time;
    
    public:
        CompletedEvent();
        CompletedEvent(Plane*,int,int);
        int getStartTime();
        int getEndTime();
        string getEventType();
        string getAction();
        int getRunway();
        Plane* getPlane();
        void printEvent();
        Event* processEvent(Event*);
        ~CompletedEvent();
};