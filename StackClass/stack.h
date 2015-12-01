
// =======================================================

// HW1P1
// Your name: Vincent Heredia, Rika Yoshii
// Compiler:  g++
// File type: headher file stack.h

//=======================================================

//*****************************************
//PURPOSE: 
//USING: 
//USED IN:
//ALGORITHM:
//DATA STRUCTURES:
//*****************************************

const int MAX = 10;   // The MAX number of elements for the stack
// MAX is unknown to the client

typedef int el_t;      // the el_t type is 'int' for now
                      // el_t is unknown to the client


class stack
{

 private: 

  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack

 public: 

  // exception handling classes
  class Overflow{};
  class Underflow{};

  stack();   // constructor
  ~stack();  // destructor

  // HOW TO CALL: pass the element to be pushed
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  void push(el_t);

  // HOW TO CALL: provide variable to receive the popped element
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  void pop(el_t&);

  // HOW TO CALL: provide variable to reveive the top element of the stack
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  void topElem(el_t&);


  // PURPOSE: Checks if the stack is empty
  bool isEmpty();

  // PURPOSE: Checks if the stack is full
  bool isFull();

  // PURPOSE: Displays all elements in the stack
  void displayAll();

  // PURPOSE: Clears the stack of all elements
  void clearIt();

};

