#include <stdio.h>

int main()
{
  int var1 = 8;
  int var2 = 20;
  int *var3 = &var2;
  int *var4 = &var1;
  double var5 = 6.5;
  double *var6 = &var5;

  int temp = *var1;

  printf ("%d", temp);
}
