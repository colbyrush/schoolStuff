#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  typedef struct entry 
  {
    char *name;
    int number;
    struct entry *next;
  } Entry;

  Entry *names, *here, *first;
  struct entry *temp;
  if ((names = (Entry *)(malloc(4 * sizeof(Entry))))==NULL) exit(1);

  here = names;
  if ((here->name = malloc(strlen("Ralph")+1)) != NULL)
    {
      strcpy(here->name, "Ralph");
      here -> number = 2;
    }

  if ((names[1].name = malloc(strlen("John")+1)) != NULL)
    {
      strcpy(names[1].name,"John");
      names[1].number = 3;
    }

  here = names + 2;

  if ((here->name = malloc(strlen("Steven")+1)) != NULL)
    {
      strcpy(names[2].name, "Steven");
      here->number = 1;
    }

  if ((names[3].name = malloc(strlen("Sam")+1)) != NULL)
    {
      strcpy(names[3].name,"Sam");
      names[3].number = 4;
    }

  first = names+2;
  (names+2)->next = &names[0];
  names->next = names+1;
  names[1].next = names+3;
  here = names+3;
  names[3].next = NULL;
  for (temp = here; temp > here-4; temp -= 1)
    printf("%s: %d\n", temp->name, temp->number);
  printf("\n");
  for(temp = first; temp; temp = temp->next)
    printf("%s: %d\n", temp->name, temp->number);
}
     
      
