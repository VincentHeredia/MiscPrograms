//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: LRU header file
//=======================================================================




#ifndef LRU_H
#define LRU_H



#include <iostream>
#include <string>
#include "Frame.h"

using namespace std;


class LRU{
 public:

  LRU();//default constructor

  //Purpose: Runs the simulation of the algorithm
  //Parameters: The size of the pages in memory
  //  The physical memory size
  //  The limit on how many instructions are ran
  //Returns: True when the simulation finishes
  bool runLRU(int pageSize, int physicalMemorySize, int limit);

  //Purpose: Searches the page table for the specified frame
  //Parameters: The frame to search for
  //Returns: The index if the frame is found, else -1
  int searchPageTable(int frame);

  //Purpose: Searches for invalid bits
  //Parameters: None
  //Returns: The index of the invalid bit if found, else -1
  int searchForInvalidBit();

  //Purpose: Chooses a victim to replace (this function varies with seperate algorithms)
  //Parameters: None
  //Returns: The chosen victim
  int chooseVictim();

  //Purpose: Outputs the page table
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

  long physicalMemorySize;
  long pageSize;
  long amountOfFrames;

};







#endif
