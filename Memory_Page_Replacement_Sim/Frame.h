//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: Frame header file
//=======================================================================


#ifndef FRAME_H
#define FRAME_H

#include <iostream>

using namespace std;


//Purpose: This class is used to store frame information 
class Frame{
 public:

  //constructor
  Frame();

  //Purpose: Basic get function
  //Parameters: None
  //Returns: The desired variable
  int getFrame();
  //Purpose: Basic set function
  //Parameters: The new variable
  //Returns: Nothing
  void setFrame(int newFrame);

  //Purpose: Basic get function
  //Parameters: None
  //Returns: The desired variable
  char getValid();
  //Purpose: Basic set function
  //Parameters: The new variable
  //Returns: Nothing
  void setValid(char newValid);

  //Purpose: Basic get function
  //Parameters: None
  //Returns: The desired variable
  char getDirtyBit();
  //Purpose: Basic set function
  //Parameters: The new variable
  //Returns: Nothing
  void setDirtyBit(char newDirtyBit);

  //Purpose: Basic get function
  //Parameters: None
  //Returns: The desired variable
  long getLastAccess();
  //Purpose: Basic set function
  //Parameters: The new variable
  //Returns: Nothing
  void setLastAccess(long newLastAccess);

 private:

  int frameNumber;
  char valid;//valid bit
  char dirtyBit;//dirty bit
  long lastAccess;//the time of the last access of the variable
};


#endif 
