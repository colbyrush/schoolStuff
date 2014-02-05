#include <iostream>

using namespace std;

struct item
{
  char data;
  int empty;
};

class boundedQueue
{

 private:

 public:

  int QPtr;
  const static int MAX_SIZE = 255;
  item BoundedQ[MAX_SIZE];
  
 boundedQueue()
    {
      QPtr = 0;
      for (int i = 0; i < MAX_SIZE; i++)
        {
          BoundedQ[i].empty = 0;
        }
    }

  bool put(char);
  bool get(char&);
  bool isFull();
  bool isEmpty();
  void reset();
  char freeSpots();
  char usedSpots();
  char getMaxSize();

};
