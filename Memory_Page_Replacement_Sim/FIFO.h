//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: FIFO header file
//=======================================================================




#ifndef FIFO_H
#define FIFO_H


#include <iostream>
#include <string>
#include "Frame.h"

using namespace std;


class FIFO{
 public:

  FIFO();//default constructor

  //Purpose: Runs the simulation of the algorithm
  //Parameters: The size of the pages in memory
  //  The physical memory size
  //  The limit on how many instructions are ran
  //Returns: True when the simulation finishes
  bool runFIFO(int pageSize, int physicalMemorySize, int limit);

  //Purpose: Searches the page table for the specified frame
  //Parameters: The frame to search for
  //Returns: The index if the frame is found, else -1
  int searchPageTable(int frame);

  //Purpose: Searches for invalid bits
  //Parameters: None
  //Returns: The index of the invalid bit if found, else -1
  int searchForInvalidBit();

  //Purpose: Chooses a victim to replace
  //Parameters: None
  //Returns: The chosen victim
  int chooseVictim();

  //Purpose: Outputs the page table (this function varies with seperate algorithms)
  //Parameters: None
  //Returns: Nothing
  void outputPageTable();

 private:

  int totalMemoryReferences;
  int totalPageFaults;
  int totalFlushes;
  double totalTime;//total time of the program in milliseconds
  int totalHits;

  //dynamic array used to emulate page memory
  Frame* pageTable;
  int front;//front of the page table(next to be replaced)

  long physicalMemorySize;
  long pageSize;
  long amountOfFrames;

};


#endif 
