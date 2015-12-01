///===================================================
// HW4 binary tree
//Name: Vincent Heredia, Rika Yoshii
//Compiler: g++
//File Type: binstree.cpp  binary tree implementation file
//===================================================

//*****************************************
//PURPOSE: 
//RATIONALE:
//INPUTS PARAMETERS:
//OUTPUT PARAMETERS:
//RETURN: 
//ALGORITHM:
//DATA STRUCTURES:
//*****************************************

//Also give text version to the students.

// CS311 : This is the BST implementation file by Rika Yoshii

// ** Look for ** comments to complete this file for HW4
// Then if you save a completed file as text file, you will be able to compile it

#include <iostream>
using namespace std;

#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       // visit right sub tree of V
      delete V;                  // deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
  cout << endl;
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      // ** traverse left sub-tree of V recursively
      INorderTraversal(V->Left);
      // ** display V's element and do endl; 
      cout << V->Elem;
      // ** traverse right sub-tree of V recursively
      INorderTraversal(V->Right);
    }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
  cout << "Elements in the PRE order:" << endl;
  PREorderTraversal(Root);  // start pre-order traversal from the root
  cout << endl;
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      // ** display V's element and do endl;
      cout << V->Elem;
      Vertex *VLeft = V->Left;
      Vertex *VRight = V->Right;
      if(VLeft == NULL) { cout << " left child: NULL" << endl; }
      else{ cout << " left child: " << VLeft->Elem << endl; }//*********************
      if(VRight == NULL){ cout << " right child: NULL" << endl; }
      else{ cout << " right child: " << VRight->Elem << endl; }//************
      // ** traverse left sub-tree of V recursively
      PREorderTraversal(V->Left);
      // ** traverse right sub-tree of V recursively
      PREorderTraversal(V->Right);
    }
}


// PURPOSE: Adds a vertex to the binary search tree for new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
//     - smaller than the current -> go to the left
//     - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{

  Vertex *N;       // N will point to the new vertex to be inserted
  N = new Vertex;        // a new vertex is created
  N->Left  = NULL;     // make sure it does not
  N->Right = NULL;    // point to anything
  N->Elem  = E;            // put element E in it
  
  cout << "Trying to insert " << E << endl;

  if (Root == NULL)  // Special case: we have a brand new empty tree
    {
      Root = N;      // the new vertex is added as the root
      cout << "...adding " << E << " as the root" << endl; 
    }

  else  // the tree is not empty
    {
      Vertex *V;       // V will point to the current vertex
      Vertex *Parent;  // Parent will point to V's parent
      
      V = Root;        // start with the root as V
        
      while (V != NULL)  // go down the tree until you cannot go any further
	{
	  if (N->Elem == V->Elem) // special case
	    {  cout << "...error: the element already exists" << endl;
	      return; }
	  else
	    if (N->Elem < V->Elem)  // what I have is smaller than V
	      {  cout << "...going to the left" << endl; 
		// ** change Parent to be V to go down 
		Parent = V;
		// ** change V to be V's Left 
		V = V->Left;
	      }
	    else // what I have is bigger than V
	      {  cout << "...going to the right" << endl;
		// ** change Parent to be V to go down
		Parent = V;
		// ** change V to be V's Right 
		V = V->Right;
	      }

	}//end of while
      	         
      // reached NULL -- Must add N as the Parent's child

      if (N->Elem < Parent->Elem)  
	{  
	  // ** Parent's Left should point to the same place as N 
	  Parent->Left = N;
	  cout << "...adding " << E << " as the left child of " 
	       << Parent->Elem << endl;}
      else 
	{
	  // ** Parent's Right should point to the same place as N 
	  Parent->Right = N;
	  cout << "...adding " << E << " as the right child of " 
	       << Parent->Elem << endl;}

    }// end of normal case
  balanceTree(Root, NULL);
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{

  cout << "Trying to delete " << E << endl;

  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent

  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
      { cout << "...deleting the lonely root" << endl;
        delete Root; 
        Root = NULL;
        return; }  // only the Root was there and deleted it

// ** if V is the root with one child
  //Right child is the only child
  else if ((E == Root->Elem)&&(Root->Left == NULL)){
    V = Root->Right;
    delete Root;
    Root = V;
    balanceTree(Root, NULL);
    return;
  }
  //Left child is the only child
  else if((E == Root->Elem)&&(Root->Right == NULL)){
    V = Root->Left;
    delete Root;
    Root = V;
    balanceTree(Root, NULL);
    return;
  }

// Otherwise deleting something else

   V = Root;  // start with the root to look for E

   while (V != NULL)
     { 
       if ( E == V->Elem)   // found it
	 {  cout << "...removing " << V->Elem << endl;
		// ** call remove here to remove V
	   remove(V, Parent);
	   balanceTree(Root, NULL);
	   return; 
	 }
       
       else
	 if (E < V->Elem)
	   {  
	     cout << "...going to the left" << endl;
	     // ** update Parent and V here to go down 
	     Parent = V;
	     V = V->Left;
	   }
	 else
	   {  
	     cout << "...going to the right" << endl;
	     // ** update Parent and V here to go down
	     Parent = V;
	     V = V->Right;
	   }
       
     }// end of while
   
   // reached NULL  -- did not find it
   cout << "Did not find the key in the tree." << endl;
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf – delete it
// Case 2: it has just one child – bypass it
// Case 3: it has two children – replace it with the max of the left //subtree

void BST::remove(Vertex *V, Vertex *P){

  // ** if V is a leaf (case 1)
  if ((V->Left == NULL)&&(V->Right == NULL))      
    {
      cout << ".. removing a leaf" << endl;
      // ** if V is a left child of P
      if (P->Left == V)
	{
	  // ** delete V and also make Parent's left NULL 
	  delete V;
	  P->Left = NULL;
	}
      else // V is a right child of the Parent
	{ 
	  // ** delete V and also make Parent's right NULL 
	  delete V;
	  P->Right = NULL;
	}
    }

    
  // ** else if V has just the left child (case 2)
  else if((V->Left != NULL)&&(V->Right == NULL))
    {
      cout << "removing a vertex with just the left child" << endl;
      // ** Make Parent’s left or right point to the left child and       delete V (You need if then else to determine left or right)
      if(P->Left == V)
	{
	  P->Left = V->Left;
	}
      else
	{
	  P->Right = V->Left;
	}
    }       

// **else if V has just the right child
  else if((V->Left == NULL)&&(V->Right != NULL))
    {
      cout << "removing a vertex with just the right child" << endl;
      // ** Make Parent’s left or right point to the right child and delete V (need if then else to determine left or right)
      if(P->Left == V)
        {
          P->Left = V->Right;
        }
      else
        {
          P->Right = V->Right;
        }
    }

  else // V has two children (case 3)
   {  cout << "...removing an internal vertex with children" << endl;
     cout << ".....find the MAX of its left sub-tree" << endl;
     elem_t Melem;
     Melem = findMax(V); // find MAX element in the left sub-tree of V
     cout << ".....replacing " << V->Elem << " with " << Melem << endl;
     // ** Replace V's element with Melem here
     V->Elem = Melem;
   }
  balanceTree(Root, NULL);
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{

     Vertex *Parent = V;
     V = V->Left;          // start with the left child of V

       // ** while the right child of V is still available
     while (V->Right != NULL)     
       {
	 Parent = V;
	 V = V->Right;
	 // ** update Parent and V to go to the right
       }

      // reached NULL Right  -- V now has the MAX element
        elem_t X = V->Elem;
        cout << ".....Max is " << X << endl;
        remove(V, Parent);    // remove the MAX vertex 
        return X;             // return the MAX element

}// end of FindMax

//Purpose: balances the tree if it needs to be balanced
//Parameter: takes a vertex *B to start at and the parent (*P) of that vertex
void BST::balanceTree(Vertex *B, Vertex *P)
{
  if(B == NULL){ return; } //do nothing
  //if the balance factor is 0, 1, or -1 then there is nothing to do
  
  //recursive call, starts the balancing at the bottom
  // and works up
  balanceTree(B->Left, B);
  balanceTree(B->Right, B);
  
  Vertex *V;
  Vertex *C;
  int bal = balanceFactor(B);//holds the balance factor
  
  //if the balance factor is 0, 1 , or -1 then do nothing
  if((bal == 0)||(bal == 1)||(bal == -1)){
    //do nothing
    return;
  }
  else if(bal == 2){//left subtree is heavy

    V = B->Left;   
    
    if(balanceFactor(V) == -1){//double right rotation
      
      //left rotation around the left subtree
      C = V->Right;
      V->Right = C->Left;
      C->Left = V;
      B->Left = C;
      //right rotation around the base
      C = B->Left;
      B->Left = C->Right;
      C->Right = B;
      if(B == Root) { Root = C; }
      else{
	//if B is the right child
        if(P->Right == B) {P->Right = C;}
        else{ P->Left = C; }//else B is the left
      }
      cout << "double right rotation" << endl;
    }
    else{ //single right
      V = B->Left;
      B->Left = V->Right;
      V->Right = B;
      if(B == Root) { Root = V; }
      else{
	//if B is the right child
        if(P->Right == B) {P->Right = V;}
        else{ P->Left = V; }//else B is the left
      }
      cout << "Single right rotation" << endl;
    }
  }//end of else if(bal == 2)
  else if(bal == -2){//right subtree is heavy
    
    V = B->Right;
    
    if(balanceFactor(V) == 1){//double left
      //right rotation around the right subtree
      C = V->Left;
      V->Left = C->Right;
      C->Right = V;
      B->Right = C;
      //left rotation around the base
      C = B->Right;
      B->Right = C->Left;
      C->Left = B;
      if(B == Root){ Root = C; }
      else{
	//if B is the right child
        if(P->Right == B) {P->Right = C;}
        else{ P->Left = C; }//else B is the left
      }
      cout << "double left rotation" << endl;
    }
    else{ //single left
      //left rotation around the base
      V = B->Right;
      B->Right = V->Left;
      V->Left = B;
      if(B == Root){ Root = V; }
      else{ 
	//if B is the right child
	if(P->Right == B) {P->Right = V;} 
	else{ P->Left = V; }//else B is the left
      }
      cout << "single left rotation" << endl;
    }
  }//end of else if(bal == -2)
}//end of balanceTree

//Purpose: gives the balance factor of a node
//Parameters: takes vertex *V to indicate which part of the tree is being checked
int BST::balanceFactor(Vertex *V){
  //if there is nothing in the tree
  if (V == NULL){ return 0; }
  
  int HLcount = 0;//used to find the height of the Left subtree
  int HRcount = 0;//used to find the height of the Right subtree
  
  //starts a recursive call to find the hight of the left and right subtrees
  Height(V->Left, 0, HLcount);
  Height(V->Right, 0, HRcount);
  
  //cout << "Balance factor of: " << V->Elem << " is " 
  //     << HLcount << " - " << HRcount << " = " 
  //     << (HLcount - HRcount) << endl;
  
  //returns the balance factor
  return (HLcount - HRcount);
}//end of balanceFactor

//Purpose: Finds the height of a node
//Parameters: Takes a vertex *V to indicate which node to start at.
//            takes an int count to keep track of the height of a node.
//            takes an int &highestCount to find give the highest count 
//              of the nodes below the given node
void BST::Height(Vertex *V, int count, int &highestCount){
  if(V != NULL){//if the given node is not null, then the node exist
    count++;//adds to the height
    //recursive call used to give the largest height of the nodes below it
    Height(V->Left, count, highestCount);
    Height(V->Right, count, highestCount);
  }
  //if the count is the largest of all the counts, then it becomes the highest count
  if (count > highestCount) { highestCount = count; }
}//end of height
