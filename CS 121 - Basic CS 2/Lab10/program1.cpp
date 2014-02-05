/* Colby Rush      CS 121-2
   Lab 10          4/7/2011 */

#include <iostream>
using namespace std;

bool above (int a, int t);
bool below (int a, int t);
int filter(int A[], int &nA, int t, bool (*fp)(int,int));

int main(int argc, char **argv)
{
  char WhichOne;  // filter above or below
  int t;  // threshold
  int A[] = {1,2,3,4,5,6,7,8,9,10};
  int nA = 10; // elements in array

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

  cout << "New Array: " << endl;

  if (WhichOne == 'a')
    filter(A,nA,t,&above);
  else if (WhichOne == 'b')
    filter(A,nA,t,&below);

return 0;
}

bool above (int a, int t)
{
  return (a > t);
}

bool below (int a, int t)
{
  return (a < t);
}

int filter(int A[], int &nA, int t, bool (*fp)(int,int))
{
  for (int i = 0; i < nA; i++)
    {
      if (fp(A[i], t) == true)
        {
          cout << A[i] << " ";
        }
    }
  cout << endl;
}





