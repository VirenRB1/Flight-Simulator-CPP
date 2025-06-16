// CLASS: RunwayNode.h
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the declaration of the RunwayNode class. The RunwayNode class is used to represent the nodes of the linked list of runways in the simulation. The class contains a pointer to an ActualEvent object, the runway number, and a pointer to the next node. The class also contains methods to get and set the event, get and set the runway number, get and set the next node.
//
//-----------------------------------------
#pragma once

class ActualEvent;

class RunwayNode{
    private:
        ActualEvent * event;
        int runwayNum;
        RunwayNode* next;

    public:
        RunwayNode(int);
        int getRunwayNum();
        void setEvent(ActualEvent*);
        ActualEvent* getEvent();
        void setNext(RunwayNode*);
        RunwayNode* getNext();


};