/*  BSTree2.cpp  
 *
 *  Binary Search Tree Implementation with Deletion.
 */


#include <iostream>

#include "BSTree2.h"

//#define DEBUG_DELETE


//  ~BinarySearchTree() 
//    Delete BST object

using namespace std;

BinarySearchTree::~BinarySearchTree()
{
   DeleteBST( rootPtr );
}


// IsLeaf()                                       
//   Test if a node is a leaf

bool  BinarySearchTree::IsLeaf( TreePtr treePtr)
{
   return ((treePtr->leftPtr  == NULL) &&
           (treePtr->rightPtr == NULL)    );
}


// DeleteBST()                                       
//   Delete an entire BST.  All memory is released
//   using a "PostOrder" traversal method.

void BinarySearchTree::DeleteBST( TreePtr& treePtr )
{
   if( treePtr != NULL )
   {
      DeleteBST( treePtr->leftPtr );
      DeleteBST( treePtr->rightPtr );
      
      delete  treePtr;
      treePtr = NULL;
   }
}

// AddNode()           
//   Add (insert) new item into the BST, whose 
//   root node is pointed to by "rootPtr".  If 
//   the data already exists, it is ignored.

void BinarySearchTree::AddNode( DATA_TYPE newData )
{
   TreePtr newPtr;

   newPtr = new BSTreeNode;
   // Add new data in the new node's data field
   newPtr->data     = newData;
   newPtr->leftPtr  = NULL;
   newPtr->rightPtr = NULL;
   
   //  If the BST is empty, insert the new data in root
   if( rootPtr == NULL )
   {
      rootPtr = newPtr;
   }
   else   //  Look for the insertion location
   {
      TreePtr   treePtr = rootPtr;
      TreePtr   targetNodePtr;
      
      while( treePtr != NULL )
      {
        targetNodePtr = treePtr;
        if( newData.title == treePtr->data.title ) 
           // Found same data; ignore it. 
           return;
        else if( newData.title < treePtr->data.title ) 
           // Search left subtree for insertion location
           treePtr = treePtr->leftPtr; 
        else   //  newData > treePtr->data 
           // Search right subtree for insertion location
           treePtr = treePtr->rightPtr; 
      }
 
      //  "targetNodePtr" is the pointer to the
      //  parent of the new node.  Decide where 
      //  it will be inserted.
      if( newData.title < targetNodePtr->data.title )
         targetNodePtr->leftPtr = newPtr;
      else  // insert it as its right child
         targetNodePtr->rightPtr = newPtr;
    }
}


// PrintTree()
//   Print a BST tree uses InOrder traversal by default.

void BinarySearchTree::PrintTree() 
{ 
    PrintBST_InOrder( rootPtr );
}

void BinarySearchTree::HandRoot()
{
  ActNum(rootPtr);
  YearNum(rootPtr);
}

// PrintInOrder()
//   Print BST using InOrder traversal

void BinarySearchTree::PrintYear()
{
  cout << endl;
  cout << "Movies released in 1967: " << endl;
  for (int i = 0; i < p; i++)
    cout << year1[i] << endl;
  cout << endl;
  cout << "Movies released in 1998: " << endl;
  for (int i = 0; i < q; i++)
    cout << year2[i] << endl;
  cout << endl;
}

void BinarySearchTree::ActNum(TreePtr treePtr)
{
  int i = 0;
  if (treePtr != NULL)
    {    
      while (treePtr->data.actor[i] != "")
        {
          if (treePtr->data.actor[i] == "Matt Damon")
            {
              act1[a] = treePtr->data.title;
              a++;
            }
          else if (treePtr->data.actor[i] == "Carrie Fisher")
            {
              act2[b] = treePtr->data.title;
              b++;
           }
          else if (treePtr->data.actor[i] == "Steve McQueen")
            {
              act3[c] = treePtr->data.title;
              c++;
            }
          else if (treePtr->data.actor[i] == "Ludacris")
            {
             act4[d] = treePtr->data.title;
             d++;
            }
          else if (treePtr->data.actor[i] == "Morgan Freeman")
            {
              act5[e] = treePtr->data.title;
             e++;
            }
          i++;
        }
      ActNum(treePtr->rightPtr);
      ActNum(treePtr->leftPtr);      
    }
}

void BinarySearchTree::YearNum(TreePtr treePtr)
{
  if (treePtr != NULL)
    {
      if (treePtr->data.year == "1967)")
        {
          year1[p] = treePtr->data.title;
          p++;
        }
      else if (treePtr->data.year == "1997)")
        {
          year2[q] = treePtr->data.title;
          q++;
        }
      YearNum(treePtr->rightPtr);
      YearNum(treePtr->leftPtr);
    }
}  

void BinarySearchTree::PrintAct()
{
  cout << "Matt Damon appeared in: " << endl;
  for (int i = 0; i < a; i++)
    cout << act1[i] << endl;
  cout << endl;
  cout << "Carrie Fisher appeared in: " << endl;
  for (int i = 0; i < b; i++)
    cout << act2[i] << endl;
  cout << endl;
  cout << "Steve McQueen appeared in: " << endl;
  for (int i = 0; i < c; i++)
    cout << act3[i] << endl;
  cout << endl;
  cout << "Ludacris appeared in: " << endl;
  for (int i = 0; i < d; i++)
    cout << act4[i] << endl;
  cout << endl;
  cout << "Morgan Freeman appeared in: " << endl;
  for (int i = 0; i < e; i++)
    cout << act5[i] << endl;
}

void
BinarySearchTree::PrintBST_InOrder(
                TreePtr treePtr )
{
  int i = 0;
  if( treePtr != NULL)
    {
      // Print left BST subtree
      PrintBST_InOrder( treePtr->leftPtr );
      // Print Root node data
      cout << treePtr->data.title << endl;
      if (treePtr->data.title == "Blade Runner" || treePtr->data.title == "The Bourne Ultimatum" || treePtr->data.title == "Logan's Run" || treePtr->data.title == "2 Fast 2 Furious" || treePtr->data.title == "Zero Tolerance")
        while (treePtr->data.actor[i] != "")
         {
           cout << treePtr->data.actor[i] << endl;
           i++;
         }
      cout << endl;
      // Print right BST subtree
      PrintBST_InOrder( treePtr->rightPtr );    
      
   }
  
}
