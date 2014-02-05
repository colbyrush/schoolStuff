/*  hash.h
 */

#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

struct nList     /*  table entry:  */
{
  const char *name;          /*  defined name         */
  string title;
  string year;
  string actor[50];
  const char *defn;          /*  replacement text     */
  struct nList *next;        /*  next entry in chain  */
};

typedef struct nList *NListPtr;

unsigned Hash( const char *s );
NListPtr Lookup( const char *s );
NListPtr Insert( const char *name, const char *defn );
void PrintHashTable();

#endif  /*  HASH_H  */
