//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: LRU implementation file
//=======================================================================



#include "LRU.h"
#include <math.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//default constructor
LRU::LRU(){
  //Initialize all variables to 0
  totalMemoryReferences = 0;
  totalPageFaults = 0;
  totalFlushes = 0;
  totalTime = 0;
  totalHits = 0;

  physicalMemorySize = 0;
  pageSize = 0;
  amountOfFrames = 0;
}


//Purpose: Runs the simulation of the algorithm
//Parameters: The size of the pages in memory
//  The physical memory size
//  The limit on how many instructions are ran
//Returns: True when the simulation finishes
bool LRU::runLRU(int userPageSize, int userPhysicalMemorySize, int limit){

  int address = 0;//holds the read in address
  string temp = "";//temp string for holding values
  int searchResult = 0;//various uses
  int frame = 0;//used to get the frame of a memory reference
  long time = 0;

  pageSize  = pow(2.0, (double)userPageSize);
  physicalMemorySize = pow(2.0, (double)userPhysicalMemorySize);

  amountOfFrames = physicalMemorySize/pageSize;

  //page memory with a size determined by the user
  pageTable = new Frame[amountOfFrames];

  fstream fin;
  fin.open("references.txt");
  if(fin.is_open() == false){
    cout << "File failed to open" << endl;
    exit(0);
  }

  clock_t begin = clock();


  //main loop
  while( (fin.eof() == false) && (limit > totalMemoryReferences) ){
    getline(fin, temp, '\n');
    address = atoi(temp.c_str());

    //cout << "Address: " << address << endl;

    //even number, read instruction
    if((address%2) == 0){

      frame = address >> userPageSize;
      //cout << "Frame: " << frame << endl;
      searchResult = searchPageTable(frame);

      //if page is not found in the page table
      if(searchResult == -1){
	//cout<< "Miss!" << endl;
	totalPageFaults++;
	//check for a valid bit
	searchResult = searchForInvalidBit();
	
	//invalid bit not found
	if(searchResult == -1){
	  //choose a page to replace
	  searchResult = chooseVictim();
	  
	  if(pageTable[searchResult].getDirtyBit() == 'D'){
	    //cout<< "Flush needed" << endl;
	    totalFlushes++;
	  }
	  //cout << "Replacing: " << searchResult << endl;
	  pageTable[searchResult].setValid('V');
	  pageTable[searchResult].setFrame(frame);
	  pageTable[searchResult].setDirtyBit('C');
	  pageTable[searchResult].setLastAccess(time);
	}
	//invalid bit found
	else{
	  //cout<< "Invalid Bit found: " << searchResult << endl;
	  pageTable[searchResult].setFrame(frame);
	  pageTable[searchResult].setValid('V');
	  pageTable[searchResult].setDirtyBit('C');
	  pageTable[searchResult].setLastAccess(time);
	}

      }//end of if(searchResult == -1)


      //if it was found in memory
      else{
	//cout<< "Hit!" << endl;
	pageTable[searchResult].setLastAccess(time);
	totalHits++;
      }
    }//end ofif((address%2) == 0)

    //odd number, write instruction
    else{
      address -= 1;
      
      frame = address >> userPageSize;
      //cout << "Frame: " << frame << endl;

      searchResult = searchPageTable(frame);

      //if page is not found in the page table
      if(searchResult == -1){
	//cout<< "Miss!" << endl;
	totalPageFaults++;
	//check for a valid bit
	searchResult = searchForInvalidBit();
	
	//invalid bit not found
	if(searchResult == -1){
	  //choose a page to replace
	  searchResult = chooseVictim();
	  if(pageTable[searchResult].getDirtyBit() == 'D'){
	    totalFlushes++;
	    //cout<< "Flush needed" << endl;
	  }
	  //cout << "Replacing: " << searchResult << endl;
	  pageTable[searchResult].setValid('V');
	  pageTable[searchResult].setFrame(frame);
	  pageTable[searchResult].setDirtyBit('D');
	  pageTable[searchResult].setLastAccess(time);
	}
	//invalid bit found
	else{
	  //cout<< "Invalid Bit found: " << searchResult << endl;
	  pageTable[searchResult].setFrame(frame);
	  pageTable[searchResult].setValid('V');
	  pageTable[searchResult].setDirtyBit('D');
	  pageTable[searchResult].setLastAccess(time);
	}

      }//end of if(searchResult == -1)


      //if it was found in memory
      else{
	//cout<< "Hit!" << endl;
	totalHits++;
	pageTable[searchResult].setDirtyBit('D');
	pageTable[searchResult].setLastAccess(time);
      }
    }//end of else

    time++;
    totalMemoryReferences++;
    //outputPageTable();
  }

  clock_t end = clock();





  totalTime = (end - begin);//*pow(10.0,-3.0);

  cout << "\n\nTotal Memory References: " << totalMemoryReferences
       << "\nTotal Page Faults: " << totalPageFaults
       << "\nTotal Hits: " << totalHits
       << "\nTotal Flushes: " << totalFlushes
       << "\nTotal Time: " << totalTime << "ms"
       << endl;



  fin.close();
  delete [] pageTable;
  
  return true;
}


//Purpose: Searches the page table for the specified frame
//Parameters: The frame to search for
//Returns: The index if the frame is found, else -1
int LRU::searchPageTable(int frame){
  
  //search for page
  for(int i = 0; i < amountOfFrames; i++){
    if(pageTable[i].getFrame() == frame){
      //was found
      return i;
    }
  }
  //was not found
  return -1;
}

//Purpose: Searches for invalid bits
//Parameters: None
//Returns: The index of the invalid bit if found, else -1
int LRU::searchForInvalidBit(){

  //search for page
  for(int i = 0; i < amountOfFrames; i++){
    if(pageTable[i].getValid() == 'I'){
      //was found
      return i;
    }
  }
  return -1;
}

//Purpose: Chooses a victim to replace (this function varies with seperate algorithms)
//Parameters: None
//Returns: The chosen victim
int LRU::chooseVictim(){
  int returnIndex = 0;
  int lowestValue = pageTable[0].getLastAccess();

  for(int i = 0; amountOfFrames > i; i++){
    if((pageTable[i].getLastAccess() < lowestValue) && (pageTable[i].getValid() == 'V')){
      lowestValue = pageTable[i].getLastAccess();
      returnIndex = i;
    }
  }
  
  return returnIndex;
}


//Purpose: Outputs the page table
//Parameters: None
//Returns: Nothing
void LRU::outputPageTable(){
  for(int i = 0; i < amountOfFrames; i++){
    
    cout << "\n| " << pageTable[i].getFrame()
	 << " | " << pageTable[i].getValid()
	 << " | " << pageTable[i].getDirtyBit()
	 << " | " << pageTable[i].getLastAccess()
	 << " |" << endl;

  }
  cout << endl << endl;
}
