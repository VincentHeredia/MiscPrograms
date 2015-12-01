//===========================================
// HW 7 part 2
//Name: Vincent Heredia
//Compiler: g++
//File Type: graph header file, dgraph.h
//===========================================

#include "slist.h"//needed for storing adjacent vertexes
#include "stack.h"//needed for storing vertexes 

int const MAX = 20;//Element slots in the Gvertex array

//Purpose: Struct for the nodes in the graph class
struct Gvertex{
  char Name;//name of vertex
  int visit;//visit mark
  int outDegree;//how many adjacent vertexs ***************************
  slist adjacent;//list of adjacent vertexs
};


//Purpose: dgraph is a graph data structor
class dgraph{

 public:
  
  //Constructor
  dgraph();
  //Deconstructor
  ~dgraph();
  
  //Purpose: Displays all elements in the graph
  void displayGraph();
  
  //Purose: Reads in input files to fill the graph
  void fillTable();
  
  //Purpose: Returns the outDegree (definition above)
  //Parameters: Takes a character to indicate which vertex
  //            is being used
  int findOutDegree(char);

  //Purpose: Returns the linked list of adjacent vertexes
  //Parameters: Takes a character to indicate which vertex
  //            is being used
  slist findAdjacency(char);

  //Purpose: Returns the amount of slots that are used in the array
  int getSize();
  
  //Purpose: Enters the given visit number for a given node
  //Parameters: Takes a int to indicate the visit number 
  //            and takes a char to indicate which node is visited
  void visit(int, char);

  //Purpose: returns true if the given vertex was already visited
  //Parameters: takes a char to indicate which node is being checked
  bool isMarked(char);
  
 private:
  
  //holds the graph vertexes
  Gvertex Gtable[MAX];
  
  int size;//size of the array
  
};//end of dgraph
