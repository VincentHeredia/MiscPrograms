//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Event class implementation
//======================================================



#include "Event.h"//header file for class




Event::Event(){//default constructor
  timeOfEvent = 0;
  eventType = 0;
}

//constructor
//Parameters: Time that the event occurs (double newTime)
//            The event type (std::string newType)
Event::Event(double newTime, int newType){//constructor
  timeOfEvent = newTime;
  eventType = newType;
}

//Purpose: Returns timeOfEvent variable
//Returns: The time of the event (double)
double Event::getTimeOfEvent() const{
  return timeOfEvent;
}
//Purpose: Sets the timeOfEvent variable
//Parameter: The new time of the event (double newTime)
void Event::setTimeOfEvent(double newTime){
  timeOfEvent = newTime;
  return;
}

//Purpose: Returns eventType variable
//Returns: The type of event (int)
int Event::getEventType() const{
  return eventType;
}
//Purpose: Sets the eventType variable
//Parameter: The new type of event (int newType)
void Event::setEventType(int newType){
  eventType = newType;
  return;
}

//----NOT USED----
//Purpose: Returns the event's process variable
//Returns: The process (Process)
Process Event::getProcess(){
  return eventsProcess;
}
//Purpose: Sets the event's process
//Parameter: The new process (Process newP)
void Event::setProcess(Process newP){
  eventsProcess = newP;
}
//----------------


//Purpose: Function is for comparing two different events in the priority queue
//Parameters: Takes two events to compare (Event e1, Event e2)
//Returns: the result of the comparison (bool)
bool Event::CompTime::operator()(const Event& e1, const Event& e2) const{
  return  e1.timeOfEvent > e2.timeOfEvent;
}
