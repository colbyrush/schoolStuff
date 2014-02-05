/* Colby Rush     CS270
   SysCall */

#include <stdio.h>

int main(int argc, char **argv)
{

  FILE * fp;
  char str[200];

  fp = fopen("test.txt", "r");
  
  while(!feof(fp))
    {
      fgets(str, 100, fp);
      printf("%s", str);
      memset(&str[0], 0, sizeof(str));
    }

  fclose(fp);
  return 0;
}
