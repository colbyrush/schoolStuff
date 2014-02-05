/* TestHash.cpp
 *   Test the Hash table code.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int main()
{  

  string line;
  fstream file;

  
  file.open("dict4.txt");
  
  while (!file.eof())
    {
      file >> line;
      Insert(line.c_str(), line.c_str());
    }

  //  Put a few values in the table...
  (void)Insert( "One",  "1" );
  (void)Insert( "One",  "11" );
  (void)Insert( "Two",  "2" );
  (void)Insert( "Four", "4" );
  (void)Insert( "Five", "5" );
  (void)Insert( "Six",  "6" );
  (void)Insert( "Nine", "9" );
  (void)Insert( "Yes", "1" );
  (void)Insert( "YES", "1" );
  (void)Insert( "No",  "0" );
  (void)Insert( "NO",  "0" );
  
  PrintHashTable();

  if (Lookup ("abloom") )
    cout << "Yep, it's there." << endl;
  if (Lookup ("electrogilt") )
    cout << "Yeah, I found it." << endl;
  if (Lookup ("magiristic") )
    cout << "Suprisingly, words are in the dictionary." << endl;
  if (Lookup ("politzeritzation") )
    cout << "You can look for a better word than that." << endl;
  if (Lookup ("tormentilla") )
    cout << "You're done. Get out. Leave. Never come back." << endl;
  
  return EXIT_SUCCESS;
}


 
