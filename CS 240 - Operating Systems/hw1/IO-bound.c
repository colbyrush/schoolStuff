#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  int x = 0;
  FILE *fp;
  while(x==0)
    {
      fp = fopen("input.txt","a");
      fputs ("@ ", fp);
      fclose (fp);
    }
}

