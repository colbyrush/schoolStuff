/*
 * Paul Nathan
 * main.cpp
 * Serves as unit tests for a boundedqueue class.
 *
 * Written for CS121 labs.
 * version 1.0, March 2009
 * (C)2009, UI.
 */ 

#include <iostream> 
#include "boundedqueue.h" 
using namespace std;

//Reviews different errors possible.
//Returns the number of errors found.
//Reference passed is number of errors possible.
int testCreationErrors(int &possible);
int testGetPutSingleData(int &possible);
int testGetPutMultipleData(int &possible);
int testReset(int &possible);
int testOverUnderflow(int &possible);
void final(int);
//-----------------------------------------
int main()
{
    int errorCount, possible;
    int totalErrors = 0;
    char c;
    
    errorCount = testCreationErrors(possible);
    totalErrors += errorCount;
    cout << errorCount << " out of " << possible << " errors possible on creation\n";

    
    errorCount = testGetPutSingleData(possible);
    totalErrors += errorCount;
    cout << errorCount << " out of " << possible << " errors possible on putting and getting a single datapoint\n";


    errorCount = testGetPutMultipleData(possible);
    totalErrors += errorCount;
    cout << errorCount << " out of " << possible << " errors possible getting and putting multiple data\n";

    
    errorCount = testReset(possible);
    totalErrors += errorCount;
    cout << errorCount << " out of " << possible << " errors possible on resetting the boundedqueue\n";

    errorCount = testOverUnderflow(possible);
    totalErrors += errorCount;
    cout << errorCount << " out of " << possible << " errors possible on overflowing/underflowing the boundedqueue\n";


    final(totalErrors);

    
    return 0;
}


int testCreationErrors(int &possible)
{
    int maxSize, numFreeSpots, errorCount;
    boundedQueue bq;
    
    errorCount = 0;

    //This is hardcoded to the number of tests in this
    //function
    possible = 4;
    
    maxSize = bq.getMaxSize();
    if(maxSize == 0)
      {
	errorCount++;
	cerr << "Maximum size is 0!!\n";
    }
    
    numFreeSpots = bq.freeSpots();
    if(numFreeSpots == 0)
    {
	errorCount++;
	cerr << "No free spots on creation!\n";
    }
    
    if(bq.usedSpots() > 0)
    {
	errorCount++;
	cerr << "Spots used on creation!?\n";
    }
    
    if(bq.freeSpots() != bq.getMaxSize())
    {
	errorCount++;
	cerr << "ErrorCount - max size must equal free spots on creation\n";
    }

    return errorCount;
}



int testGetPutSingleData(int &possible)
{
    int errorCount = 0;
    boundedQueue bq;
    char c;
    
    //hardcoded to this function.
    possible = 5;

    //45 has no particular value, it's just some number used to test.
    if( ! bq.put(45))
    {
	errorCount++;
	cerr << "Failure to put\n";
    }

    if(bq.freeSpots() != bq.getMaxSize() - 1)
    {
	errorCount++;
	cerr << "Number of spots free is incorrect\n";

    }
    
    if(bq.usedSpots() != 1)
    {
	errorCount++;
	cerr << "1 element used, but reported in error\n";
    }
    
    if( ! bq.get(c))
    {
	errorCount++;
	cerr << "Get errored, when it should not have\n";
    }
    
    if(c != 45)
    {
	errorCount++;
	cerr << "Failure to get correctly\n";
    }
    
    return errorCount;
}

int testGetPutMultipleData(int &possible)
{
    int errorCount = 0;
    boundedQueue bq;
    //flags
    bool errorAdding = false, errorRemoving = false, errorValid = false;
    char temp;
    
    possible = 6;

    //The next 3 tests determine if the account is valid
    if( ! (bq.put(1) && bq.put(2) && bq.put(3)))
    {
	errorCount++;
	cerr << "Putting 3 elements in failed\n";
    }
    
    if(bq.freeSpots() != bq.getMaxSize() - 3)
    {
	errorCount++;
	cerr << "Accounting of the free spots is in error\n";
    }
    if(bq.usedSpots() != 3)
    {
	errorCount++;
	cerr << "3 elements have been inserted, report in error\n";
    }

    //manually reset the queue
    bq.get(temp);
    bq.get(temp);
    bq.get(temp);
    
    //This pair of loops verifies correct insertion/deletion.
    for(int i = 0; i < bq.getMaxSize() - 1; i++)
    {
	if( ! bq.put(i))
	{
	    cerr << "Error adding an element while queue not full\n";
	    errorAdding = true;
	}
    }
    
    if(errorAdding)
	errorCount++;
    
    for(int i = 0; i < bq.usedSpots(); i++)
    {
	if( ! bq.get(temp))
	{
	    cerr << "Error removing an element that should be valid\n";
	    errorRemoving = true;
	}
	if(temp != i)
	{
	    cerr << "element " << temp << " removed does not match element inserted " << i << "\n";
	    errorValid = true;
	}
    }
    
    if(errorRemoving)
	errorCount++;
    
    if(errorValid)
	errorCount++;
    
    return errorCount;
}

void final(int f)
{
    if(f)
    {
	cout << "You have " << f << " left\n";
    }
    else
    {
	cout << "You have passed this set of tests!\n";
	cout << "\e[31;40mCONFETTI!\e[0m\n";
    }

}

int testReset(int &possible)
{
    boundedQueue bq;
    int errorCount = 0;
    
    bq.reset();
    if(! bq.isEmpty())
    {
	errorCount++;
	cerr << "Queue should be empty on reset\n";
    }

    possible = 1;
    
    return errorCount;
}

int testOverUnderflow(int &possible)
{
    int errorCount = 0;
    char testChar;
    bool foundErrorOnPut = false;
    boundedQueue bq;
    
    //Test the queue's ability to detect overload
    for(int i = 0; i < bq.getMaxSize(); i++)
    {
	if( ! bq.put(255))
	{
	    cerr << "Failed on putting a legit item in\n";
	    foundErrorOnPut = true;
	}
    }

    if(foundErrorOnPut)
	errorCount++;
    
    if(bq.put(1))
    {
	errorCount++;
	cerr << "Failed to create an error on overflow!\n";
    }
    
    
    bq.reset();
    if(bq.get(testChar))
    {
	errorCount++;
	cerr << "Underflow not reported\n";
    }

    possible = 3;
    
    
    return errorCount;
}
