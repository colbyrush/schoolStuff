/*  selSort.cpp
 *
 *  Selection Sort test program.
 *
 *  Bruce M. Bolden
 *  November 16, 1998
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define  aType  int

aType MAX_ARRAY = 10;

   //  prototypes
void  SelectionSort( aType A[], int nElements );
int IndexOfSmallest( aType A[], int iStart, int iEnd );

void  PrintArray( aType A[], int nElements );

int selectionnum = 0;
int indexnum = 0;

int main()
{
  string filename;
  fstream file;
  aType testArray[MAX_ARRAY];
  int i = 0;
  cout << "Enter a filename to sort: " << endl;
  cin >> filename;
  file.open (filename.c_str());
  while (!file.eof())
    {
      file >> testArray[i];
      i++;
    }
  int nA = sizeof(testArray)/sizeof(aType);

  SelectionSort( testArray, nA );

  cout << "Statistics:" << endl;
  cout << "Selection: " << selectionnum << endl;
  cout << "Index(i?): " << indexnum << endl;
}


/*  SelectionSort:  Sort and array, A, using a selection
 *  sort algorithm.
 */

void  SelectionSort( aType A[], int nElements )
{
  selectionnum++;
  int iSmallest;
  aType  tmp;
  
  for( int i = 0 ; i < nElements ; i++ )
    {
      iSmallest = IndexOfSmallest( A, i, nElements-1 );
      //  swap
      if( iSmallest > i )
        {
          tmp = A[i];
          A[i] = A[iSmallest];
          A[iSmallest] = tmp;
        }
    }
}


/*  IndexOfSmallest:  Find index of smallest value.
 */

int IndexOfSmallest( aType A[], int iStart, int iEnd )
{
  indexnum++;
  int    index = -1;
  aType  aMin = A[iStart];
  
  for( int i = iStart ; i <= iEnd ; i++ )
    {
      if( A[i] < aMin )
        {
          aMin = A[i];
          index = i;
        }
    }
    
  return index;
}


/*  Print contents of an array.
 */

void  PrintArray( aType A[], int nElements )
{
  cout << "[ ";
  
  for( int i = 0 ; i < nElements ; i++ )
    {
      cout << A[i] ;
      if( i < nElements-1 )
        cout << ", ";
    }
  
  cout << " ] " << endl; 
}

