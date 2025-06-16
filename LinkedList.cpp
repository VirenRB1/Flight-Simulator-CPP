// CLASS: LinkedList.cpp
//
// Author: Viren Ravji Bhanderi, 7976692
//
// REMARKS: This file contains the implementation of the LinkedList class.
//
//-----------------------------------------

#include "LinkedList.h"
#include "RunwayNode.h"
#include "ActualEvent.h"

//Null Constructor
LinkedList::LinkedList() : top(nullptr) {}

//Constructor with parameters. Creates a linked list with num nodes
LinkedList::LinkedList(int num) : top(nullptr){

    while(num > 0){
        RunwayNode * runway = new RunwayNode(num);
        this->addFront(runway);
        num--;
    }
}

//Adds a node to the front of the linked list
void LinkedList:: addFront(RunwayNode* node){
    if(top == nullptr){
        top = node;
    }else{
        node->setNext(top);
        top = node;
    }
}

//Checks if there is a free runway
bool LinkedList::existFreeRunway(){
    bool result = false;
    RunwayNode * runway = top;

    while(runway != nullptr && !result){
        if(runway->getEvent() == nullptr){
            result = true;
        }
        runway = runway->getNext();
    }
    return result;
}

//Deletes the event from the runway linked list based on the runway number
void LinkedList::deleteEvent(int runwayNo){
    RunwayNode* node = top;
    int curr = 1;
    while(curr != runwayNo){
        node = node->getNext();
        curr++;
    }
    //clean up the event
    delete node->getEvent();
    node->setEvent(nullptr);
}

//Adds an event to the runway linked list and sets the runway number of the event
void LinkedList::addEvent(ActualEvent* myEvent){
    RunwayNode* node = top;
    bool done = false;
    int curr = 1;

    while(node != nullptr && !done){
        if(node->getEvent() == nullptr){
            myEvent->setRunway(node->getRunwayNum());
            node->setEvent(myEvent);
            done = true;
        }
        node = node->getNext();
    }
}

//Destructor, cleans up the linked list
LinkedList:: ~LinkedList(){
    RunwayNode* curr = top;
    RunwayNode* prev = nullptr;
    while(curr != nullptr){
        prev = curr;
        curr = curr->getNext();
        delete prev;
    }
}