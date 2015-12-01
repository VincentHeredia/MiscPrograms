//=======================================================
//HW 7 part 2
//Name: Vincent Heredia
//Compiler: g++
//File type: implementation file, dgraph.cpp
//=======================================================

#include "dgraph.h"//header file for this implementation file
#include <iostream>//needed for displaying the graph
#include <fstream>//needed for reading in the graph's text file
using namespace std;

//Purpose: Constructor
dgraph::dgraph(){
  int count = 0;//used to transverse the array

  //while there is an array slot that is not filled
  while(count < MAX){
    Gvertex newVertex;//used to fill the array slot
    newVertex.Name = ' ';//intially named ' ' or null
    newVertex.visit = 0;//initally not visited
    Gtable[count] = newVertex;//fills the slot
    count++;//next slot
  }
  
  size = 0;//initially, nothing is in the array
  
}  

//Purpose: Deconstructor
dgraph::~dgraph(){
  //Deconstructor automatically calls the slist deconstructor
}

//Purpose: Fills the graph with nodes from a file
//Algorithm: Contains a loop that fills the array with
//           elements from a file until end of file is reached
void dgraph::fillTable(){
  
  ifstream fin ("table.txt", ios::in);
  
  char x;//used to fill adjacent nodes
  int count;//used to fill the outDegree variable
  int slot = 0;//used to indicate which element is being filled

  //while there is another line
  //fill an array slot with a new Gvertex element
  while(fin >> Gtable[slot].Name)
    { 
      fin >> count; //fills the outDegree
      Gtable[slot].outDegree = count;
      
      //fills the adjacent list
      for(int i = 1; i <= count; i++){
	fin >> x;
	(Gtable[slot].adjacent).addRear(x);
      }
      
      size++;//size increased
      slot++;//move to the next slot
    }//end of while loop
  fin.close();//closes the file
}//end of dgraph
 
//Purpose: Displays the current graph
void dgraph::displayGraph(){
  for(int i = 0; i < MAX; i++){
    //if array slot isnt empty
    if(Gtable[i].Name != ' '){
      cout << "Name: " << Gtable[i].Name << " "
	   << "Out Degree: " << Gtable[i].outDegree << " "
	   << "Visit number: " << Gtable[i].visit << " "
	   << "Adjacent nodes: "; 
      (Gtable[i].adjacent).displayAll(); 
      cout << endl;
    }
  }//end of for loop
}//end of displayGraph

//Purpose: Returns the outDegree of the given node, if the node
//         is not found, then -1 is returned
//Parameters: Takes a char to indicate which node is to be used
int dgraph::findOutDegree(char name){
  
  for(int i = 0; i < MAX; i++){//search for node
    //if name matches the name of the node
    if(Gtable[i].Name == name){
      return Gtable[i].outDegree;//return out degree
    }
  }//end of for loop
  cout << " Node not found " << endl;
  return -1;//node not found
}//end of findOutDegree

//Purpose: Returns the adjacency list of the given node,
//         if node is not found, returns an empty list
//Parameters: Takes a char to indicate which node is to be used
slist dgraph::findAdjacency(char name){
  
  for(int i = 0; i < MAX; i++){//search for node
    //if name matches the name of the node
    if(Gtable[i].Name == name){
      return Gtable[i].adjacent;//return out degree
    }
  }//end of for loop
  cout << " Node not found " << endl;
  slist emptyList;
  return emptyList;//node not found
}//end of findAdjacency

int dgraph::getSize(){
  return size;
}

//Purpose: Enters the given visit number for a given node
//Parameters: Takes a int to indicate the visit number
//            and takes a char to indicate which node is visited
void dgraph::visit(int num, char name){
  for(int i = 0; i < MAX; i++){//search for node
    //if name matches the name of the node
    if(Gtable[i].Name == name){
      Gtable[i].visit = num;
      return;
    }
  }//end of for loop
  //if node is not found
  cout << " Node not found " << endl; 
  return;
}//end of void vist

//Purpose: returns true if the given vertex was already visited
//Parameters: takes a char to indicate which node is being checked
bool dgraph::isMarked(char name){
  for(int i = 0; i < MAX; i++){//search for node
    //if name matches the name of the node
    if(Gtable[i].Name == name){
      if (Gtable[i].visit == 0){return false;}
      else {return true;}
    }
  }//end of for loop
  cout << " Node not found " << endl;
}//end of isMarked
