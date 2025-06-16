// CLASS: RequestEvent.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the RequestEvent class.
//
//-----------------------------------------

#include "RequestEvent.h"
#include "Plane.h"

//Constructor
RequestEvent::RequestEvent(Plane* plane,string action,int request):plane(plane), action(action), requestTime(request) {}

//Returns the start time of the event
int RequestEvent::getStartTime(){
    return requestTime;
}

//Returns the end time of the event
int RequestEvent::getEndTime(){
    return requestTime;
}

//Returns the type of event
string RequestEvent::getEventType(){
    return "RequestEvent";
}

//Returns the action of the plane
string RequestEvent::getAction(){
    return action;
}

//Returns the plane
Plane* RequestEvent::getPlane(){
    return plane;
}

//Prints the event based on the action of the plane
void RequestEvent::printEvent(){
    if(action == "landing"){
        cout<< "TIME: " << requestTime << " -> " << plane->getAirline() << " " << plane->getFlightNum() << " (" << plane->getAtcId() << ") " << plane->getPlaneSize() << " inbound for " << action <<endl;
    }else{
        cout<< "TIME: " << requestTime << " -> " << plane->getAirline() << " " << plane->getFlightNum() << " (" << plane->getAtcId() << ") " << plane->getPlaneSize() << " ready for " << action <<endl;
    }
}

//Destructor
RequestEvent::~RequestEvent(){
    //Nothing to do here as i dont want to delete the plane right now
}

