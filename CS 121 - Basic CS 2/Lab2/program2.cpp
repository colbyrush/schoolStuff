/* Lab #2       Colby Rush
   CS 121-02    1/27/2010 */

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  if (argc < 3)
    {
      cout << "Arguement amount entered insufficent. Please enter at least 3." << endl;
      return 1;
    }
  double a;
  int x = atoi(argv[1]);
  int y = atoi(argv[3]);
  switch(argv[2][0])
    {
    case '+':
     a = x + y;
     break;
    case '-':
     a = x - y;
     break;
    case '*': 
     a = x * y;
     break;
    case '/':   
     a = x / (double)y;
     break;
    }
     cout << argv[1] << " " << argv[2] << " " << argv[3] << " = " << a << endl;
     return 0;
}


/* Script started on Thu 27 Jan 2011 02:41:40 PM PST
bash-3.2$ ./a.out 2 + 2
2 + 2 = 4
bash-3.2$ ./a.out 2 - 4
2 - 4 = -2
bash-3.2$ ./a.out 2 / 4
2 / 4 = 0.5
bash-3.2$ ./a.out 2 * 4
2 a.out #program1.cpp# = 2.07358e-317
bash-3.2$ exit */
