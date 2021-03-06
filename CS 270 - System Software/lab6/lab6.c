#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void strip(char *s)
{
  int len;
  len = strlen(s);
  if(s[len - 2] == '\r')
    s[len -2] = '\0';

  else if(s[len -1] == '\n')
    s[len -1] = '\0';
}// end strip

void clean(int argc, char **argv)
{
  int x;
  for (x = 0; x < argc; x++)
    strip(argv[x]);
}

void printargs(int argc, char **argv)
{
  int x;
  for (x = 0; x < argc; x++)
    printf("%s\n", argv[x]);
}

int makeargs(char *s, char *** argv)
{
  int i;
  char * tmp;
  int count = 1;
  for (i = 0; i < strlen(s); i++)
    {
    if (s[i] == ' ')
      count++;
    else if (s[i] == 'q')
      return -1;
    }
  
  if (count <= 0)
    return -1;
  else
    {
      *argv = (char**)malloc(count *sizeof(char*));
      tmp = strtok(s," ");
      
      for (i = 0; i < count; i++)
        {  
          (*argv)[i] = (char*)malloc((strlen(tmp)+1)*sizeof(char));
          strcpy((*argv)[i],tmp);
          tmp = strtok(NULL," ");
        }
      
      return count;
    }
}// end makeArgs


int main()
{
  char **argv = NULL, s[100];
  int argc;
  int x = 1;

  while (x == 1)
    {
      printf("Please enter a string to analyze. Enter q to quit. ");
      gets (s);
      argc = makeargs(s, &argv);
      if(argc != -1)
        {
          printf("There are %d tokens.\nThe tokens are:\n", argc);
          printargs(argc, argv);
        }// end if      
      else
        return -1;
      clean(argc, argv);
      argv = NULL;
    }
}
// end main
