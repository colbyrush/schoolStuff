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
  char str[100];
  char file[100];
  char * output;
  ssize_t nr;
  int op, i;
  int x;

  if (argc == 1)
    {
      argv[1] = " ";
      argv[2] = NULL;
    }

  fp = fopen (argv[1], "r");
  if (fp == NULL)
    {
      printf("Please enter a valid filename to read: ");
      scanf ("%s", file);
      fp = fopen (file, "r");
    }

  output = argv[2];
  if (output == NULL)
    {
      printf("Please enter a valid filename to write to: ");
      scanf ("%s",output);
      op = open (output, O_CREAT | O_WRONLY, 0777);
    }
  else
    op = open (output, O_CREAT | O_WRONLY, 0777);
 
  fgets(str, 100, fp);
  while (!feof(fp))
    {
      x = strlen(str);
      nr = write(op, &x, sizeof(int));
      nr = write (op, str, sizeof(char)*x);     
      if (nr == -1)
        {
          perror ("write");
          exit -1;
        }
      strip (str);
      fgets(str, 100, fp);
    }

  fclose(fp);
  close(op);
}
