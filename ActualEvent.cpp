// CLASS: ActualEvent.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the ActualEvent class.
//
//-----------------------------------------

#include "ActualEvent.h"
#include "Plane.h"

//Constructor
ActualEvent::ActualEvent(Plane* myPlane,string action,int beginTime): plane(myPlane), action(action), start(beginTime) , end(setEndTime()), runway(-1){}

//Sets the end time of the event based on the start time and the time it takes to clear the runway
int ActualEvent::setEndTime(){
    int clearingTime = findClearingTime();
    return start + clearingTime;

}
//Sets the start and end time of the event based on the time it takes to clear the runway
//This is used when the event is created and the start time is not known eg when added to the landing and takeoff queues
void ActualEvent::setActualStartEnd(int time){
    start = time;
    end = start + findClearingTime();
}

//Finds the time it takes to clear the runway based on the action of the plane
int ActualEvent::findClearingTime(){
    int totalTime = 0;
    int wake = plane->getWakeTime();
    int landingDecent = 2;
    int leaveRunway = 1;
    if(action == "landing"){
        totalTime = landingDecent + leaveRunway + wake;
    }else{
        totalTime = leaveRunway + wake;
    }
        
    return totalTime;
}

//Returns the runway number
int ActualEvent::getRunway(){
    return runway;
}

//Sets the runway number
void ActualEvent::setRunway(int num){
    runway = num;
}

//Returns the start time of the event
int ActualEvent::getStartTime(){
    return start;
}

//Returns the end time of the event
int ActualEvent::getEndTime(){
    return end;
}

//Returns the type of event
string ActualEvent::getEventType(){
    return "ActualEvent";
}

//Returns the action of the plane  (landing or takeoff)
string ActualEvent::getAction(){
    return action;
}

//Returns the plane
Plane* ActualEvent::getPlane(){
    return plane;
}

//Prints the event
void ActualEvent::printEvent(){
    cout<< "TIME: " << getStartTime() << " -> " << plane->getAirline()<<" " << plane->getFlightNum() << " (" <<plane->getAtcId() << ") " << plane->getPlaneSize() << " cleared for " << action << " on runway " << runway <<". (time req. for " << action << ": " << end - start <<")" << endl;

}

//Destructor
ActualEvent::~ActualEvent(){
    //nothing to do here as i dont want to delete the plane right now
}