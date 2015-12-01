//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Output implementation file
//======================================================



#include "Output.h"//header file
#include <iomanip>//used for cleaning output up




//Purpose: Outputs process informations
//Parameters: The process to be outputted (Process finishedProcess), the current time (double currentTime)
//Returns: The process that has been outputted (Process)
Process output(Process finishedProcess, double currentTime){
  
  double turnAround = currentTime - finishedProcess.getArrivalTime();
  finishedProcess.setTurnAround(turnAround);

  std::cout << std::fixed <<  std::setprecision(3)
	    << "Process: " << finishedProcess.getProcessID() << std::endl
	    << "Arrival Time: " << finishedProcess.getArrivalTime() << "s" << std::endl
	    << "Finish Time: " << currentTime << "s" << std::endl
	    << "Service Time: " << finishedProcess.getTotalDuration() << "s" << std::endl
	    << "I/O Time: " << finishedProcess.getIOBurstTotal() << std::endl
	    << "Turnaround time: " << turnAround << "s" << std::endl
	    << "Waiting time: " << finishedProcess.getWaitingTime() << "s" << std::endl << std::endl;
  return finishedProcess;
}

//Purpose: Outputs the final information of the scheduling algorithm
//Parameters: The vector of finished processes, The idle time of the CPU (double CPUIdleTime), The current time (double currentTime)
void finalOutput(std::vector<Process> &ProcessArray, double CPUIdleTime, double currentTime){
  double avTurnAround = 0.0;
  double avWaiting = 0.0;
  int size = ProcessArray.size();

  while(!ProcessArray.empty()){
    avWaiting = avWaiting + ProcessArray.back().getWaitingTime();
    avTurnAround = avTurnAround + ProcessArray.back().getTurnAround();
    ProcessArray.pop_back();
  }
  avWaiting = avWaiting/size;
  avTurnAround = avTurnAround/size;
  std::cout << std::fixed <<  std::setprecision(3)
	    << "All processes finished..." << std::endl
	    << "CPU Utilization: " << 100-((CPUIdleTime/currentTime)*100) << "%" << std::endl
	    << "Throughput: " << size/currentTime << " jobs / s" << std::endl
	    << "Average turnaround: " << avTurnAround << std::endl
	    << "Average Waiting Time: " << avWaiting << std::endl;
}
