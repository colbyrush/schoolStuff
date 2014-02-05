/* array.cpp

   Array manipulation functions.

   Bruce M. Bolden
   September 7, 2007

   http://www.cs.uidaho.edu/~bruceb/
   ---------------------------------------------------------
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

#include "array.h"


/*  ReadArray -- Reads array elements.
 */
int ReadArray( ifstream& fIn, int A[], const int nMax )
{
    int i = 0;
    int nTmp;

    while( (i < nMax) && (fIn >> nTmp) )
    {
        A[i] = nTmp;
        ++i;
    }

    return i;    //  number of elements stored
}


/*  WriteArray -- Writes one element to a line.
 */
void WriteArray( ofstream &fOut, const int A[], const int nMax )
{
    for( int i = 0 ; i < nMax ; i++ )
        fOut << A[i] << endl;
}


/*  InitializeArray

    Initializes array elements to a programmer defined value.
 */
void InitializeArray( int A[], const int nMax, const int iVal )
{
    for( int i = 0 ; i < nMax ; i++ )
        A[i] = iVal;
}


/*  MinArray

    Finds the minimum value in an array. 
 */
int MinArray( const int A[], const int nMax )
{
    int  min = A[0];

    for( int i = 1 ; i < nMax ; i++ )
    {
        if( A[i] < min )
            min = A[i];
    }

    return  min;
}

int MaxArray (int A[],int nMax)
{
  int max = A[0];
  for (int i = 1; i < nMax; i++)
    {
      if (A[i] > max)
        max = A[i];
    }
  return max;
}

int MedianArray ( int A[], int nMax)
{
  sort (A, A+nMax);
  int mid = nMax/2;
  int median = A[mid];
  return median;
}

double StandDiv (int A[], int nMax)
{
  double adding = 0;
  double sig = 0;
  for (int i = 0; i < nMax; i++)
    adding = adding + A[i];
 double mean = adding / nMax;
 for (int q = 0; q < nMax; q++)
   sig = sig + ((A[q] - mean)*(A[q] - mean));
 double almost = (sig)/(nMax - 1);
 double stand = sqrt(almost);
 return stand;
}


//  ------------------------------------------------------------------


/*  SearchArray 
 
    Searches for the value, keyVal, in an array. 
    If successful, the index is returned.
    If unsuccessful, -1 is returned.
 */
int SearchArray( const int A[], const int nMax, const int keyVal )
{
    for( int i = 0 ; i < nMax ; i++ )
    {
        if( A[i] == keyVal )
            return i;
    }

    return  -1;
}
