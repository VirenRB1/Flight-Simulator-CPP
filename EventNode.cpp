// CLASS: EventNode.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the EventNode class. The EventNode class is used to represent the nodes of the priority queue. The class contains a pointer to an Event object and a pointer to the next node. The class also contains methods to get and set the event, get and set the next node, and a destructor.
//
//-----------------------------------------

#include "EventNode.h"
#include "Event.h"

//Constructor
EventNode:: EventNode(Event* myEvent) : event(myEvent) , next(nullptr) {}

//Constructor
EventNode:: EventNode(Event* myEvent,EventNode* nextNode) : event(myEvent) , next(nextNode) {}

//Returns the event
Event* EventNode::getEvent(){
    return event;
}

//Sets the event
void EventNode::setEvent(Event* event){
    event = event;
}

//Sets the next node
void EventNode::setNext(EventNode* node){
    next = node;
}

//Returns the next node
EventNode* EventNode::getNext(){
    return next;
}

//Destructor
EventNode::~EventNode(){

}
