/* Colby Rush        CS 270
   10/3/11           Asteroid */

#include <stdio.h>
#include "ast.h"

int main (int argc, char **argv)
{
  int i, q, x, array[10][10], D[15], solutions, days;
  FILE *fp;
  char input[1];
  char sarray[10][10];

  fp=fopen("data1.txt", "r");

  if (fp == NULL)
    {
      fprintf(stderr, "Not a valid file :(\n");
      return 0;
    }
  while (!feof(fp))
    {
      fscanf(fp,"%d",solutions);
      for (x = 1; x <= solutions; x++)
        {
          fscanf(fp,"%d",days);
          for (i = 0; i < 15; i++)
              scanf ("%d", &D[i]);
          for (q = 0; q < 10; q++)
            for (i = 0; i < 10; i++)
              scanf("%d", &array[i][q]);
          print(array, D, sarray, x, days); 
        }
    }
  return 0;
}
