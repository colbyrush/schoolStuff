#include <stdio.h>

void print (int array[10][10], int *, char sarray[10][10], int, int);
void calc(int array[10][10], char sarray[10][10], int *);
void sym (int array[10][10], char sarray[10][10]);
void addnums(int array[10][10], int);

void print (int array[10][10], int *D, char sarray[10][10], int x, int days)
{
  int i, q, d, p;
  
  for (i = 0; i < 10; i++)
    for (q = 0; q < 10; q++)
      sarray[i][q] = '0';

  for (p = 1; p <= x; p++)
    {
      printf("Solution: %d\n", p);
      for (i = 0; i < 15; i++)
        printf("%d ", D[i]);
      printf("\nGeneration: 0\n");
      
      calc(array, sarray, D);
      
      for (i = 0; i < 10; i++)
        {
          for (q = 0; q < 10; q++)
            {
              printf("%c ", sarray[i][q]);
            }
          printf("\n");
        }
      
      for (d = 1; d < days; d++)
        {
          printf("Generation: %d\n", d);
          calc(array, sarray, D);
          
          for (i = 0; i < 10; i++)
            {
              for (q = 0; q < 10; q++)
                {
                  printf("%c ", sarray[i][q]);
                }
              printf("\n");
            }
        }
    }
}  

void calc (int array[10][10], char sarray[10][10], int *D)
{
  int i, q, b;
  int solution = 0;

  for (i = 0; i < 15; i++)
    solution += D[i];
  if (solution = -3)
    addnums(array, -3);
  else if (solution = -2)
    addnums(array, -2);
  else if (solution = -1)
    addnums(array, -1);
  else if (solution = 0)
    addnums(array, 0);
  else if (solution = 1)
    addnums(array, 1);
  else if (solution = 2)
    addnums(array, 2);
  else if (solution = 3)
    addnums(array, 3);
  
  sym(array, sarray);
}

void addnums(int array[10][10], int x)
{
  int i, q;
  int b = 0;
  
  for (i = 0; i < 10; i++)
    for (q = 0; q < 10; q++)
      {
        if (array[i][q] = 0)
          b = 1;
        else if (array[i][q] >= 1)
          {
            if (i == 0 || q == 0)
              {
                array[i+1][q] += x;
                array[i][q+1] += x;
              }
            else if (i == 10 || q == 10)
              {
                array[i-1][q] += x;
                array[i][q-1] += x;
              }
            else
              {
                array[i-1][q] += x;
                array[i][q-1] += x;
                array[i+1][q] += x;
                array[i][q+1] += x;
              }
          }
      }
}


void sym(int array[10][10], char sarray[10][10])
{
  int i, q;
  for (i = 0; i < 10; i++)
    for (q = 0; q < 10; q++)
      {
        if (array[i][q] <= 0)
          {
            array[i][q] = 0;
            sarray[i][q] = '0';
          }
        else if (array[i][q] = 1)
          {
            array[i][q] = 1;
            sarray[i][q] = '!';
          }
        else if (array[i][q] = 2)
          {
            array[i][q] = 2;
            sarray[i][q] = 'X';
          }
        else
          {
            array[i][q] = 3;
            sarray[i][q] = '#';
          }
      }
}
