// CLASS: RunwayNode.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the RunwayNode class.
//
//-----------------------------------------
#include "RunwayNode.h"
#include "ActualEvent.h"

//Constructor
RunwayNode::RunwayNode(int num) : event(nullptr) , runwayNum(num) , next(nullptr) {}

//getter for the event
ActualEvent* RunwayNode::getEvent(){
    return this->event;
}

//setter for the event
void RunwayNode::setEvent(ActualEvent* myEvent){
    event = myEvent;
}

//getter for the runway number
int RunwayNode::getRunwayNum(){
    return runwayNum;
}

//setter for the next node
void RunwayNode::setNext(RunwayNode* node){
    this->next = node;
}

//getter for the next node
RunwayNode* RunwayNode::getNext(){
    return this->next;
}