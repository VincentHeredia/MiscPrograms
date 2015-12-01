//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: Main file of the program
//Summary: This program aims to simulate page replacement algorithms
//Assumptions: None
//Special Instructions: The program runs in a loop, letting the user
//enter commands. The user can select one of three
//page replacement algorithms and change the amount
//of instructiosn that are read from the reference.txt file.
//=======================================================================



#include <iostream>
#include <string>
#include "FIFO.h"
#include "Random.h"
#include "LRU.h"
using namespace std;

//Purpose: Gets the user's page and physical memory size
//Parameter: Select = 0 means get the user's page size, select = 1 means get the physical memory size
// Page size is only used when the user is entering the physical memory size
//Returns: the user's input if successful, -1 if not
int getPageOrPhysicalMemorySize(int select, int pageSize);


//Purpose: Main function of the program. Lets the user run specific algorithms for paging.
//   The user can enter in commands to run specific algorithms with different parameters.
//Returns: int
int main(){
  cout << "Program assignment 5, by Vincent Heredia" << endl;
  

  bool notDone = true;//when the user inputs 0, this is turned to false and the program ends
  string userInput = "";//the user picks which algorithm to run
  int userPageSize = 0;//the user's page size
  int userPhysicalMemorySize = 0;//the user's physical memory size
  int limit = 5000000;//limits the number of instructions the program reads


  //------------------------Main loop------------------------
  while(notDone){
    cout << "\nType 1 for Random, "
	 << "\n2 for FIFO, "
	 << "\n3 for LRU, "
	 << "\n4 to change the amount of instructions executed (default 5,000,000), "
	 << "\n0 to quit\nEnter: ";
    getline(cin, userInput);//get user input

    //random
    if(userInput == "1"){
      userPageSize = getPageOrPhysicalMemorySize(0, 0);//get page size
      userPhysicalMemorySize = getPageOrPhysicalMemorySize(1, userPageSize);//get physical memory size

      //if either function failed
      if( (userPageSize == -1) || (userPhysicalMemorySize == -1) ){
	cout << "Invalid input" << endl;
      }
      else{
	cout << "Page Size: 2^" << userPageSize << " Physical Memory Size: 2^" << userPhysicalMemorySize << endl;
	//run random
	RandomAlg random;
	random.runRandom(userPageSize, userPhysicalMemorySize, limit);
      }
    }

    //FIFO
    else if(userInput == "2"){
      userPageSize = getPageOrPhysicalMemorySize(0, 0);//get page size
      userPhysicalMemorySize = getPageOrPhysicalMemorySize(1, userPageSize);//get physical memory size

      //if either function failed
      if( (userPageSize == -1) || (userPhysicalMemorySize == -1) ){
	cout << "Invalid input" << endl;
      }
      else{
	cout << "Page Size: 2^" << userPageSize << " Physical Memory Size: 2^" << userPhysicalMemorySize << endl;
	//run FIFO
	FIFO fifo;
	fifo.runFIFO(userPageSize, userPhysicalMemorySize, limit);
      }
    }

    //LRU
    else if(userInput == "3"){
      userPageSize = getPageOrPhysicalMemorySize(0, 0);//get page size
      userPhysicalMemorySize = getPageOrPhysicalMemorySize(1, userPageSize);//get physical memory size

      //if either function failed
      if( (userPageSize == -1) || (userPhysicalMemorySize == -1) ){
	cout << "Invalid input" << endl;
      }
      else{
	cout << "Page Size: 2^" << userPageSize << " Physical Memory Size: 2^" << userPhysicalMemorySize << endl;
	//run LRU
	LRU lru;
	lru.runLRU(userPageSize, userPhysicalMemorySize, limit);
      }
    }
    else if (userInput == "4"){
      cout << "Input the amount of instructions you wish\n"
	   <<"to execute(between 1 and 5,000,000)\nEnter: ";
      getline(cin, userInput);
      int tempInt = atoi(userInput.c_str());

      if ( (tempInt < 1) || (tempInt > 5000000) ){
	cout << "Invalid input" << endl;
      }
      else{
	limit = tempInt;
      }

    }
    else if(userInput == "0"){
      notDone = false;
      continue;
    }
    else{
      cout << "Invalid input: " << userInput << endl;
    }
    
    cout << "\n\n" << endl;
  }//end of while
  //------------------------End of main loop------------------------


  cout << "Exiting program..." << endl;
  return 1;
}//end of main



//Purpose: Gets the user's page and physical memory size
//Parameter: Select = 0 means get the user's page size, select = 1 means get the physical memory size
// Page size is only used when the user is entering the physical memory size
//Returns: the user's input if successful, -1 if not
int getPageOrPhysicalMemorySize(int select, int pageSize){
  string userInput;
  int userInt;

  if(select == 0){
    cout << "\nSpecifiy a page size between 2^8 and 2^13\nEnter: 2^";
  }
  else if(select == 1){
    cout << "\nSpecifiy the physical memory size (should be bigger than the page size)\nEnter: 2^";
  }
  else{
    cout << "Invalid parameter" << endl;
    return -1;
  }

  getline(cin, userInput);

  userInt = atoi(userInput.c_str());

  if ( (select == 0) && ((userInt >= 8) && (userInt <= 13)) ){
    return userInt;
  }
  //if the user's physical memory size is less than the pageSize
  else if( (select == 1) && (pageSize <= userInt) && (userInt <= 100) ){
    return userInt;
  }
  else{
    return -1;
  }
}
