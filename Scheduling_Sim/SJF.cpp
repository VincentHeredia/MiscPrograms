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


//Purpose: Runs the shortest job first algorithm
//Parameters: The number of processes (int numOfP)
void startSJF(int numOfP){
  std::cout << std::endl << "Starting SJF Simulation...\n" << std::endl;
  //queues for simulation
  std::priority_queue< Event, std::vector<Event>, Event::CompTime> eventQueue;//event queue for holding various events
  std::priority_queue< Process, std::vector<Process>, Process::CompDur > readyQueue;//ready queue for holding processes
  std::priority_queue< Process, std::vector<Process>, Process::CompIO > IOArray;//used for holding process that are waiting for an IO device


  std::priority_queue< Event, std::vector<Event>, Event::CompTime> tempEventQueue;
  std::priority_queue< Process, std::vector<Process>, Process::CompDur > tempProcessQueue;

  std::vector<Process> ProcessArray;//used for final output

  //Time variables
  double totalTime = 300.0;//total time executed
  double currentTime = 0.0;//Initialize current time
  double randomDouble = 0.0;//used for various things

  int currentEvent;//holds the current event type
  Process newP;//used for new processes
  Process CPUProcess;//process in the CPU
  int IDcount = 0;//for the process IDs
  bool CPUBusy = false;//flag for checking if the CPU has a process in it
  double CPUIdleTime = 0.0;//time that the CPU was not working
  double CPUIdleTimeTemp = 0.0;//assists finding CPU idle time
  

  srand(time(0));//set random seed
  Event newE;//temporary event holder
  long n = -2;//for random numbers


  for (int i = 0; i < numOfP; i++){
    newE.setEventType(1);//new event = process arrival
    randomDouble = ( rand() % 300000 );
    randomDouble = randomDouble/1000;
    newE.setTimeOfEvent(rand() % 299 + ran1(&n));
    eventQueue.push(newE);
    //std::cout << newE.getTimeOfEvent() << std::endl;
  }

  
  int tempI; //not needed
  while ((!eventQueue.empty())){

    currentEvent = eventQueue.top().getEventType();
    currentTime = eventQueue.top().getTimeOfEvent();
    eventQueue.pop();//erase front event
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
      readyQueue.push(newP);//push it to the back


      //checks the CPU to see if it is busy
      if (CPUBusy){

      }
      else{//if it isnt, add the new process into the CPU
	CPUBusy = true;
	CPUIdleTime = (currentTime - CPUIdleTimeTemp) + CPUIdleTime;
	CPUProcess = readyQueue.top();
	CPUProcess.setStatus("Running");
	//std::cout << "CPUProcess: " << CPUProcess.getProcessID() <<  " Inserted" <<std::endl;
	
	readyQueue.pop();//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	//add the event completion time to the event queue
	//std::cout << "Event Processes at: " << newE.getTimeOfEvent() << std::endl;
	eventQueue.push(newE);
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
	IOArray.push(CPUProcess);
	// Generate event for when the IO time is done
	newE.setEventType(3);
	newE.setTimeOfEvent(currentTime+CPUProcess.getIOBurst());
	// Insert event into IO queue
	eventQueue.push(newE);
      }




      //Put new Process into CPU if there is no process in there
      if(!readyQueue.empty()){
	//add new process to CPU
	CPUProcess = readyQueue.top();
	CPUProcess.setStatus("Running");
	CPUProcess.setWaitingTime(CPUProcess.getWaitingTime() + (currentTime - CPUProcess.getLastRun()) );
	
	readyQueue.pop();//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	eventQueue.push(newE);
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
      newP = IOArray.top();//IOArray.front();//changed
      IOArray.pop();//IOArray.erase(IOArray.begin());//changed

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
      readyQueue.push(newP);

      //check if CPU has a process
      if (CPUBusy){
	//std::cout << "CPU is Busy" << std::endl;
      }
      else{//if it isnt, add the new process into the CPU
	CPUBusy = true;
	CPUIdleTime = (currentTime - CPUIdleTimeTemp) + CPUIdleTime;
	CPUProcess = readyQueue.top();
	CPUProcess.setStatus("Running");
	CPUProcess.setWaitingTime(CPUProcess.getWaitingTime() + (currentTime - CPUProcess.getLastRun()));
	readyQueue.pop();//erase front event
	newE.setEventType(2);
	newE.setTimeOfEvent(currentTime+CPUProcess.getNextBurst());
	eventQueue.push(newE);
      }

      break;

    case 4:// Timer Expiration - Shouldnt be reached
      
      break;

    default: 
      
      break;
    }
    
  }
  finalOutput(ProcessArray, CPUIdleTime, currentTime);
}
