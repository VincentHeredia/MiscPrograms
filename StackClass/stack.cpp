// =========================================================

//HW1P1 stack
//Your name: Vincent Heredia, Rika Yoshii
//Complier:  g++
//File type: Implimentation File stack.cpp

//==========================================================

//*****************************************
//PURPOSE: 
//RATIONALE:
//INPUTS PARAMETERS:
//OUTPUT PARAMETERS:
//RETURN: 
//ALGORITHM:
//DATA STRUCTURES:
//*****************************************

#include "stack.h"//header that holds class definitions
#include <iostream>//needed to output data

using namespace std;



  //Constructor, Initializes top to be -1
  stack::stack()
  { top = -1; // indicate an empty stack 
  }

  //Deconstructor
  stack::~stack(){ // nothing to do 
  }


  //Returns true if the stack is empty (top == -1), returns false if not
  bool stack::isEmpty()
  { if (top == -1) return true; else return false; }


  //Returns true if the stack is full (top == MAX-1), returns false if not
  bool stack::isFull()
  { if (top == MAX-1 ) return true; else return false; }


  //Pushes a element onto the stack if it is not full.
  //If the stack is full then a overflow error is thrown.
  void stack::push(el_t elem)
{ if (isFull()) { throw Overflow();  } // Checks for overflow error
    else { top++; el[top] = elem; } }

  //Pops an element off the stack if it is not empty.
  //IF the stack is empty then an underflow error is thrown.
  void stack::pop(el_t& elem)
{ if (isEmpty()) { throw Underflow(); } // Checks for underflow error
    else { elem = el[top]; top--;} }

  //Gives back the top most element in the stack
  //throws an underflow error if the stack is empty
  void stack::topElem(el_t& elem)
{ if (isEmpty()) { throw Underflow();  } // Checks for underflow error
    else { elem = el[top]; } }

  //Displays all the elements from the stack vertically
  //if empty, displays " [ empty ] "
  void stack::displayAll()
  { if (isEmpty()) cout << "[ empty ]" << endl;//Checks if the stack is empty
    else for (int i=top; i>=0; i--) //displays each element of the stack
    { cout << el[i] << endl; } }

  //Pops all elements out of the stack making it empty
  //if the stack is empty, leaves as is
  void stack::clearIt() 
  { 
    el_t elem;//needed to use the pop function
    if (isEmpty()) {}//checks if the stack is empty
    else for (int i=top; i>=0; i--) { pop(elem); }//Pops elements off the stack until the bottom is reached 
  }
