//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Event class header file
//======================================================


#include <string>//needed for string operations
#include "Process.h"//needed for processor variable


#ifndef EVENT_H
#define EVENT_H


//Purpose: This class is used to determine what 
//events are happening during the scheduling algorithms
class Event{
 public:
  Event();//default constructor

  //constructor
  //Parameters: Time that the event occurs (double newTime)
  //            The event type (std::string newType)
  Event(double newTime, int newType);//constructor


  //Purpose: Returns timeOfEvent variable
  //Returns: The time of the event (double)
  double getTimeOfEvent() const;
  //Purpose: Sets the timeOfEvent variable
  //Parameter: The new time of the event (double newTime)
  void setTimeOfEvent(double newTime);

  
  //Purpose: Returns eventType variable
  //Returns: The type of event (int)
  int getEventType() const;
  //Purpose: Sets the eventType variable
  //Parameter: The new type of event (int newType)
  void setEventType(int newType);

  
  //----NOT USED----
  //Purpose: Returns the event's process variable
  //Returns: The process (Process)
  Process getProcess();
  //Purpose: Sets the event's process 
  //Parameter: The new process (Process newP)
  void setProcess(Process newP);
  //----------------

  //This struct holds the comparison function for the event priority queue
  struct CompTime{
    //Purpose: Function is for comparing two different events in the priority queue
    //Parameters: Takes two events to compare (Event e1, Event e2)
    //Returns: the result of the comparison (bool)
    bool operator()(const Event& e1, const Event& e2) const;
  };


 private:
  double timeOfEvent;//time the event is set to occur
  int eventType;//the type of event it is
  //0 = Unknown
  //1 = Process Arrival
  //2 = CPU Burst Completion
  //3 = I/O Completion
  //4 = Timer Expiration
  //Coded as int type for quicker processing
  Process eventsProcess;//the event's process, NOT USED
};

#endif
