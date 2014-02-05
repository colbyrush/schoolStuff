/* Colby Rush      CS 121
   Lab #13        4/28/11 */

#include <iostream>
#include "boundedqueue.h"


using namespace std;


bool boundedQueue::put(char x)
{
  int circ = QPtr % MAX_SIZE;
  if (isFull())
    return false;
  BoundedQ[circ].data = x;
  BoundedQ[circ].empty = 1;
  QPtr++;
  return true;
}

bool boundedQueue::get(char& x)
{
  int circ = QPtr % MAX_SIZE;
  if (BoundedQ[circ].empty == 0)
    {
      QPtr++;
      return false;
    }
  x = BoundedQ[circ].data;
  BoundedQ[circ].empty = 0;
  QPtr++;
  return true;
}

bool boundedQueue::isFull()
{
  char count = usedSpots();
  if (count = getMaxSize())
    return false;
  else
    return true;
}

bool boundedQueue::isEmpty()
{
  char count = freeSpots();
  if (count = getMaxSize())
    return true;
  else
    return false;
}

char boundedQueue::freeSpots()
{
  int count = 0;
  for (int i = 0; i < MAX_SIZE; i++)
    if (BoundedQ[i].empty == 0)
      count++;
  return count;
}

char boundedQueue::usedSpots()
{
  int count = 0;
  for (int i = 0; i < MAX_SIZE; i++)
    if (BoundedQ[i].empty == 1)
      count++;
  return count;
}

void boundedQueue::reset()
{
  for (int i = 0; i < MAX_SIZE; i++)
    BoundedQ[i].empty = 0;
  QPtr = 0;
}

char boundedQueue::getMaxSize()
{
  return MAX_SIZE;
}
