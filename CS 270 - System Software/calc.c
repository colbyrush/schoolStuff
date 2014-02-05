/* Colby Rush       CS 270
   9/22/11          Calc program */

#include <stdio.h>
#include "calc.h"

int main (int argc, char **argv)
{

  int i, q;
  FILE *fp;

  /* first array of name and score should be the same to keep track of students */
  
  fp=fopen("scores.txt", "r");
  if (fp == NULL)
    {
      fprintf(stderr, "Can't open input file :'(\n");
      return 0;
    }
  
  int n = 0;

  while (!feof(fp))        /* file read loop */
    {
      fgets(student[n].name, 50, fp);
      for (i = 0; i < 13; i++)
        {
          fscanf(fp, "%d", &student[n].score[i]);
        }
      n++;
    }
  
  fclose(fp);

  for (q = 0; q < n; q++) /* score print loop */
    {
      calc(student, q);
    }
  return 0;
}
