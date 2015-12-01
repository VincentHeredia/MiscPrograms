

// =========================================================

//HW1P1 queue
//Your name: Vincent Heredia
//Complier:  g++
//File type: Queue Implimentation

//================================================================

#include "queue.h"//contains class declaration
#include <iostream>//Needed for cout functions

using namespace std;
   
// constructor 
queue::queue()
{
  front = 0;//Front initially 0
  rear = -1;//Rear is initially -1 to indicate that there are no elements in the que
  count = 0;//Count initially 0 due to queue being empty
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0) { return true; }
  else { return false; }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE){ return true; }
  else { return false; }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t elToAdd)
{
  if (isFull()) { throw Overflow(); }
  else
    {
      rear = ((rear + 1)%(MAX_SIZE));
      el[rear] = elToAdd;
      count++;//count used to keep track of the amount of elements in the queue
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& removedEl)
{
  if (isEmpty()) { throw Underflow(); }
  else 
    {
      removedEl = el[front];
      front = ((front + 1)%(MAX_SIZE));
      count--;//count used to keep track of the amount of elements in the queue
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& frontEl)
{
  frontEl = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
// While loop tranverses the array displaying every element
void queue::displayAll()
{
  if (isEmpty()) { cout << "[ empty ]" << endl; }
  else
    {
      int i = front;

      cout << "[ ";
      
      while (i != rear)//While loop stops just before the last element
	{
	  cout << el[i] << " ";
	  i = ((i + 1)%(MAX_SIZE));
	}//End of while loop
      cout << el[i] << " ";//Prints out the last element
      
      cout << "]" << endl;
    }//End of else
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{
  el_t frontEl;
  if (count == 1) {return;}//Checks if the queue has 1 element
  else 
    {
      remove(frontEl);//takes out the first element
      add(frontEl);//puts it into the back
    }
}




