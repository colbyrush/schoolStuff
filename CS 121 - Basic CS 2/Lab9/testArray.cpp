/* testArray.cpp
 
  Test array manipulation functions.  All array manipulation
  functions are defined in an external library.
 
  Bruce M. Bolden
  September 7, 2007
 
  http://www.cs.uidaho.edu/~bruceb/
  ---------------------------------------------------------
 */
 
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "array.h"

int main()
{
    const int MAX_ELEMENTS = 10;
    int iArray[MAX_ELEMENTS];
    
    int  n;               //  number of elements in the array
    int index;

        //  Open Input/Output file streams (no error checking!)
    ifstream fIn( "array.dat", ios::in );
    ofstream fOut( "array.out", ios::out );
    
    n = ReadArray( fIn, iArray, MAX_ELEMENTS );
    fIn.close();
    WriteArray( fOut, iArray, n );

    fOut << "\n\nMinimum value" << endl;
    int min = MinArray( iArray, n );
    fOut << "\tMinimum: " << min << endl;
    
        //  Test array search function
    fOut << "\nSearching for 5" << endl;
    index = SearchArray( iArray, n, 5 );
    fOut << "\tindex: " << index << endl;
    
    fOut << "\nSearching for 25" << endl;
    index = SearchArray( iArray, n, 25 );
    fOut << "\tindex: " << index << endl;

    double ma = MaxArray(iArray, 10);
    double medi = MedianArray(iArray, 10);
    double StandDi = StandDiv(iArray, 10);
    
        //  Test array initialization function
    InitializeArray( iArray, MAX_ELEMENTS, 5 );
    WriteArray( fOut, iArray, n );

    cout << "Max value of array is: " << ma << endl;
    cout << "Median value of array is: " << medi << endl;
    cout << "Standard deviation of array is: " << StandDi << endl;

    fOut.close();
    
    return 0;
}
