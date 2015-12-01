//==========================================================

//HW3P2 slist
//Name: Vincent Heredia
//Compiler: g++
//File Type: slist.h header file

//=========================================================

#include "llist.h"//Inherits from this class

//Class creates a linked list inheriting from the llist object
class slist : public llist
{

 public:
  
  //constructor
  slist();
  
  //Purpose: Searches the list for an element
  //Parameters: takes an el_t data type to search for in the llist nodes
  int search(el_t Key);
    
  //Purpose: Replaces an element in a node with a new element
  //Parameters: takes an el_t data type to replace the old element with
  //            takes an int I to indicate which index the node is add
  void replace(el_t Elem, int I);
  
};
