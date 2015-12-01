//**************************************************************
//PURPOSE: This program is an interpreter for pseudo code
//IMPLEMENTAED BY: Vincent Heredia
//COURSE: CS 351
//INSTRUCTOR: Shaun-Inn Wu
//LAB SESSION: N/A
//LAB INSTRUCTOR: N/A
//DATE: 9/3/2014
//INPUT: No input required, it is possible to change the text file that the
//       program runs by changing the string in the function below.
//OUTPUT: Output to console
//ALGORITHM: This program runs two main functions. The first loads the data
//           into an array. The second runs the instructions from said array
//           and calls functions depending on the instructions.
//DATA STRUCTURES: Memory of the pseudo code is managed by an array.
//OVERVIEW OF SUBPARTS: This program only contains one class.
//**************************************************************
#include "interpreter.h"

int main(){

  interpreter myInterpreter;

  myInterpreter.instructionExe("pseudocode.txt");
}
