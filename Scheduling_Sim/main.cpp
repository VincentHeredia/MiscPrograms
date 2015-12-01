//=========================================================
//Author: Vincent Heredia
//Date: 3/23/15
//Course: 433
//Assignment 3
//Purpose: This program aims to simulate and analyze various scheduling algorithms.
//Assumptions: This program only simulates 300 seconds of run time.
//To run: The program will prompt the user to either run FCFS or SJF,
//        then the user will enter how many processes they want to run within the 300 second timelimit.
//=========================================================



#include <iostream>
#include <fstream>
#include <string>
#include "random.h"
#include "FCFS.h"
#include "SJF.h"

//main function, prompts the user to enter various commands to run the scheduling algorithms
int main(){
  std::cout << "Scheduling Algorithms Simulation, by Vincent Heredia" << std::endl;
  
  std::string userInput;//user input held here
  int userIn;//number for determining how many processes will run
  bool notDone = true;//flag for exiting the program

  while (notDone){//while user has not typed 0

    std::cout << "Enter 1 for First-Come First-Serve\n"
	      << "Enter 2 for Shortest job first\n" 
	      << "Enter 0 to quit\n"
	      << "Enter: ";
    std::cin >> userInput;//get user input
    std::cout << std::endl;

    switch(userInput[0]){
    case '1'://FCFS
      std::cout << "Input amount of processes\nEnter: ";
      std::cin >> userIn;
      startFCFS(userIn);
      break;
    case '2'://SJF
      std::cout << "Input amount of processes\nEnter: ";
      std::cin >> userIn;
      startSJF(userIn);
      break;

    case '0'://exit
      notDone = false;
      break;
    }

    std::cout << std::endl;
  }
  return 0;
}
