/*  mergeSort.cpp
 *
 *  Bruce M. Bolden
 *  November 18, 1998
 */

#include <iostream>
#include <fstream>
#include <string>

typedef int aType;   //  array type

using namespace std;

const int MAX_ARRAY = 10000;

    //  prototypes
void  Mergesort( aType a[], int first, int last );
void  Merge( aType a[], 
             int firstLeft,  int lastLeft, 
             int firstRight, int lastRight );

void  Swap( aType &v1, aType &v2 );
void  PrintArray( aType A[], int nElements );

int swapnum = 0;
int mergesortnum = 0;
int mergenum = 0;

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
  
  Mergesort( testArray, 0, nA-1 );
  
  cout << "Statistics: " << endl;
  cout << "Swap #: " << swapnum << endl;
  cout << "Mergesort #: " << mergesortnum << endl;
  cout << "Merge #: " << mergenum << endl;
}


/*  Mergesort:  Do a mergesort on array a.  
 *  Note:  This is a recursive routine.
 */

void Mergesort( aType a[], int first, int last ) 
{
    int  middle;
    mergesortnum++;
    if( first < last ) {
        middle = (first + last)/2;
        Mergesort( a, first, middle);
        Mergesort( a, middle+1, last );
        Merge( a, first, middle, middle+1, last );
    }
}

/*  Merge:  Merge two segments of an array together.  
 */

void Merge( aType a[], 
            int firstLeft,  int lastLeft, 
            int firstRight, int lastRight ) 
{
  mergenum++;
    aType tempArray[MAX_ARRAY];
    int  index = firstLeft;
    int  firstSave = firstLeft;

        //  Merge segments (array subsets)
    while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
    {
        if( a[firstLeft] < a[firstRight] )
        {
           tempArray[index] = a[firstLeft];
           firstLeft++;
        }
        else
        {
           tempArray[index] = a[firstRight];
           firstRight++;
        }
        index++;
    }
        //  Copy remainder of left array into tempArray
    while( firstLeft <= lastLeft )
    {
        tempArray[index] = a[firstLeft];
        firstLeft++;
        index++;
    }

        //  Copy remainder of right array into tempArray
    while( firstRight <= lastRight )
    {
        tempArray[index] = a[firstRight];
        firstRight++;
        index++;
    }

        //  Copy back into original array
    for( index = firstSave ; index <= lastRight ; index++ )
        a[index] = tempArray[index];
}


/*  Swap:  Swap two items (by reference).
 */
void  Swap( aType &v1, aType &v2 )
{
    aType  tmpVal;
    int swapnum;
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

