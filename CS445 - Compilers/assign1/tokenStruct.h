#ifndef TOKENSTRUCT_H
#define        TOKENSTRUCT_H

struct TokenData
{
  int tokenClass;
  int lineno;
  char* tokenstr;
  char* idvalue;
  int numvalue;
  char* keyvalue;
};


#endif        /* TOKENSTRUCT_H */
