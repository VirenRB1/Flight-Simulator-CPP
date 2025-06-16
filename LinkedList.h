// CLASS: LinkedList.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the LinkedList class. The LinkedList class is used to represent the linked list of runways in the simulation. The class contains a pointer to the top of the linked list. The class also contains methods to add a node to the front of the linked list, check if there is a free runway, delete an event from the runway linked list based on the runway number, add an event to the runway linked list, and a destructor.
//
//-----------------------------------------

#pragma once

class RunwayNode;
class ActualEvent;

class LinkedList{
    private:
        RunwayNode* top;

    public:
        LinkedList();
        LinkedList(int);
        void addFront(RunwayNode*);
        bool existFreeRunway();
        void deleteEvent(int);
        void addEvent(ActualEvent*);
        ~LinkedList();
};