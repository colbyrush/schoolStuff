#include <stdio.h>
#define DEBUG 0 
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)<0?-(x):(x))
int i=-5, j=4, k=-4, l=2, temp;

int main()
{
  printf("k, i: %d\n",MAX(ABS(k),i));
  #ifdef DEBUG
  printf("j, l-2: %d\n", MAX(j,ABS(l-9)));
  printf("l, k: %d\n", MAX(l,k));
  #endif
}
