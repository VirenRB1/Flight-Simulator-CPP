// CLASS: PriorityQueue.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This class contains the implementation of the PriorityQueue class. The PriorityQueue class is used to represent the priority queue of events in the simulation. The class contains a pointer to the top of the priority queue. The class also contains methods to add an event to the priority queue, get the event at the top of the priority queue, and remove the event at the top of the priority queue.
//
//-----------------------------------------

#include "PriorityQueue.h"
#include "EventNode.h"
#include "Event.h"

//Null Constructor
PriorityQueue::PriorityQueue() : top(nullptr) {}

//pushes an event to the priority queue and sorts it based on the start time of the event
void PriorityQueue::push(Event * myEvent){
    //if the priority queue is empty, add the event to the top
    if(top == nullptr){
        top = new EventNode(myEvent);
    }else{
        //get the start time of the event
        int startTime = myEvent->getStartTime();
        bool found = false;
        EventNode *curr = top;
        EventNode *prev = nullptr;
        while(curr != nullptr && !found){
            Event * currEvent = curr->getEvent();
            //if the start time of the event is less than the start time of the current event, add the event before the current event
            if(startTime < currEvent->getStartTime()){
                EventNode * nextNode = new EventNode(myEvent,curr);
                if(prev != nullptr){
                    prev->setNext(nextNode);
                }else{
                    top = nextNode;
                }
                
                found = true;
            }
            prev = curr;
            curr = curr->getNext();
        }
        //if the event was not added, add it to the end of the priority queue
        if(!found){
            EventNode* nextNode = new EventNode(myEvent);
            prev->setNext(nextNode);
        }
    }
}

//returns the event at the top of the priority queue
Event * PriorityQueue::peek(){
    Event * result = nullptr;
    if(top != nullptr){
        result = top->getEvent();
    }
    return result;
}

//removes the event at the top of the priority queue and returns it
//returning the EventNode pointer instead of the Event pointer so that the EventNode can be deleted
EventNode* PriorityQueue::pop(){
    EventNode* result = top;
    if(result != nullptr){
        top = top->getNext();
    }
    return result;

}