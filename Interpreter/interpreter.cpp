//*****************************************
//PURPOSE: Contains the interpreter class
//RATIONALE: N/A
//INPUTS PARAMETERS:N/A
//OUTPUT PARAMETERS: N/A
//RETURN: N/A
//ALGORITHM: N/A
//DATA STRUCTURES: Array
//*****************************************

#include "interpreter.h"
using namespace std;

//constructor
interpreter::interpreter(){
  
  ACC = 0;
  PC = 1000;
  memoryUsed = 0;
}

//deconstructor
interpreter::~interpreter(){
}

//*********************************************
//Purpose: Reads in the data from the pseudo code text file
//Rationale: This function is here for organization purposes
//Input Parameters: takes a string indicating the text file with the data
//Algorithm: runs two loops to fill in the values from the pseudo code, then the
//           instructions, in that order
//Data Structures: uses the memory array
//********************************************
void interpreter::dataReader(string fileName){
  
  int count = 0;
  int data = 0;//holds data from file
  bool stopInstruction = false;

  ifstream codeFile;
  codeFile.open (fileName.c_str());//c_str() needed for the function to
  //                                 use a string.

  if (codeFile.is_open() == true)//check to make sure the file opened
    {
      
      //reads in data to first half of memory (the 'values' section)
      //read in values until 9999
      while ((count != 999)&&(stopInstruction == false)){
	
	codeFile >> data;
	
	if (data == 9999){ stopInstruction = true; }
	else if (data > 9999) { cout << "Value is greater than 9999, discarding" << endl; }
	else { memory[count] = data; memoryUsed++; }

	count++;
      }
      //Possible error: Value memory becomes full. Program will still run, but values
      //                could have bleed into the instructions if the user inputed
      //                a file with more than 1000 values.
      if (count == 999) { cout << "Value memory full, possible errors in output" << endl; }
      
      stopInstruction = false;//reset for the next section of memory
      count = 1000;//next section of memory is 1000-2000
      
      //reads in data to the second half of memory (the 'instructions' section)
      //read in instructions until 9999
      while ((count != 2000)&&(stopInstruction == false)){

	codeFile >> data;
	
	if (data == 9999){ stopInstruction = true; }
	else if (data > 9999) { cout << "Instruction is greater than 9999, discarding" << endl; }
	else { memory[count] = data; }

	count++;
      }
      //Possible Error: Instruction memory becomes full. Program will still
      //                run, but instructions might have been cut off. 
      //                instructions will only be cut off if the user
      //                inputed a file that has more than 1000 instructions.
      if (count == 2000) { cout << "Instruction memory full, possible"  
				<< " instructions missing from output" << endl; 
      }
      codeFile.close();//closes the open file

    }//end of   if (codeFile.is_open() == true)
  else { cout << "File failed to open" << endl; }//if file fails to open
}

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
void interpreter::instructionExe(string fileName){
  
  int test = 0;//used to test program
  int instruction = 0;//used to hold the instructions
  int value = 0;//used to hold the value from memory
  bool programStop = false;//swaps once the 9000 instruction goes off

  dataReader(fileName);//stores values in the memory

  //programStop flips when stop() function runs
  //if PC reaches 2000 then the program has reached the instruction memory limit
  //and the program ends.
  while ((programStop == false)&&(PC != 2000)) {
    
    //output to show current program state
    cout << "ACC: " << ACC << " PC: " << PC%1000//instructions are in the 1000-1999 range of the array 
	 << endl << "Last Instruction: " << instruction;
    cout << " Memory: ";
    for (int i = 0; i < memoryUsed; i++)
      { cout << i << ":" << memory[i] << " "; }

    instruction = memory[PC];
    value = instruction%1000;//takes off the value
    instruction = instruction/1000;//takes off the instruction

    cout << endl << "Next Instruction: " << instruction 
	 << " Value: " << value << "\n\n";

    switch(instruction){//switch takes the instruction and runs the corresponding function
    case 1:
      loadAcc(value); PC++;
      break;
    case 2:
      storeAcc(value); PC++;
      break;
    case 3:
      addCont(value); PC++;
      break;
    case 4:
      subtractCont(value); PC++;
      break;
    case 5:
      multiplyCont(value); PC++;
      break;
    case 6:
      divideAcc(value); PC++;
      break;
    case 7:
      PC = branchPos(value);
      if(value == -1){PC++;}
      break;
    case 8:
      PC = branchNeg(value);
      if(value == -1){PC++;}
      break;
    case 9:
      programStop = stop();//finishes the loop and ends the program
      PC++;
      break;
    default:
      cout << "Not an instruction" << endl;
      PC++;
    }//end of switch

    cout << "\n\n";
  }//end of while loop
  //If PC == 2000, program ends before instructions
  if (PC == 2000) { cout << "Error: end of instruction memory, program ending" << endl; }
}//end of interpreter()

// Instruction Functions
//-----------------------------------------------------------

//*********************************************
//Purpose: This function loads the ACC with the contents of XXX
//Rationale: used to replicate the 1XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the ACC
//********************************************
//1XXX
//Loads the ACC with value from XXXX
//Possible errors: load from an empty slot - Program catches this error
void interpreter::loadAcc (int value){
  //if the memory slot is greater or equal to the memoryUsed, then
  //location must be a slot that does not contain a integer
  if (value >= memoryUsed) { 
    cout << "Error: memory location does not exist" << endl; 
  }
  else { ACC = memory[value]; }
  return;
}

//*********************************************
//Purpose: This function stores the value from the ACC to
//         a location in the memory array
//Rationale: used to replicate the 2XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the memory element indicated
//                   by the value passed to the function
//********************************************
//2XXX
//stores the ACC value into memory slot XXX
//Possible errors: storage in a previously unoccupied slot - program compinsates for this
void interpreter::storeAcc (int value){
  if (value >= memoryUsed) { memory[value] = ACC; memoryUsed = value+1; }
  else { memory[value] = ACC; }
  return;
}

//*********************************************
//Purpose: This function adds the contents of XXX to the ACC
//Rationale: used to replicate the 3XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the ACC
//********************************************
//3XXX
//adds the contents of XXX to the ACC
//Possible errors: integer becomes larger than 9999 or smaller than -9999 - program catches this
void interpreter::addCont (int value){
  if(ACC + memory[value] > 9999){
    cout << "Integer too large, returning 9999" << endl;
    ACC = 9999;
  }
  else if(ACC + memory[value] < -9999){
    cout << "Integer too small, returning -9999" << endl;
    ACC = -9999;
  }
  else { ACC = ACC + memory[value]; }
  return;
}

//*********************************************
//Purpose: This function subtracts the contents of XXX from the ACC
//Rationale: used to replicate the 4XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the ACC
//********************************************
//4XXX
//subtracts the contents of XXX from the ACC
//Possible errors: integer becomes larger than 9999 or smaller than -9999 - program catches this
void interpreter::subtractCont (int value){
  if(ACC - memory[value] > 9999){
    cout << "Integer too large, returning 9999" << endl;
    ACC = 9999;
  }
  else if(ACC - memory[value] < -9999){
    cout << "Integer too small, returning -9999" << endl;
    ACC = -9999;
  }
  else { ACC = ACC - memory[value]; }
  return;
}


//*********************************************
//Purpose: This function multiplies the contents of XXX and the ACC
//Rationale: used to replicate the 5XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the ACC
//********************************************
//5XXX
//Multiply contents of XXX to ACC
//Possible errors: integer becomes larger than 9999 or smaller than -9999 - program catches this
void interpreter::multiplyCont (int value){
  if(ACC * memory[value] > 9999){
    cout << "Integer too large, returning 9999" << endl;
    ACC = 9999;
  }
  else if(ACC * memory[value] < -9999){
    cout << "Integer too small, returning -9999" << endl;
    ACC = -9999;
  }
  else { ACC = ACC * memory[value]; }
  return;
}

//*********************************************
//Purpose: This function divides the ACC by the contents of XXX
//Rationale: used to replicate the 6XXX instruction
//Input Parameters: takes the value from the instruction
//Output Parameters: changes the ACC
//********************************************
//6XXX
//Divide the ACC by contents of XXX
//Possible errors: divide by 0 - program catches this
void interpreter::divideAcc (int value){
  if(memory[value] != 0) { ACC = ACC / memory[value]; }
  else { cout << "Cannot divide by zero" << endl; }
  return;
}

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
//Branch to instruction XXX if ACC is positive 
int interpreter::branchPos (int value){
  if (ACC > 0) {
    return (value + 1000); //adds 1000 because insturctions are in the 2nd half of memory
  }//if ACC
  else{}
  return -1;
}//end of branchPos

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
//Branch to instruction XXX if ACC is negative
//Possible errors: branch does not exist, program does not catch this
int interpreter::branchNeg (int value){
  if (ACC < 0) { 
    return (value + 1000); //adds 1000 because instructions are in the 2nd half of memory
  }//if ACC
  else{}
  return -1;
}//end of branchNeg

//*********************************************
//Purpose: This function is run to stop the program
//Rationale: used to replicate the 9XXX instruction
//Returns: returns true to change the program running status
//********************************************
//9XXX
//function runs to notify that the program is ending
//Possible errors: branch does not exist, program does not catch this
bool interpreter::stop (){
  cout << "Program ending" << endl;
  return true;//returns true to stop the while loop
}
//-----------------------------------------------------------
