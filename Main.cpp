//-----------------------------------------
// NAME		: Viren Ravji Bhanderi
// STUDENT NUMBER	: 7976692
// COURSE		: COMP 2150
// INSTRUCTOR	: Olivier Tremblay-Savard
// ASSIGNMENT	: Assignment 2
// QUESTION	: Question #1
//
// REMARKS: This program reads in a file of plane requests and simulates the landing and takeoff of planes on a set number of runways that are determined by the user. The program also uses two other priority queues to keep track of the planes that are waiting to land and takeoff. The program finds out the total time wasted by the planes waiting to land and takeoff.
//
//-----------------------------------------

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)

#include "SmallPlane.h"
#include "LargePlane.h"
#include "HeavyPlane.h"
#include "SuperPlane.h"

#include "RequestEvent.h"
#include "ActualEvent.h"
#include "CompletedEvent.h"

#include "PriorityQueue.h"
#include "LinkedList.h"

#include "EventNode.h"

// Function Prototypes
Plane *createPlane(string, int, string, int);
Event *processInput();
void processSimulation();
void processRequestEvent(RequestEvent *);
void processActualEvent(ActualEvent *);
void processCompletedEvent(CompletedEvent *);
ActualEvent *convertToActual(RequestEvent *);
CompletedEvent *convertToCompleted(ActualEvent *);

static int flightId = 1;						   // used to give each plane a unique id
PriorityQueue *mySimulation = new PriorityQueue(); // priority queue to keep track of the events
PriorityQueue *landingQueue = new PriorityQueue(); // priority queue to keep track of the planes waiting to land
PriorityQueue *takeOffQueue = new PriorityQueue(); // priority queue to keep track of the planes waiting to takeoff
LinkedList *runways;							   // linked list to keep track of the runways will be created in main
static int globalTime = 0;						   // used to keep track of the time in the simulation
static int waitTime = 0;						   // used to keep track of the total time wasted by the planes

ifstream inputFile; // input file
static string line; // used to read in the lines from the file

int main(int argc, char *argv[])
{

	string filename = argv[1];
	int numRunways = stoi(argv[2]);
	runways = new LinkedList(numRunways); // creating the linked list of runways. It will have as many nodes as the number of runways
	//
	// Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	inputFile.open(filename);		   // opening the file for reading
	Event *currEvent = processInput(); // parsing the first line of the file
	if (currEvent != nullptr)
	{
		mySimulation->push(currEvent); // adding the first event to the priority queue
	}

	// Starting the simulation. it will keep running until the priority queue is empty
	processSimulation();

	// cleaning up
	delete mySimulation;
	delete landingQueue;
	delete takeOffQueue;
	delete runways;
	inputFile.close();
	// printing the total number of runways and the total time wasted by the planes
	cout << "The total Number of runways is: " << numRunways << ".\nTotal Time wasted by planes is: " << waitTime << " Minutes." << endl;
	return 0;
}

//------------------------------------------------------
// processInput()
// PURPOSE:  Processes the input line by line and creates a RequestEvent object for each line
// PARAMETERS: None
// Returns: Event* - a pointer to the RequestEvent object created
//
//------------------------------------------------------
Event *processInput()
{
	Event *currEvent = nullptr;
	if (getline(inputFile, line))
	{							// gets the next line from the file and saves it in 'line', if there is one
		stringstream sst(line); // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int time = 0;
		string callSign = "";
		int flightNum = 0;
		string size = "";
		string requestType = "";

		// cout<< line << endl;

		sst >> token;		// grabbing the next token (reading time)
		time = stoi(token); // converting time (string format) to an int
		sst >> callSign;	// grabbing the next token (reading call sign)
		sst >> token;		// grabbing the next token (reading flight number)
		flightNum = stoi(token);
		sst >> size;		// grabbing the next token (reading plane size)
		sst >> requestType; // grabbing the next token (reading request type, either landing or takeoff)

		Plane *myPlane = createPlane(callSign, flightNum, size, flightId);
		currEvent = new RequestEvent(myPlane, requestType, time);
	}

	return currEvent;
}

//------------------------------------------------------
// createPlane(string,int,string,int)
// PURPOSE:  Creates a plane object based on the parameters passed in
// PARAMETERS: string callSign - the call sign of the plane
//             int flightNum - the flight number of the plane
//             string size - the size of the plane
//             int id - the id of the plane
// Returns: Plane* - a pointer to the plane object created
//
//------------------------------------------------------
Plane *createPlane(string callSign, int flightNum, string size, int id)
{
	Plane *result;

	// creating the plane based on the size
	if (size == "small")
	{
		result = new SmallPlane(callSign, flightNum, size, id);
	}
	else if (size == "large")
	{
		result = new LargePlane(callSign, flightNum, size, id);
	}
	else if (size == "heavy")
	{
		result = new HeavyPlane(callSign, flightNum, size, id);
	}
	else
	{
		result = new SuperPlane(callSign, flightNum, size, id);
	}
	// incrementing the flight id so that the next plane has a unique id
	flightId++;
	return result;
}

//------------------------------------------------------
// processSimulation()
// PURPOSE: Processes the simulation by popping the top event from the priority queue and calling the appropriate function based on the type of event
// PARAMETERS: None
// Returns: None
//
//------------------------------------------------------
void processSimulation()
{
	// get the top event from the priority queue
	EventNode *top = mySimulation->pop();
	if (top != nullptr)
	{
		Event *topEvent = top->getEvent();
		// once i have the event, i can delete the node
		delete top;
		// get the type of the event
		string eventType = topEvent->getEventType();
		// set the global time to the start time of the top event
		globalTime = topEvent->getStartTime();

		// based on the type of event, call the appropriate function
		if (eventType == "RequestEvent")
		{
			RequestEvent *myEvent = dynamic_cast<RequestEvent *>(topEvent);
			if (myEvent != nullptr)
				processRequestEvent(myEvent);
		}
		else if (eventType == "ActualEvent")
		{
			ActualEvent *myEvent = dynamic_cast<ActualEvent *>(topEvent);
			if (myEvent != nullptr)
				processActualEvent(myEvent);
		}
		else
		{
			CompletedEvent *myEvent = dynamic_cast<CompletedEvent *>(topEvent);
			if (myEvent != nullptr)
				processCompletedEvent(myEvent);
		}
	}
	else
	{
		cout << "\nSimulation Complete" << endl;
	}
}

//------------------------------------------------------
// processRequestEvent(RequestEvent*)
// PURPOSE:  Processes the RequestEvent by checking if there is a free runway. If there is, it creates an ActualEvent object and adds it to the priority queue. If there is no free runway, it adds the event to the appropriate queue (landing or takeoff)
// PARAMETERS: RequestEvent* myEvent - a pointer to the RequestEvent object
// Returns: None
//
//------------------------------------------------------
void processRequestEvent(RequestEvent *myEvent)
{
	// if the start time of the event is the same as the global time, print the event
	if (globalTime == myEvent->getStartTime())
	{
		myEvent->printEvent();
	}
	// read the next line from the file and create a new event
	Event *newEvent = processInput();
	// convert the request event to an actual event
	ActualEvent *result = convertToActual(myEvent);

	// if there is a free runway, add the event to the priority queue
	if (runways->existFreeRunway())
	{
		mySimulation->push(result);
	}
	else
	{
		// if there is no free runway, add the event to the appropriate queue
		string action = result->getAction();
		if (action == "landing")
		{
			landingQueue->push(result);
		}
		else
		{
			takeOffQueue->push(result);
		}
	}
	// if there is a new event, add it to the priority queue
	if (newEvent != nullptr)
	{
		mySimulation->push(newEvent);
	}
	// call the processSimulation function to continue the simulation
	processSimulation();
}

//------------------------------------------------------
// processActualEvent(ActualEvent*)
// PURPOSE:  Processes the ActualEvent by checking if there is a free runway. If there is, it adds the event to the runway linked list and creates a CompletedEvent object and adds it to the priority queue.
// PARAMETERS: ActualEvent* myEvent - a pointer to the ActualEvent object
// Returns: None
//
//------------------------------------------------------
void processActualEvent(ActualEvent *myEvent)
{
	if (runways->existFreeRunway())
	{
		runways->addEvent(myEvent);
		CompletedEvent *event = convertToCompleted(myEvent);
		mySimulation->push(event);
		// dont want to delete the actual event right now because the runwayNode still holds it, i will delete it when processing the corresponding completed event
	}
	// print the event and call the processSimulation function to start the simulation aGain
	myEvent->printEvent();
	processSimulation();
}

//------------------------------------------------------
// processCompletedEvent(CompletedEvent*)
// PURPOSE: Processes the CompletedEvent by deleting the event from the runway linked list and the priority queue. It then checks if there are any planes waiting to land or takeoff. If there are, it creates an ActualEvent object and adds it to the event priority queue.
// PARAMETERS: CompletedEvent* event - a pointer to the CompletedEvent object
// Returns: None
//
//------------------------------------------------------
void processCompletedEvent(CompletedEvent *event)
{
	// print the event
	event->printEvent();
	// delete the event from the runway linked list
	runways->deleteEvent(event->getRunway());
	// clean up
	delete event;
	// check if there are any planes waiting to land first. if there are, create an actual event and add it to the priority queue
	if (landingQueue->peek() != nullptr)
	{
		EventNode *top = landingQueue->pop();
		ActualEvent *myEvent = dynamic_cast<ActualEvent *>(top->getEvent());
		delete top;

		if (myEvent != nullptr)
		{
			// update the wait time
			waitTime += globalTime - myEvent->getStartTime();
			// set the start and end time of the event
			myEvent->setActualStartEnd(globalTime);
			mySimulation->push(myEvent);
		}
	}
	else
	{
		// if there are no planes waiting to land, check if there are any planes waiting to takeoff. if there are, create an actual event and add it to the priority queue
		if (takeOffQueue->peek() != nullptr)
		{
			EventNode *top = takeOffQueue->pop();
			ActualEvent *myEvent = dynamic_cast<ActualEvent *>(top->getEvent());
			delete top;

			if (myEvent != nullptr)
			{
				// update the wait time
				waitTime += globalTime - myEvent->getStartTime();
				// set the start and end time of the event
				myEvent->setActualStartEnd(globalTime);
				mySimulation->push(myEvent);
			}
		}
	}
	// recursive call to the processSimulation function to continue the simulation
	processSimulation();
}

//------------------------------------------------------
// convertToActual(RequestEvent*)
// PURPOSE: Converts a RequestEvent object to an ActualEvent object
// PARAMETERS: RequestEvent* myEvent - a pointer to the RequestEvent object
// Returns: ActualEvent* - a pointer to the ActualEvent object
//
//------------------------------------------------------
ActualEvent *convertToActual(RequestEvent *myEvent)
{
	ActualEvent *result = nullptr;
	if (myEvent != nullptr)
	{
		Plane *plane = myEvent->getPlane();
		string action = myEvent->getAction();
		int startTime = myEvent->getStartTime();
		result = new ActualEvent(plane, action, startTime);
		delete myEvent;
	}
	return result;
}

//------------------------------------------------------
// convertToCompleted(ActualEvent*)
// PURPOSE:  Converts an ActualEvent object to a CompletedEvent object
// PARAMETERS: ActualEvent* myEvent - a pointer to the ActualEvent object
// Returns: CompletedEvent* - a pointer to the CompletedEvent object
//
//------------------------------------------------------
CompletedEvent *convertToCompleted(ActualEvent *myEvent)
{
	CompletedEvent *result = nullptr;
	if (myEvent != nullptr)
	{
		Plane *myPlane = myEvent->getPlane();
		int runway = myEvent->getRunway();
		int time = myEvent->getEndTime();
		result = new CompletedEvent(myPlane, runway, time);
	}
	return result;
}