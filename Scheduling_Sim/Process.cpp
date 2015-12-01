//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Process class implementation
//======================================================



#include "Process.h"
#include <iostream>//needed for output

Process::Process(){//Constructor

}




//--------------gets and sets---------------
//Purpose: Get for ProcessID variable
//Returns: The process's ID
int Process::getProcessID(){
  return processID;
}
//Purpose: Set for ProcessID variable
//Parameters: the new ID (int newID)
void Process::setProcessID(int newID){
  processID = newID;
  return;
}

//Purpose: Get for the startTime variable
//Returns: The start time
double Process::getStartTime(){
  return startTime;
}
//Purpose: Set for the startTime variable
//Parameters: The new startTime (double)
void Process::setStartTime(double newTime){
  startTime = newTime;
  return;
}

//Purpose: Get for the totalDuration variable
//Returns: The total duration
double Process::getTotalDuration(){
  return totalDuration;
}
//Purpose: Set for the totalDuration variable
//Parameters: The new total duration (double)
void Process::setTotalDuration(double newTime){
  totalDuration = newTime;
  return;
}

//Purpose: Get for the remainingDuration variable
//Returns: The remaining duration
double Process::getRemainingDuration(){
  return remainingDuration;
}
//Purpose: Set for the remainingDuration variable
//Parameters: The new remaining duration (double)
void Process::setRemainingDuration(double newTime){
  remainingDuration = newTime;
  return;
}

//Purpose: Get for the averageBurst variable
//Returns: The average burst
double Process::getAverageBurst(){
  return averageBurst;
}
//Purpose: Set for the averageBurst variable
//Parameters: The new average burst (double)
void Process::setAverageBurst(double newTime){
  averageBurst = newTime;
  return;
}

//Purpose: Sets the new average burst using Ϯn+1 = αᵼn + (1 - α)Ϯn
//Parameters: the last burst (double), the weight or alpha (double)
void Process::setNewAverageBurst(double lastRun, double weight){
  //std::cout << "Weight: " << weight << " lastRun: " << lastRun << std::endl;
  averageBurst = ((weight*lastRun) + ((1 - weight)*averageBurst));
  return;
}

//Purpose: Get for the nextBurst variable
//Returns: The next burst
double Process::getNextBurst(){
  return nextBurst;
}
//Purpose: Set for the nextBurst variable
//Parameters: The new next burst (double)
void Process::setNextBurst(double newTime){
  nextBurst = newTime;
  return;
}

//Purpose: Get for the IOBurst variable
//Returns: The IO burst
double Process::getIOBurst(){
  return IOBurst;
}
//Purpose: Set for the IOBurst variable
//Parameters: The new IO burst (double)
void Process::setIOBurst(double newTime){
  IOBurst = newTime;
  return;
}

//Purpose: Get for the IOBurstTotal variable
//Returns: The IO burst total
double Process::getIOBurstTotal(){
  return IOBurstTotal;
}
//Purpose: Set for the IOBurstTotal variable
//Parameters: The new IO burst total (double)
void Process::setIOBurstTotal(double newTime){
  IOBurstTotal = newTime;
  return;
}


//Purpose: Get for the priority variable
//Returns: The priority
int Process::getPriority(){
  return priority;
}
//Purpose: Set for the priority variable
//Parameters: The new priority (double)
void Process::setPriority(int newPriority){
  priority = newPriority;
  return;
}

//Purpose: Get for the status variable
//Returns: The status
std::string Process::getStatus(){
  return status;
}
//Purpose: Set for the status variable
//Parameters: The new status (double)
void Process::setStatus(std::string newStatus){
  status = newStatus;
  return;
}

//Purpose: Get for the arrivalTime variable
//Returns: The arrival time
double Process::getArrivalTime(){
  return arrivalTime;
}
//Purpose: Set for the arrivalTime variable
//Parameters: The new arrival time (double)
void Process::setArrivalTime(double newTime){
  arrivalTime = newTime;
}

//Purpose: Get for the turnAround variable
//Returns: The turn around
double Process::getTurnAround(){
  return turnAround;
}
//Purpose: Set for the turnAround variable
//Parameters: The new turn around (double)
void Process::setTurnAround(double newTime){
  turnAround = newTime;
}

//Purpose: Get for the waitingTime variable
//Returns: The waiting time
double Process::getWaitingTime(){
  return waitingTime;
}
//Purpose: Set for the waitingTime variable
//Parameters: The new waiting time (double)
void Process::setWaitingTime(double newTime){
  waitingTime = newTime;
}

//Purpose: Get for the lastRun variable
//Returns: The last run
double Process::getLastRun(){
  return lastRun;
}
//Purpose: Set for the lastRun variable
//Parameters: The new last run (double)
void Process::setLastRun(double newTime){
  lastRun = newTime;
  return;
}

bool Process::CompIO::operator()(const Process& p1, const Process& p2) const{
  return p1.IOBurst > p2.IOBurst;
}
bool Process::CompDur::operator()(const Process& p1, const Process& p2) const{
  return p1.totalDuration > p2.totalDuration;
}


//-------------- end of gets and sets---------------
