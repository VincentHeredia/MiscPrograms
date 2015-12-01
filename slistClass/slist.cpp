//=================================================

// HW3P2 slist
//Name: Vincent Heredia
//Compiler: g++
//File Type: slist.cpp implementation file

//=================================================

#include "slist.h"//header file of this class
#include <iostream>//needed to know what NULL is
using namespace std;

//Constructor
slist::slist() : llist()
{
  
}

//No deconstructor

//Purpose: Searches the list to find an element
//Parameters: takes an el_t data type to search the list for
//Algorithm: checks ever node for the element until it either finds it
//           or falls off the list
int slist::search(el_t Key)
{
  int position = 1;//Indicates which position the element is found at
                   //This increases every time a comparison returns false
                   //Initially set to 1

  Node *P;//Node pointer used to find elements
  P = Front;//starts from the Front of the list
  
  //while P is not pointing to the end of the list
  while (P != NULL){
    //if the searched element is in the node return the position
    if (Key == P->Elem) { return position; }
    //if not, then move to the next node
    else { P = P->Next; position++; }
  }//end of while
  return 0;//if it is not found returns 0
}//end of search function


//Purpose: Replaces an element in a node with a new element
//Parameters: takes an el_t data type to replace the old node's element with
//            takes an int I to indicate the index of the node
//Algorithm: checks if the index given is out of range of the list
//           if not then go to the index and replace the node's element
void slist::replace(el_t Elem, int I)
{
  //if the index is out of range
  if ((I > Count)||(I < 1)) { throw llist::OutOfRange(); }
  
  //else replace the node's element with the new element
  else {
    
    Node *P;//new node pointer to go to the index
    P = Front;//pointer stars at the Front node
    
    //moves the pointer down the list until the index is reached
    for (int K = 1; K <= I-1; K++) {
      P = P->Next;
    }//end of for
    
    //replaces the element in the node with the new element
    P->Elem = Elem;
  }//end of else

}//end of replace function
