/* Colby Rush              CS 121
   Movies Hash Table   5/6/11  */

#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int main (int argc, char **argv)
{
  int i = 0;
  string buffer;
  size_t pos;
  ifstream file;
  nList movie;
  file.open ("movies.txt");
  while (!file.eof())
    {
      i = 0;
      getline (file, movie.title, '(');
      movie.title.erase(movie.title.length()-1);
      getline (file, movie.year);
      getline (file, buffer);
      for (int q = 0; q < 50; q++)
        movie.actor[q] = "";
      while (buffer != "")
        {
          movie.actor[i] = buffer;
          getline (file, buffer);                      // copy performers until blank
          i++;
        }      
      x = movie.title;
      Insert (movie.title, movie);
    }
  PrintHashTable();
  return 0;
}
