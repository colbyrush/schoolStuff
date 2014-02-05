/* Colby Rush     CS 121-2
   Lab 7          3/24/2011 */

#include <iostream>

using namespace std;

struct op 
{
  char opr;
  int op1, op2;
  int apply();
};

struct stacknode
{
  op info;
  stacknode * next;
};

typedef stacknode * nodeptr;
nodeptr top;


class Stack 
{
public:

  Stack()
  {
    top = NULL;
  }

  ~Stack()
  {
    nodeptr p, n;
    p = top;
    while (p != NULL)
      {
        n = p;
        p = p -> next;
        delete n;
      }
  }
  
  void push(op x)
  {
    nodeptr n;
    n = new stacknode;
    n->info = x;
    if (top == NULL)
      {
        top = n;
        n->next = NULL;
      }
    else
      {
        nodeptr tmp = top;
        n->next = tmp;
        top = n;
      }
  }

  void pop()
  {
    nodeptr curr;
    if (top == NULL)
      {
        cout << "Stack empty." << endl;
        return;
      }
    else
      {
        curr = top;
        top = top->next;
        delete curr;
      }
  }


private:

};

class list
{

struct node
{
  int info;
  node * next;
};

  typedef node * nodeptr;
  nodeptr head;

public:

  list()
  {
    head = NULL;
  }

  ~list()
  {
    nodeptr p, n;
    p = head;
    while (p != NULL)
      {
        n = p;
        p = p -> next;
        delete n;
      }
  }


  void AddNode(int x)
  {
    nodeptr n, prev, curr;
    n = new node;
    n->info = x;
    if (head == NULL)
      {
        head = n;
        n->next = NULL;
      }
    else
      {
        curr = head;
        while (curr != NULL)
          {
            prev = curr;
            curr = curr->next;
          }
        if (curr == head)
          {
            n->next = head;
            head = n;
          }
        else
          {
            prev->next = n;
            n->next = curr;
          }
      }
  }

  void PrintNodes()
  {

    nodeptr p = head;
    if (p = NULL)
      {
        cout << "List empty. Exiting." << endl;
        return;
      }
    else
      {
        while (p != NULL)
          {
            cout << p->info << endl;
            p = p->next;
          }
      }
  }
  
  int deletelast()
  {
    nodeptr curr, prev;
    curr = head;
    if (head == NULL)
      {
        cout << "List empty." << endl;
        return 0;
      }
    else
      {
        while (curr != NULL)
          {
            prev = curr;
            curr = curr->next;
          }
        prev->next = curr->next;
        delete curr;
      }
  }
private:
};
  
        
int main (int argc, char **argv)
{
  Stack Stack1;
  list List1;
  int x;

  cout << "How many items in the test list?" << endl;
  cin >> x;
  cout << "Testing..." << endl;
  for (int i = 1; i<x; i++)
    List1.AddNode(i);
  List1.PrintNodes();
  return 0;
}
