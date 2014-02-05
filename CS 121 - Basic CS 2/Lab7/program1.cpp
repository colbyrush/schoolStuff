/* Colby Rush      CS 121-2
   Lab 7           3/10/2011 */

#include <iostream>
#include "program1.h"

using namespace std;

int* FilterAbove(int a[], int &nA, int t);
int* FilterBelow(int a[], int &nA, int t);

int main(int argc, char **argv)
{
  char WhichPart; // array or list
  char WhichOne;  // filter above or below
  int t;  // threshold
  int A[] = {1,2,3,4,5,6,7,8,9,10};
  int nA = 10; // elements in array

  LinkedList list1;

  for (int q = 1; q < 10; q++)
    list1.AddNode(q);

  cout << "Array (a) or linked list (l)?";
  cin >> WhichPart;

  if (WhichPart == 'a')
    {
      cout << "Current array: " << endl;
      for (int d = 0; d < nA; d++)
        {
          cout << A[d] << " ";
        }
      cout << endl;
      cout << "Enter threshold value: " << endl;
      cin >> t;
      cout << "Filter above (a), or below (b)?" << endl;
      cin >> WhichOne;
      
      if (WhichOne == 'a')
        FilterAbove(A,nA,t);
      else if (WhichOne == 'b')
        FilterBelow(A,nA,t);
      
      cout << "New array: " << endl;
      for(int x = 0; x < nA; x++)
        cout << A[x] << " ";
      cout << endl;
    }
  else if (WhichPart == 'l')
    {
      cout << "Current list: " << endl;
      list1.ListNodes();
      cout << endl << "Enter threshold value: " << endl;
      cin >> t;
      cout << "Filter above (a), or below (b)?" << endl;
      cin >> WhichOne;
      if (WhichOne == 'a')
        {
          for (int y = 0; y < t; y++)
            list1.DeleteNode(y);
        }
      else if (WhichOne == 'b')
        {
          for (int j = 9; j > t; j--)
            list1.DeleteNode(j);
        }
      cout << "New list: " << endl;
      list1.ListNodes();
    }
  return 0;
}

int* FilterAbove(int A[], int &nA, int t)
{
  
  int c = 0;
  int aTmp[nA];
  for (int i = 0; i < nA; i++)
    {
      if (A[i] >= t)       // If number is greater than filter, put it in a temp array
        {
          aTmp[c] = A[i];
          c++;            // Counter to start aTmp at 0 and then make sure its as big as filtered
        }
    }

  for (int q = 0; q < c; q++) // Transfer aTmp into A
    {
      A[q] = aTmp[q];
    }

  nA = c;

  return A;

}

int* FilterBelow(int A[], int &nA, int t)
{

  int c = 0;
  int aTmp[nA];
  for (int i = 0; i < nA; i++)
    {
      if (A[i] <= t)       // If number is greater than filter, put it in a temp array
        {
          aTmp[c] = A[i];
          c++;            // Counter to start aTmp at 0 and then make sure its as big as filtered
        }
    }

  for (int q = 0; q < c; q++) // Transfer aTmp into A
    {
      A[q] = aTmp[q];
    }

  nA = c;

  return A;

}
