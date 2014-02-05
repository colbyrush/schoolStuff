#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern char *yytext;
int main(int argc, char *argv[])
{
   int t;
   if (argc < 2) { printf("usage: scan file.dat\n"); exit(-1); }
   yyin = fopen(argv[1],"r");
   if (yyin == NULL) { printf("can't open/read '%s'\n", argv[1]); exit(-1); }
   while ((t=yylex()) > 0) {
      printf("token %d text %s\n", t, yytext);
      }
   return 0;
}

