// CLASS: PriorityQueue.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the PriorityQueue class. The PriorityQueue class is used to represent the priority queue of events in the simulation. The class contains a pointer to the top of the priority queue. The class also contains methods to add an event to the priority queue, get the event at the top of the priority queue, and remove the event at the top of the priority queue.
//
//-----------------------------------------
#pragma once

class EventNode;
class Event;

class PriorityQueue{
    private:
        EventNode* top;

    public:
        PriorityQueue();
        void push(Event *);
        Event * peek();
        EventNode* pop();
};