//******************************
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS433
//File: This contains the startSJF function
//******************************


#include <queue>//used for queues
#include <iostream>//used for output
#include <string>//used for string operations
#include <cstdlib>//used for random function
#include <ctime>//used for seeding the random function
#include "Event.h"//event class
#include "Process.h"//process class
#include "random.h"//given functions
#include "FCFS.h"//algorithm header
#include "Output.h"//for outputing info of process and scheduling algorithms


//Purpose: Inserts an event into the event vector
//Parameters: The new event (Event newE), The vector to be inserted into
void insertIntoVector(Event newE, std::vector<Event> &eventQueue);

//Purpose: Inserts a process into the process vector
//Parameters: The new process (Process newP), the vector to be inserted into
void insertIntoVector(Process newP, std::vector<Process> &IOArray);



//Purpose: Runs the FCFS scheduling algorithm
//Parameters: The number of processes
void startFCFS(int numOfP){
  std::cout << std::endl << "Starting FCFS Simulation...\n" << std::endl;
  //queues for simulation
  std::vector<Event> eventQueue;//event queue for holding various events
  std::vector<Process> readyQueue;//ready queue for holding processes
  std::vector<Process> ProcessArray;//used for final output
  std::vector<Process> IOArray;//used for holding process that are waiting for an IO device
  //Time variables
  double totalTime = 300.0;//total time executed
  double currentTime = 0.0;//Initialize current time
  double randomDouble = 0.0;//used for generating random numbers

  int currentEvent;//holds the current event type
  Process newP;//used for new processes
  Process CPUProcess;//process in the CPU
  int IDcount = 0;//for the process IDs
  bool CPUBusy = false;//flag for checking if the CPU has a process in it
  double CPUIdleTime = 0.0;//time that the CPU was not working
  double CPUIdleTimeTemp = 0.0;//assists finding CPU idle time
  

  srand(time(0));//set random seed
  Event newE;
  long n = -2;
  for (int i = 0; i < numOfP; i++){
    newE.setEventType(1);//new event = process arrival
    randomDouble = ( rand() % 300000 );
    randomDouble = randomDouble/1000;
    newE.setTimeOfEvent(rand() % 299 + ran1(&n));
    insertIntoVector(newE, eventQueue);
    //std::cout << newE.getTimeOfEvent() << std::endl;
  }

  
  
  while ((!eventQueue.empty())){

    currentEvent = eventQueue.front().getEventType();
    currentTime = eventQueue.front().getTimeOfEvent();
    eventQueue.erase(eventQueue.begin());//erase front event
    switch(currentEvent){
    case 1://Process Arrival
      
      //adds to the ready queue
      randomDouble = ( rand() % 60000 );
      randomDouble = randomDouble/1000;
      newP.setTotalDuration(randomDouble);

      //average burst
      randomDouble = ( rand() % 95 ) + 5;
      newP.setAverageBurst(randomDouble);//Ϯn+1 = αᵼn + (1 - α)Ϯn


      newP.setStatus("Ready");
      newP.setProcessID(IDcount);
      newP.setArrivalTime(currentTime);
      newP.setRemainingDuration(0.0);
      newP.setIOBurst(0.0);
      newP.setIOBurstTotal(0.0);
      newP.setWaitingTime(0.0);
      newP.setLastRun(0.0);
      IDcount++;//increment ID, next ID will be the ID of current process + 1
      
      //set next burst
      randomDouble = CPUBurstRandom(newP.getAverageBurst());
      randomDouble = randomDouble/1000;
      if(randomDouble <= 0.0){randomDouble += 0.001;}//CPUBurstRandom() can generate 0.0 sometimes
      newP.setNextBurst(randomDouble);
      readyQueue.push_back(newP);//push it to the back


      //checks the CPU to see if it is busy
      if (CPUBusy){
	//std::cout << "CPU is Busy" << std::endl;
      }
      else{//if it isnt, add the new process into the CPU
	CPUBusy = true;
	CPUIdleTime = (currentTime - CPUIdleTimeTemp) + CPUIdleTime;
	CPUProcess = readyQueue.front();
	CPUProcess.setStatus("Running");
	//std::cout << "CPUProcess: " << CPUProcess.getProcessID() <<  " Inserted" <<std::endl;
	
	readyQueue.erase(readyQueue.begin());//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	//add the event completion time to the event queue
	//std::cout << "Event Processes at: " << newE.getTimeOfEvent() << std::endl;
	insertIntoVector(newE, eventQueue);
      }


      break;
      
    case 2://CPU Burst Completion
      

      //std::cout << "CPUProcess: " << CPUProcess.getProcessID() << " is done" << std::endl;
      
      CPUProcess.setRemainingDuration(CPUProcess.getRemainingDuration() + CPUProcess.getNextBurst());
      //std::cout << CPUProcess.getProcessID() << " " << CPUProcess.getTotalDuration() << " " << CPUProcess.getRemainingDuration() << std::endl;
      //check if CPU pocess is done
      if (CPUProcess.getRemainingDuration() >= CPUProcess.getTotalDuration()){
	CPUProcess.setStatus("Terminated");
	// Output its information and insert into 'finished array' 
	ProcessArray.push_back(output(CPUProcess, currentTime));
      }
      else{// Generate IO burst and insert into IO queue
	CPUProcess.setStatus("Waiting");
	CPUProcess.setLastRun(currentTime);
	randomDouble = ( rand() % 70 ) + 30;
	randomDouble = randomDouble/1000;
	CPUProcess.setIOBurst(randomDouble);
	insertIntoVector(CPUProcess, IOArray);
	// Generate event for when the IO time is done
	newE.setEventType(3);
	newE.setTimeOfEvent(currentTime+CPUProcess.getIOBurst());
	// Insert event into IO queue
	insertIntoVector(newE, eventQueue);
      }




      //Put new Process into CPU if there is no process in there
      if(!readyQueue.empty()){
	//add new process to CPU
	CPUProcess = readyQueue.front();
	CPUProcess.setStatus("Running");
	CPUProcess.setWaitingTime(CPUProcess.getWaitingTime() + (currentTime - CPUProcess.getLastRun()) );
	
	readyQueue.erase(readyQueue.begin());//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	insertIntoVector(newE, eventQueue);
	//std::cout << "CPUProcess: " << CPUProcess.getProcessID() <<  " Inserted" <<std::endl;
      }
      //if no process in ready queue, set CPU flag to not busy
      else{ //set CPU to idle
	CPUBusy = false; 
	CPUIdleTimeTemp = currentTime;
	//std::cout << "CPU Idle" <<std::endl;
      }

      break;

    case 3:// I/O Completion
      
      //take the process out of the IO queue
      newP = IOArray.front();
      IOArray.erase(IOArray.begin());

      //std::cout << newP.getAverageBurst() << " " << newP.getNextBurst() << std::endl;
      newP.setNewAverageBurst(newP.getNextBurst()*1000.0, 0.2);//Ϯn+1 = αᵼn + (1 - α)Ϯn
      //std::cout << newP.getAverageBurst() << std::endl;

      //reinsert the process into the readyQueue
      newP.setLastRun(currentTime);
      randomDouble = CPUBurstRandom(newP.getAverageBurst());
      randomDouble = randomDouble/1000;

      //CPUBurstRandom tends to generate numbers lower than the average for some reason
      //This is placed to make sure the bursts don't reach 0.0.
      if (randomDouble < 0.010) { randomDouble = 0.010; }
      newP.setNextBurst(randomDouble);


      newP.setStatus("Waiting");
      newP.setIOBurstTotal(newP.getIOBurst() + newP.getIOBurstTotal());
      readyQueue.push_back(newP);

      //check if CPU has a process
      if (CPUBusy){
	//std::cout << "CPU is Busy" << std::endl;
      }
      else{//if it isnt, add the new process into the CPU
	CPUBusy = true;
	CPUIdleTime = (currentTime - CPUIdleTimeTemp) + CPUIdleTime;
	CPUProcess = readyQueue.front();
	CPUProcess.setStatus("Running");
	CPUProcess.setWaitingTime(CPUProcess.getWaitingTime() + (currentTime - CPUProcess.getLastRun()));
	readyQueue.erase(readyQueue.begin());//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	insertIntoVector(newE, eventQueue);
      }

      break;

    case 4:// Timer Expiration - Shouldnt be reached
      
      break;

    default: 
      
      break;
    }//end of switch
    

  }//end of while
  finalOutput(ProcessArray, CPUIdleTime, currentTime);
}




void insertIntoVector(Event newE, std::vector<Event> &eventQueue){
  int i = 0;
  bool notDone = true;

  while(notDone){
    if(eventQueue.size() <= i){
      eventQueue.push_back(newE);
      notDone = false;
    }
    else if(eventQueue[i].getTimeOfEvent() < newE.getTimeOfEvent()){
      i++;
      continue;
    }
    else{ 
      eventQueue.insert(eventQueue.begin()+i, newE); 
      notDone = false;
    }
  }//end of while
}


void insertIntoVector(Process newP, std::vector<Process> &IOArray){
  int i = 0;
  bool notDone = true;

  while(notDone){
    if(IOArray.size() <= i){
      IOArray.push_back(newP);
      notDone = false;
    }
    else if(IOArray[i].getIOBurst() < newP.getIOBurst()){
      i++;
      continue;
    }
    else{ 
      IOArray.insert(IOArray.begin()+i, newP); 
      notDone = false;
    }
  }//end of while
}
