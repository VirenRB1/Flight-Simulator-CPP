// CLASS: EventNode.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the EventNode class. The EventNode class is used to represent the nodes of the priority queue. The class contains a pointer to an Event object and a pointer to the next node. The class also contains methods to get and set the event, get and set the next node, and a destructor.
//
//-----------------------------------------

#pragma once
class Event;

class EventNode{

    private:
    Event* event;
    EventNode* next;

    public:
    EventNode(Event*);
    EventNode(Event*,EventNode*);
    Event* getEvent();
    void setEvent(Event*);
    void setNext(EventNode*);
    EventNode* getNext();
    ~EventNode();

};