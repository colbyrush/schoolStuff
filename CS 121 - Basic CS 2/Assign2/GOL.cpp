/* Assignment #2        Colby Rush
   CS 121-02            2/10/2011 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int life(int **, int, int);
int status(int **, int, int);
void print(int **, int, int);

int main(int argc, char **argv)
{
  ifstream infile;
  string input_file;
  int x; // size x
  int y; // size y
  cout << "Enter a filename: " << endl; // select and open file
  cin >> input_file;
  infile.open(input_file.c_str());
  int i; // x of array
  int e; // y of array
  int *colony; // int array
  int b = 0;   // colony counter
  int gridx, gridy, sizex, sizey; // grid coord


  while(infile.is_open() == false)
    {
      cout << "Cannot open file." << endl;
      cin >> input_file;
      infile.open(input_file.c_str());
    }                                  // file open
 
  int **array;         // dynamic array creation

  infile >> x >> y;
  
  array = new int*[x];

  for(i=0;i<x;i++);
  {
    array[i] = new int[y];
  }                   

  for(i=0;i<x;i++)
    {
      for(int e=0;e<y;e++)
	{
	  array[i][e] = 0;
	}
    }                   // created
  while(!infile.eof())
    {  
      infile >> gridx >> gridy >> sizex >> sizey;
      int c = (sizex * sizey) - 1; // colony variable
      colony = new int[c];
      for (i = 0; i < c; i++)
	{
	  infile >> colony[i];   // reads in cells
	}

      for (i = gridy; i < (c+1)/sizey; i++) // placement loop
	{
	  for (e = gridx; e < (c+1)/sizey; e++)
	    {
	      if (colony[e+b] == 0)
		{
		  array[i][e] = 0;
		}
	      else if (colony[e+b] == 1)
		{
		  array[i][e] = 1;
		}
	    }
	  b = b + (c+1)/sizey;             // counter addon
	}

    }
  
  infile.close();

  while (1 == 1) // runs all methods
    {
  life(array, x, y);
  status(array, x, y);
  print(array, x, y);
    }  
  return 0;


}

int neighbors(int **array, int x, int y) // counts amount of neighbors for a cell
{
  int q;
  int w;
  int count = 0;
  for (q = x - 1; q < x + 1; x++)
    {
      for (w = y - 1; w < y + 1; y++)
        {
	  if (q < 0 || q > x)
	    {
	      q = x;
	    }
	  else if (w < 0 || w > y)
	    {
	      w = y;
	    }
	  else
	    {
	      if (array[q][w] > 0)
		{
		count++;
		}
	    }
	}
    }
  return count;
}


int life(int **array, int x, int y) // determines if cell is alive or dead
{
  int count = 0;
  for (int i = 0; i < x; i++)
    {
      for (int e = 0; e < y; e++)
        {
	  if (array[i][e] == 0)
	    {
	      count = neighbors(array, i, e);
	      if(count == 3)
		{
		  array[i][e]++;
		}
	    }
	  else
	    {
	      if(count < 2 || count > 3)
		{
		  array[i][e] = 0;
		}
	     else
		{
		  array[i][e]++;
		  if (array[i][e] == 9)
		    {
		      array[i][e] = 9;
		    }
		}
	    }
	}
    }
}

int status(int **array, int x, int y) // percentage at bottom of cells taken
{
  int count = 0;
  int per;
  for (int i = 0; i < x; i++)
    {
      for (int e = 0; e < y; e++)
	{
	  if (array[i][e] != 0)
	    {
	      count++;
	    }
	}
    }
  per = count / (x*y);
  cout << "The amount of cells alive are: " << per << " %" << endl;
}

void print(int **array, int x, int y) // prints array
{
  for (int i=0;i<x;i++)
    {
      for (int e=0;e<y;e++)
	{
	  cout << array[i][e];
	}
      cout << endl;
    }
}
