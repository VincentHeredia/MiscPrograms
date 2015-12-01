//=======================================================================
//Author: Vincent Heredia
//Date: 5/2/2015
//Course: CS433 assignment 5
//File: Frame implementation file
//=======================================================================

#include "Frame.h"


using namespace std;



//constructor
Frame::Frame(){
  frameNumber = 0;
  valid = 'I';
  dirtyBit = 'C';
}




//Purpose: Basic get function
//Parameters: None
//Returns: The desired variable
int Frame::getFrame(){
  return frameNumber;
}
//Purpose: Basic set function
//Parameters: The new variable
//Returns: Nothing
void Frame::setFrame(int newFrame){
  frameNumber = newFrame;
  return;
}

//Purpose: Basic get function
//Parameters: None
//Returns: The desired variable
char Frame::getValid(){
  return valid;
}
//Purpose: Basic set function
//Parameters: The new variable
//Returns: Nothing
void Frame::setValid(char newValid){
  valid = newValid;
  return;
}

//Purpose: Basic get function
//Parameters: None
//Returns: The desired variable
char Frame::getDirtyBit(){
  return dirtyBit;
}
//Purpose: Basic set function
//Parameters: The new variable
//Returns: Nothing
void Frame::setDirtyBit(char newDirtyBit){
  dirtyBit = newDirtyBit;
}

//Purpose: Basic get function
//Parameters: None
//Returns: The desired variable
long Frame::getLastAccess(){
  return lastAccess;
}
//Purpose: Basic set function
//Parameters: The new variable
//Returns: Nothing
void Frame::setLastAccess(long newLastAccess){
  lastAccess = newLastAccess;
}
