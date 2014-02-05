#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void strip(char *s)
{
  int len;
  len = strlen(s);
  if(s[len - 2] == '\r')
    s[len -2] = '\0';

  else if(s[len -1] == '\n')
    s[len -1] = '\0';
}

int main (int argc, char **argv)
{
  FILE * fp;
  int op;
  char * open;

  if (argc == 1)
    {
      argv[1] = " ";
      argv[2] = NULL;
    }

  op = argv[1];
  if (op == -1)
    {
      printf("Please enter a valid filename to read from: ");
      scanf ("%s", open);
      op = open (open, O_CREAT | O_WRONLY, 0777);
      if (op == -1)
        {
          printf ("Invalid file. Exiting.");
          exit -1;
        }
    }

  fp = argv[2];
  if (fp == NULL)
    {
      

  fclose(fp);
  close(op);
}
