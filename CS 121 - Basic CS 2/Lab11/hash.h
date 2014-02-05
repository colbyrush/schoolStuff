/*  hash.h
 */

#ifndef HASH_H
#define HASH_H

struct nList     /*  table entry:  */
{
  const char *name;          /*  defined name         */
  const char *defn;          /*  replacement text     */
  struct nList *next;        /*  next entry in chain  */
};

typedef struct nList *NListPtr;

unsigned Hash( const char *s );
NListPtr Lookup( const char *s );
NListPtr Insert( const char *name, const char *defn );
void PrintHashTable();

#endif  /*  HASH_H  */
