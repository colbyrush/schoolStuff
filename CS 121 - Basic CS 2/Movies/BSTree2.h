/*  BSTree2.h
 *
 *  Interface for Binary Search Tree class WITH
 *  deletion.
 */

#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <string>

using namespace std;

struct movie
{
  string title;
  string year;
  string actor[50];
};

typedef	 struct movie    DATA_TYPE;  // Type of node's data

class BinarySearchTree {
  private:
    typedef struct  BSTreeNode {
       DATA_TYPE     data;
       BSTreeNode   *leftPtr;
       BSTreeNode   *rightPtr;
    } *TreePtr;
    int      a, b, c, d, e, q, p;    
    
    TreePtr rootPtr;   //  root of the BST
    void     InitBSTree()
                 { rootPtr = NULL; }
    void     DeleteBST( TreePtr& treePtr );
    bool     IsLeaf( TreePtr treePtr );
    void     YearNum(TreePtr treePtr);
    void     ActNum(TreePtr treePtr);
    void     PrintBST_InOrder(   TreePtr treePtr );
  public:
    BinarySearchTree() 
                 {
                   InitBSTree();
                   a = 0, b = 0, c = 0, d = 0, e = 0, q = 0, p = 0;
                 }
    ~BinarySearchTree();
    string   act1[20], act2[20], act3[20], act4[20], act5[20], year1[50], year2[50];
    bool     IsEmpty()
                 { return (rootPtr == NULL); }
    void     AddNode( DATA_TYPE newData );
    void     HandRoot();
    void     PrintTree();
    void     PrintAct();
    void     PrintYear();
};

#endif
