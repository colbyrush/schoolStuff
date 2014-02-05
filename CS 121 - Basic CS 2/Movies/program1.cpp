/* Colby Rush    CS 121
   Movies Tree   4/17/11 */

#include <iostream>
#include <fstream>
#include "BSTree2.h"
#include <string>
#include "BSTree2.cpp"

using namespace std;

int main (int argc, char **argv)
{
  int i = 0, y = 0;
  string buffer;
  size_t pos;
  BinarySearchTree t1;
  ifstream file;
  movie movies;
  file.open ("movies.txt");
  while (!file.eof())
    {
      i = 0;
      getline (file, movies.title, '(');
      movies.title.erase(movies.title.length()-1);
      getline (file, movies.year);
      getline (file, buffer);
      for (int q = 0; q < 50; q++)
        movies.actor[q] = "";
      while (buffer != "")
        {
          movies.actor[i] = buffer;
          getline (file, buffer);                      // copy performers until blank
          i++;
        }
      t1.AddNode(movies);      
    }
  t1.PrintTree();   
  t1.HandRoot();
  t1.PrintAct();
  t1.PrintYear();
  return 0;
}
