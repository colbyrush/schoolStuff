/* Lab #2           Colby rush
   CS 121-02        1/27/2011 */

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
  if (argc < 3)
    {
      cout << "Arguement amount entered insufficent. Please enter at least 3." << endl;
      return 1;
    }
  int i;
  cout << "Argc = " << argc << endl << "Argv = ";
  for (i=0; i < argc; i++)
    {
      if (i == 1)
	{
	  int x = atoi(argv[i]);
	  cout << "Integer value: " << x << " | ";
	}
      else if (i == 2)
	{
	  float x = atof(argv[i]);
	  cout << "Floating value: " << x << " | ";
	}
      else
	{
	  int x = atoi(argv[i]);
	  cout << x << " | ";
	}
    }
  cout << endl;
}




/*  Script started on Thu 27 Jan 2011 01:42:33 PM PST
bash-3.2$ /a.out 2 two hi cody
Argc = 5
Argv = 0 | Integer value: 2 | Floating value: 0 | 0 | 0 |
bash-3.2$ ./a.out 43 23 23.432 hey test lol
Argc = 5
Argv = 0 | Integer value: 43 | Floating value: 23.432 | 0 | 0 |
bash-3.2$ ./a.out mods are asleep post sinks
Argc = 6
Argv = 0 | Integer value: 0 | Floating value: 0 | 0 | 0 | 0 |
*/