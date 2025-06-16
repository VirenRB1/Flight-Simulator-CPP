// CLASS: CompletedEvent.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the CompletedEvent class.
//
//-----------------------------------------

#include "CompletedEvent.h"
#include "Plane.h"

//Null Constructor
CompletedEvent::CompletedEvent() : plane(nullptr) , runway(-1), time(-1){}

//Constructor with parameters
CompletedEvent::CompletedEvent(Plane* myPlane,int runwayNum,int myTime) : plane(myPlane) , runway(runwayNum) , time(myTime){}

//Returns the start time of the event
int CompletedEvent::getStartTime(){
    return time;
}

//Returns the end time of the event
int CompletedEvent::getEndTime(){
    return time;
}

//Returns the runway number
int CompletedEvent::getRunway(){
    return runway;
}

//Returns the type of event
string CompletedEvent::getEventType(){
    return "CompletedEvent";
}

//Returns the action of the plane
string CompletedEvent::getAction(){
    return "Completed";
}

//Returns the plane
Plane* CompletedEvent::getPlane(){
    return plane;
}

//Prints the event
void CompletedEvent::printEvent(){
    cout<< "TIME: " << getStartTime() << " -> " << plane->getAirline()<<" " << plane->getFlightNum() << " (" <<plane->getAtcId() << ") " << plane->getPlaneSize() << " has cleared the runway " << runway << endl;
}

//Destructor
CompletedEvent::~CompletedEvent(){
    //delete CompleteEvent then delete plane
    delete plane;
}