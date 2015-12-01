//======================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: CS 433
//File: Output header file
//======================================================


#ifndef OUTPUT_H
#define OUTPUT_H


#include <iostream>//used for output
#include "Process.h"//process class
#include <queue>//used for queues

//Purpose: Outputs process informations
//Parameters: The process to be outputted (Process finishedProcess), the current time (double currentTime)
//Returns: The process that has been outputted (Process)
void finalOutput(std::vector<Process> &ProcessArray, double CPUIdleTime, double currentTime);
//Purpose: Outputs the final information of the scheduling algorithm
//Parameters: The vector of finished processes, The idle time of the CPU (double CPUIdleTime), The current time (double currentTime)
Process output(Process finishedProcess, double currentTime);



#endif
