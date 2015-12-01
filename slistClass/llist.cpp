
// ====================================================

//HW3P1 llist
//Your name: Vincent Heredia
//Complier:  g++
//File type: llist implimentation file llist.cpp

//=====================================================

#include "llist.h"//needed for linked list functions
#include <iostream>//need for output
using namespace std;

//constructor
llist::llist()
{
  Front = NULL;//initalizes both front and rear to NULL
  Rear = NULL; // the list is initally empty
  Count = 0;
}//end of constructor


//Destructor  
llist::~llist()
{
  el_t OldNum;//Local variable to recieve list elements
  //while the list is not empty, delete from the front
  while(isEmpty() == false)
    {
      deleteFront(OldNum);
    }
  //shows that the deconstructor is called at the end of the program
  cout << "Calling the llist desconstructor" << endl;
}//End of deconstructor

//Purpose: checks of the list is empty
//Parameters: none
//Algorithm: if both Front and Rear == NULL then return true else return false
bool llist::isEmpty()
{
  if((Front == NULL)&&(Rear == NULL)){ return true; }
  else { return false; }
}//end of isEmpty

//Purpose: displays all nodes in the list
//Parameters: no parameters
//Algorithm: Node P moves down the list until the next node is Rear->Next
//           and prints each element out
void llist::displayAll()
{
  //checks if the list is empty
  if (isEmpty() == true){ cout << "[ empty ]" << endl; }
    else{
      Node *P;//Node used to print the elements out
      P = Front;//starts from Front
      cout << "[";
      while(P != (Rear->Next))//loops until every element is printed
	{
	  cout << " " << P->Elem;//outputs the element
	  P = P->Next;//moves P to the next element
	}
      cout << " ] " <<  endl;
    }//end of else
  
}//end of displayAll

//Purpose: adds an node to the rear
//Parameters: takes an el_t data type to put into the new node
//Algorithm: If this node is the frist in the list, sets Front and Rear to it
//           other wise a new node is added to the rear
void llist::addRear(el_t NewNum) 
{
  if(isEmpty() == true){ //if this is the first node
    Rear = new Node;
    Front = Rear;
    Rear->Elem = NewNum;
  }
  else{ //else adds node
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
  }
  Count++;
}//End of addRear

//Purpose: Deletes an node from the front
//Parameters: takes a el_t data type to load the deleted node into
//Algorithm: if the list is empty, throw underflow error
//           else deletes a node from the front
//           if this makes the list empty then front and rear are set to NULL
void llist::deleteFront(el_t& OldNum)
{
  //checks if the list is empty
  if (isEmpty() == true){ throw Underflow(); }
  else if(Front == Rear) {//if this is the last node, delete and set both rear and front to null
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  }
  else{//deletes the front node
    OldNum = Front->Elem;
    Node *Second;//used to point to the node before the front
    Second = Front->Next;
    delete Front;
    Front = Second;//sets the new front
    Count--;
  }
}//End of deleteFront

//Purpose: adds a new node to the front of the list
//Parameters: takes an el_t data type and loads it into the new node
//Algorithm: if this node is the first then the new node is added and both front and rear are set to it
//           else the new node is added to the front
void llist::addFront(el_t NewNum)
{
  if (isEmpty() == true) {//if the list is empty then set both front and rear to the new node
    Front = new Node;
    Rear = Front;
    Front->Elem = NewNum;
  }
  else{//else add a node to the front
    Node *x;
    x = new Node;
    x->Next = Front;
    Front = x;
    Front->Elem = NewNum;
  }
  Count++;
}//End of addFront

//Purpose: deletes an node from the rear
//Parameters: takes an el_t data type to load the deleted node into
//Algorithm: if the list is empty throw an Underflow error
//           else deletes the rear node 
//           if this makes the list empty then both rear and front are set to NULL
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty() == true) { throw Underflow(); }//if the list is empty throw underflow error
  else{//else delete the rear node
    OldNum = Rear->Elem;
    if (Rear != Front)//if the rear is not the same as the front delete the rear node
      {
	Node *P;
	P = Front;
	while(P->Next != Rear) { P = P->Next; }
	delete Rear;
	Rear = P;
	Rear->Next = NULL;
      }
    else//if they are equal then delete rear and set both front and rear to NULL
      {
	delete Rear;
	Front = NULL;
	Rear = NULL;
      }
    Count--;
  }
}//End of deleteRear

//Purpose: Deletes a node at the Ith index
//Parameters: takes int I to indicate which node will be deleted, takes an el_t data type
//            to load the deleted element into
//Algorithm: if the index is less than 1 or greater than the ammount of nodes there are
//           then an out of range error is thrown
//           else if the index is the same as the rear node then delete the rear node
//           else if the index is the same as the front node then delete the front
//           else delete the node at the Ith index
void llist::deleteIth(int I, el_t& OldNum)
{ 
  // if the index is out of range
  if ((I < 1)||(I > Count)) { throw OutOfRange(); }
  
  //if the index points to the rear node
  else if (I == Count) {deleteRear(OldNum);}
  
  //if the index points to the front node
  else if (I == 1) {deleteFront(OldNum);}
  
  //else the index is found and deleted
  else {
    Node *P;//points to the index's node
    Node *Pp;//points to the previous node
    P = Front;//both are initally set to the front
    Pp = Front;
    //for loop executes until P is set to the index
    for (int K = 1; K <= I-1; K++) {
      Pp = P;//      Pp is set to the previous node
      P = P->Next;// and P is set to nex
    }//end of while
    Node *Pn;//points to the node after the index
    Pn = P->Next;
    OldNum = P->Elem;
    delete P;//delete P
    P = Pn;//  set P to P next
    Pp->Next = Pn;//sets the node after the deleted index to the next node
    Count--;
  }//end of else

}//End of deleteIth

//Purpose: adds a new node before the Ith index
//Parameters: takes int I to indicate which node the new node will be inserted infront of, 
//            takes an el_t data type to load into the new element
//Algorithm: if the index is less than 1 or geater than the ammount of nodes in the list 
//           an out of range exception is thrown
//           else if the index is the same as the rear node, add to the rear
//           else if the index is the same as the front node, add to the front
//           else add the node to the index position
void llist::addbeforeIth(int I, el_t newNum)
{
  //throw an exception of the index is out of range
  if ( (I > (Count+1))||(I < 1) ) { throw OutOfRange(); }
  
  //add to the rear if the index is the same as the rear
  else if (I == (Count+1)) { addRear(newNum); }
  
  //add to the front if the index is the same as the front
  else if (I == (1)) { addFront(newNum); }
  
  else {//add to the index position
    Node *NewP;//the new node
    NewP = new Node;
    Node *Pn;// the node after the index position
    Node *Pp;// the node before the index position
    Pn = Front;//both initially start at the front
    Pp = Front;
    //for loop executes until the index position is reached
    for (int K = 1; K <= I-1; K++) {
      Pp = Pn;//      Pp is set to the next node
      Pn = Pn->Next;//Pn is set to its next node
    }//end of while
    Pp->Next = NewP;//the new node becomes the next node for Pp
    NewP->Next = Pn;//the next node becomes the previous node for Pn
    NewP->Elem = newNum;
    Count++;
  }//end of else

}//end of addbeforeIth



