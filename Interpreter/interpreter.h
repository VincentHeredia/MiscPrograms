//*****************************************
//PURPOSE: This class is used to interpret pseudo code
//USING: user can use the instructionExe to interpret a text file.
//USED IN: N/A
//ALGORITHM: instructionExe: calls dataRead to fill the array with
//                           the data, then it runs a loop to 
//                           execute the program.
//           dataReader: reads in the data from the text file
//                       into the array.
//           Instruction functions: These are used to mimic the 
//                                  pseudo code in the text file.
//                                  Mostly simple code with some
//                                  error checks.
//DATA STRUCTURES: To store the data from the pseudo code, an array
//                 is used. The first half (1-999) is used for values,
//                 the second half is used for instructions.
//*****************************************
#include <iostream>
#include <fstream>
using namespace std;


class interpreter
{
 public:

  interpreter();//constructor
  ~interpreter();//deconstructor

  //*********************************************
  //Purpose: This function is used start the interpretation of the pseudo code
  //Rationale: This function allows the user to input a text file with the pseudo code
  //Input Parameters: takes a string indicating the text file with the data
  //Algorithm: calls dataRead to fill the array with the data, then it runs a loop to
  //           execute the program.
  //Data Structures: To store the data from the pseudo code, an array
  //                 is used. The first half (1-999) is used for values,
  //                 the second half is used for instructions.
  //********************************************
  void instructionExe(string fileName);

 private:
   
  int memory[2000];//array used to store memory
  int ACC;//used to preform operations on
  int PC;//used to keep track of which instruction the program is on
  int instruction;//used to execute the instruction
  int memoryUsed;//keeps track of how much of the value memory is in use
  

  //*********************************************
  //Purpose: Reads in the data from the pseudo code text file
  //Rationale: This function is here for organization purposes
  //Input Parameters: takes a string indicating the text file with the data
  //Algorithm: runs two loops to fill in the values from the pseudo code, then the
  //           instructions, in that order
  //Data Structures: uses the memory array
  //********************************************
  void dataReader(string fileName);

  //=========Instruction functions===========
  
  //*********************************************
  //Purpose: This function loads the ACC with the contents of XXX
  //Rationale: used to replicate the 1XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the ACC
  //********************************************
  //1XXX
  void loadAcc (int value);
  
  //*********************************************
  //Purpose: This function stores the value from the ACC to 
  //         a location in the memory array
  //Rationale: used to replicate the 2XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the memory element indicated 
  //                   by the value passed to the function
  //********************************************
  //2XXX
  void storeAcc (int value);
  
  //*********************************************
  //Purpose: This function adds the contents of XXX to the ACC
  //Rationale: used to replicate the 3XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the ACC
  //********************************************
  //3XXX
  void addCont (int value);
  
  //*********************************************
  //Purpose: This function subtracts the contents of XXX from the ACC
  //Rationale: used to replicate the 4XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the ACC
  //********************************************
  //4XXX
  void subtractCont (int value);
  
  //*********************************************
  //Purpose: This function multiplies the contents of XXX and the ACC
  //Rationale: used to replicate the 5XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the ACC
  //********************************************
  //5XXX
  void multiplyCont (int value);
  

  //*********************************************
  //Purpose: This function divides the ACC by the contents of XXX
  //Rationale: used to replicate the 6XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the ACC
  //********************************************
  //6XXX
  void divideAcc (int value);
  
  //*********************************************
  //Purpose: This function branches to the indicated instruction
  //         if the ACC is positive
  //Rationale: used to replicate the 7XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the PC
  //Returns: -1 if the function is not true, otherwise it returns the value
  //         and overrides the PC
  //********************************************
  //7XXX
  int branchPos (int value);
  
  //*********************************************
  //Purpose: This function branches to the indicated instruction
  //         if the ACC is negative
  //Rationale: used to replicate the 8XXX instruction
  //Input Parameters: takes the value from the instruction
  //Output Parameters: changes the PC
  //Returns: -1 if the function is not true, otherwise it returns the value
  //         and overrides the PC
  //********************************************
  //8XXX
  int branchNeg (int value);
  

  //*********************************************
  //Purpose: This function is run to stop the program
  //Rationale: used to replicate the 9XXX instruction
  //Returns: returns true to change the program running status
  //********************************************
  //9XXX
  bool stop ();
  //========================================
};
