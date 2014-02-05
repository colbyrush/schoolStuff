/* Hash.cpp
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *     Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include "hash.h"

using namespace std;


const int HASH_TABLE_SIZE = 117;
static NListPtr hashTable[HASH_TABLE_SIZE];

/*  Hash
 *  Generate hash value for string s
 */

unsigned Hash( nList *movie )
{
    unsigned hashVal;
    
    for( hashVal = 0 ; *movie.title != '\0' ; movie.title++ )
        hashVal = *s + 31 * hashVal;
        
    return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
 *  Look for s in hashTable
 */

NListPtr Lookup( nList *movie )
{
    NListPtr np;
    
    for( np = hashTable[Hash(movie.title)] ; np != NULL ; np = np->next )
    {
        if( strcmp(movie.title, np->name) == 0 )
            return np;    //  found
    }
    
    return NULL;          //  not found
}

/*  Insert
 *  Put (name, defn) in hash table
 */
 
NListPtr Insert( nList movie )
{
    unsigned hashVal;
    NListPtr np;
    
    if( (np = Lookup(movie)) == NULL )  // not found
    {
        np = (NListPtr) malloc(sizeof(*np));
        if( np == NULL || (np->name = strdup(movie.title)) == NULL )
            return NULL;
        hashVal = Hash(movie);
        np->next = hashTable[hashVal];
        hashTable[hashVal] = np;
    }
    else
    {      //  remove previous definition
        free( (void *)np->movie );
    }
    
    if( (np->movie.title = strdup(movie.title)) == NULL )
        return NULL;
    
    return np;
}


/*  PrintHashTable
 *  Print the hash table contents
 */

void PrintHashTable()
{
    NListPtr np;
    int count;
    int big = 0;
    int small = 10000;
    int bignum = 0;
    int smallnum = 0;
    cout << "Hash table contents:" << endl;
    cout << "--------------------\n" << endl;

    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
      {
        np = hashTable[i];
        count = 0;
        while( np != NULL )
          {
            cout << setw(3) << i << ":    ";
            cout << np->movie.title;
            cout << endl;
            np = np->next;
            count++;
          }
        if (count > big)
          {
            big = count;
            bignum = i;
          }
        if (count < small)
          {
            small = count;
            smallnum = i;
          }
        cout << "Amount in bucket #" << i << " : " << count << endl;
      }
        cout << "Maximum bucket is #" << bignum << " and it's size is: " << big << endl;
        cout << "Minimum bucket is #" << smallnum << " and it's size is: " << small << endl;
}
