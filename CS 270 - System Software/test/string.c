#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  int i, x;
  FILE * fin = fopen("input.txt","r");
  char strings[5][41], word[41];

  for(i = 0; i < 5; i++)
    {
      fgets(strings[i], 42, fin);
      // strcpy(strings[i],word);
      printf("%d: %s\n", i, strings[i]);
      //      memset(word,'0',strlen(word));
    }

}
