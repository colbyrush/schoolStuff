/* Lab #3       Colby Rush
   CS 121-02    2/3/2011

 program1.c */

#include <stdio.h>
#include <math.h>

void ShowHeader();

double min();
double max();
double average();


int main(int argc, char **argv)
{
  int count = 0; // counter
  int i = 0; // array number
  double x; // min or max
  double avg; // average
  char filename[256]; // makes sure the filename doesn't overflow
  FILE *fp = NULL; // file pointer
  double val;
  double array[100]; // stores input
  count *cp = NULL; // counter



  printf("Please enter a filename: ");
  scanf("%s", filename); // input of filename

  printf("Your filename is %s\n", filename);

  fp = fopen(filename, "r"); // assigns file to file pointer

  if (fp == NULL) // makes sure faulty filename works
  {
  printf("Could not open the file!\n");
  return 1;
  }

  while (!feof(fp)) // reads values into val
  {
  fscanf(fp, "%f", &val);
  &val = array[i];  // collects the values into the array
  i++;
  count++;
  }
 
  double min(array, cp);
  double max(array, cp);
  double average(array, cp);

  printf("Your min is: ", min);
  printf("Your max is: ", max);
  printf("Your average is: ", avg);


  return 0;
}

double min(array, cp)
{
  int i;
  double x;
  for (i = 0; i <= cp; i++)
    {
      x = array[i];
      if (x < min)
	{
	  min = x;
	}
    }
}

double max(array, cp)
{
  int i;
  double x;
  for (i = 0; i <= cp; i++)
    {
      x = array[i];
      if (x > max)
	{
	  max = x;
	}
    }
}

double average(array, cp)
{
  int i;
  double x;
  double avg;
  for (i = 0; i <= cp; i++)
    {
      x = x + array[i];
    }
  avg = x / count;
}
