//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Process class header
//======================================================

#ifndef PROCESS_H
#define PROCESS_H


#include <string>//needed for string operations




//This class holds various information on a process in the system
class Process{
 public:
  Process();//Constructor
  
  //Purpose: Get for ProcessID variable
  //Returns: The process's ID
  int getProcessID();
  //Purpose: Set for ProcessID variable
  //Parameters: the new ID (int)
  void setProcessID(int newID);

  //Purpose: Get for the startTime variable
  //Returns: The start time
  double getStartTime();
  //Purpose: Set for the startTime variable
  //Parameters: The new startTime (double)
  void setStartTime(double newTime);

  //Purpose: Get for the totalDuration variable
  //Returns: The total duration
  double getTotalDuration();
  //Purpose: Set for the totalDuration variable
  //Parameters: The new total duration (double)
  void setTotalDuration(double newTime);

  //Purpose: Get for the remainingDuration variable
  //Returns: The remaining duration
  double getRemainingDuration();
  //Purpose: Set for the remainingDuration variable
  //Parameters: The new remaining duration (double)
  void setRemainingDuration(double newTime);

  //Purpose: Get for the averageBurst variable
  //Returns: The average burst
  double getAverageBurst();
  //Purpose: Set for the averageBurst variable
  //Parameters: The new average burst (double)
  void setAverageBurst(double newTime);

  //Purpose: Sets the new average burst using Ϯn+1 = αᵼn + (1 - α)Ϯn
  //Parameters: the last burst (double), the weight or alpha (double)
  void setNewAverageBurst(double lastRun, double weight);

  //Purpose: Get for the nextBurst variable
  //Returns: The next burst
  double getNextBurst();
  //Purpose: Set for the nextBurst variable
  //Parameters: The new next burst (double)
  void setNextBurst(double newTime);

  //Purpose: Get for the IOBurst variable
  //Returns: The IO burst
  double getIOBurst();
  //Purpose: Set for the IOBurst variable
  //Parameters: The new IO burst (double)
  void setIOBurst(double newTime);

  //Purpose: Get for the IOBurstTotal variable
  //Returns: The IO burst total
  double getIOBurstTotal();
  //Purpose: Set for the IOBurstTotal variable
  //Parameters: The new IO burst total (double)
  void setIOBurstTotal(double newTime);

  //Purpose: Get for the priority variable
  //Returns: The priority
  int getPriority();
  //Purpose: Set for the priority variable
  //Parameters: The new priority (double)
  void setPriority(int newPriority);

  //Purpose: Get for the status variable
  //Returns: The status
  std::string getStatus();
  //Purpose: Set for the status variable
  //Parameters: The new status (double)
  void setStatus(std::string newStatus);

  //Purpose: Get for the arrivalTime variable
  //Returns: The arrival time
  double getArrivalTime();
  //Purpose: Set for the arrivalTime variable
  //Parameters: The new arrival time (double)
  void setArrivalTime(double newTime);

  //Purpose: Get for the turnAround variable
  //Returns: The turn around
  double getTurnAround();
  //Purpose: Set for the turnAround variable
  //Parameters: The new turn around (double)
  void setTurnAround(double newTime);

  //Purpose: Get for the waitingTime variable
  //Returns: The waiting time
  double getWaitingTime();
  //Purpose: Set for the waitingTime variable
  //Parameters: The new waiting time (double)
  void setWaitingTime(double newTime);

  //Purpose: Get for the lastRun variable
  //Returns: The last run
  double getLastRun();
  //Purpose: Set for the lastRun variable
  //Parameters: The new last run (double)
  void setLastRun(double newTime);

  struct CompIO{
    //Purpose: Provides a comparison for the priority queue
    //Parameters: The two processes to be compaired
    //Returns: the result of the comparison
    bool operator()(const Process& p1, const Process& p2) const;
  };
  struct CompDur{
    //Purpose: Provides a comparison for the priority queue
    //Parameters: The two processes to be compaired
    //Returns: the result of the comparison
    bool operator()(const Process& p1, const Process& p2) const;
  };


 private:
  int processID;//The process's name
  
  double startTime;//The time when the process enters the CPU
  double totalDuration;//The total duration that the process needs to run in the CPU
  double remainingDuration;//The duration that the process still needs to be in the CPU
  
  double averageBurst;//Average CPU burst of the process
  double nextBurst;//The next CPU burst
  double IOBurst;//The current IO burst
  double IOBurstTotal;//The total IO time

  double arrivalTime;//The time the process enters the system
  double turnAround;//The turn around of the process, used for final output
  double waitingTime;//The time the process had to wait, used for final output
  double lastRun;//the last time the process was in the CPU

  int priority;//Priority of the process

  std::string status;//The status of the process, Running, Ready, Waiting, Terminated
};


#endif
