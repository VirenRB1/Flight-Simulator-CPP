// CLASS: RequestEvent.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the RequestEvent class. The RequestEvent class is a subclass of the Event class and is used to represent the request events that occur in the simulation. The class contains the plane, the action of the plane (landing or takeoff), and the start time of the event. The class also contains methods to get the start time, end time, event type, action, plane, print the event, and a destructor.
//
//-----------------------------------------
#pragma once
#include "Event.h"
class Plane;

class RequestEvent: public Event{
    private:
        Plane *plane;
        string action;
        int requestTime;
    
    public:
        RequestEvent(Plane*,string,int);
        int getStartTime() override;
        int getEndTime() override;
        string getEventType() override;
        string getAction() override;
        Plane* getPlane() override;
        void printEvent() override;
        ~RequestEvent();
};