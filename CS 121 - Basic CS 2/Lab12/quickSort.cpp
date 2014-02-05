/*  quickSort.cpp
 *
 *  Bruce M. Bolden
 *  November 18, 1998
 */

#include <iostream>
#include <fstream>
#include <string>

typedef int aType;

using namespace std;

aType MAX_ARRAY = 10000;

    //  prototypes
void Quicksort( aType a[], int first, int last );
int Pivot( aType a[], int first, int last );

void  Swap( aType &v1, aType &v2 );
void  PrintArray( aType A[], int nElements );

int quicknum = 0;
int pivotnum = 0;
int swapnum = 0;

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

  Quicksort( testArray, 0, nA-1 );

  cout << "Statistics:" << endl;
  cout << "Quicksort: " << quicknum << endl;
  cout << "Pivots: " << pivotnum << endl;
  cout << "Swaps: " << swapnum << endl;

}

/*  Quicksort:  Sort an array a, using the quicksort
 *  algorithm.
 */

void Quicksort( aType a[], int first, int last ) 
{
  quicknum++;
  int pivot;
  
  if( first < last ) {
    pivot = Pivot( a, first, last );
    Quicksort( a, first, pivot-1 );
    Quicksort( a, pivot+1, last );
  }
}


/*  Pivot:  Find and return the index of pivot element.
 */

int Pivot( aType a[], int first, int last ) 
{
  pivotnum++;
  int  p = first;
  aType pivot = a[first];
  
  for( int i = first+1 ; i <= last ; i++ ) {
    if( a[i] <= pivot ) {
      p++;
      Swap( a[i], a[p] );
    }
  }
  
  Swap( a[p], a[first] );
  
  return p;
}


/*  Swap:  Swap two item (by reference).
 */

void  Swap( aType &v1, aType &v2 )
{
  swapnum++;
  aType  tmpVal;
  
  tmpVal = v1;
  v1 = v2;
  v2 = tmpVal;
}


/*  PrintArray:  Print contents of an array.
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

