
//****************************************************************************
//  CS311 Linked - by Rika for those who could not get HW3 to work
//  Header File  llist.h
//  Name: Vincent Heredia
//  Compiler: g++
//  File Type: Header file llist.h
//****************************************************************************

typedef int el_t ;//defined as an int for now

// list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

//llist is a linked list data structure
class llist 
{
  
 protected:
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public:
  
  class Underflow{};//if the user trys to delete an element from an empty stack
  class OutOfRange{};//if the user trys to add or delete an element that is out of range
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  //Purpose: Checks if the list is empty
  //How to call: takes no parameters, gives back true or false
  bool isEmpty();
    
  //Purpose: displays all elements in the list
  //How to call: takes no parameters, gives nothing back,
  //             uses cout to display
  void displayAll();
    
  //Purpose: adds an element to the rear
  //How to call: takes a data type el_t to store in the new element
  //             gives nothing back
  void addRear(el_t NewNum);
    
  //Purpose: deletes an element from the front
  //How to call: takes a data type el_t to store the deleted element
  //             gives nothing back
  void deleteFront(el_t& OldNum);
    
  //Purpose: adds an element to the front
  //How to call: takes a data type el_t to store in the new element
  //             gives nothing back
  void addFront(el_t NewNum);
    
  //Purpose: deletes an element from the rear
  //How to call: takes a data type el_t to store the deleted element
  //             gives nothing back
  void deleteRear(el_t& OldNum);
    
  //Purpose: deletes an element from the Ith index 
  //How to call: takes an int I to find the index position, 
  //             takes a data type el_t to store the deleted element
  //             gives nothing back
  void deleteIth(int I, el_t& OldNum);
    
  //Purpose: adds an element before the Ith index
  //How to call: takes an int I to find the index position
  //             takes a data type el_t to store in the new element
  //             gives nothing back
  void addbeforeIth(int I, el_t newNum);
    
};
