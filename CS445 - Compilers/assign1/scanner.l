/* Beginning scanner for compiler design - Colby Rush, CS 445, Assignment 1, Last Updated 10/30/13 */


%{
    #include "tree.h"
    #include <string>
    #include <stdio.h>
    #include <stdlib.h>
    #include "tokenStruct.h"
    #include "scanner.tab.h"
    extern int numWarnings;
    int lineno = 1;
    char lastToken[100];

    char* copystr(char* s)
    {
        int x;
        char* m;
        if(s==NULL) return NULL;
        x = strlen(s)+1;
        m = (char*)malloc(x);
        if(m==NULL)
            printf("Copystr error");
        else strcpy(m,s);
        
        return m;
    }

    char* remlit(char* s, int type)
    {
        int i;
        char *t = copystr(s);
        int x = strlen(t) + 1;
        
        
            if(t[i]=='\\')
            {
                int q = i;
                while(q < x)
                {
                    t[q] = t[q+1];
                    q++;
                }
                t[q] = '\0';
                switch(t[i])
                {
                    case 't':
                        t[i]='\t';
                        break;
                    case 'n':
                        t[i]='\n';
                        break;                    
                    case '0':
                        t[i+1]='\0';
                        if(type == 0)
                            t[i] = '\'';
                        else
                            t[i] = '\"';
                        break;
                    default:
                        printf("String literal");
                        break;
                }
                q++;
            }
            else if(t[i]== '^')
            {
                int q = i;
                while(q < x)
                {
                    t[q] = t[q+i];
                    q++;
                }
                t[q] = '\0';
                t[i] = t[i] ^ 0x40;
            }
            else
                t[i]=s[i];
        return t;
    }

    
    int maketoken(int linenum, int tokenClass, char* svalue)
    {
            
            yylval.tokenData = new TokenData;
            yylval.tokenData->tokenClass = tokenClass;
            yylval.tokenData->lineno = lineno;
            switch(tokenClass)
            {
                case NUMCONST:
                    strcpy(lastToken, svalue);
                    yylval.tokenData->numvalue = atoi(svalue);
                case ID:
                    strcpy(lastToken, svalue);
                    yylval.tokenData->idvalue = copystr(svalue);
                case CHARCONST:
                    strcpy(lastToken, svalue);
                    yylval.tokenData->tokenstr = copystr(remlit(svalue, 0));
                case STRINGCONST:
                    strcpy(lastToken, svalue);                                
                    yylval.tokenData->tokenstr = copystr(remlit(svalue, 0));
                default:
                    strcpy(lastToken, svalue);
                    yylval.tokenData->keyvalue = copystr(svalue);
            }

return tokenClass;

    }

%}

%%

[ \t]                                   ; //whitespace
\n                                      lineno++;

\/\/.*\n                                lineno++; //comments


"and"                                   {return maketoken(lineno, AND, yytext);}
"break"                                 {return maketoken(lineno, BREAK, yytext);}
"bool"                                  {return maketoken(lineno, BOOL, yytext);}
"char"                                  {return maketoken(lineno, CHAR, yytext);}
"else"                                  {return maketoken(lineno, ELSE, yytext);}
"false"                                 {return maketoken(lineno, FALSE, yytext);}
"foreach"                               {return maketoken(lineno, FOREACH, yytext);}
"if"                                    {return maketoken(lineno, IF, yytext);}
"in"                                    {return maketoken(lineno, IN, yytext);}
"int"                                   {return maketoken(lineno, INT, yytext);}
"or"                                    {return maketoken(lineno, OR, yytext);}
"not"                                   {return maketoken(lineno, NOT, yytext);}
"return"                                {return maketoken(lineno, RETURN, yytext);}
"true"                                  {return maketoken(lineno, TRUE, yytext);}
"static"                                {return maketoken(lineno, STATIC, yytext);}
"while"                                 {return maketoken(lineno, WHILE, yytext);}
"=="                                    {return maketoken(lineno, EQUIV, yytext);}
"!="                                    {return maketoken(lineno, NEQ, yytext);}
"<="                                    {return maketoken(lineno, LEQ, yytext);}
"<"                                     {return maketoken(lineno, LESSER, yytext);}
">="                                    {return maketoken(lineno, GEQ, yytext);}
">"                                     {return maketoken(lineno, GREATER, yytext);}
"="                                     {return maketoken(lineno, ASSIGN, yytext);}
"+="                                    {return maketoken(lineno, PASSIGN, yytext);}
"-="                                    {return maketoken(lineno, MASSIGN, yytext);}
"--"                                    {return maketoken(lineno, DEC, yytext);}
"++"                                    {return maketoken(lineno, INC, yytext);}
":"                                     {return maketoken(lineno, COLON, yytext);}

","                                     {return maketoken(lineno, COMMA, yytext);}
"["                                     {return maketoken(lineno, LBRACKET, yytext);}
"]"                                     {return maketoken(lineno, RBRACKET, yytext);}
"("                                     {return maketoken(lineno, LPAREN, yytext);}
")"                                     {return maketoken(lineno, RPAREN, yytext);}
"{"                                     {return maketoken(lineno, LBRACE, yytext);}
"}"                                     {return maketoken(lineno, RBRACE, yytext);}
";"                                     {return maketoken(lineno, SEMI, yytext);}

"+"                                     {return maketoken(lineno, PLUS, yytext);}
"-"                                     {return maketoken(lineno, MINUS, yytext);}
"/"                                     {return maketoken(lineno, DIVIDE, yytext);}
"%"                                     {return maketoken(lineno, MOD, yytext);}
"*"                                     {return maketoken(lineno, MULTI, yytext);}

[a-zA-Z][a-zA-Z0-9_]*                   {return maketoken(lineno, ID, yytext);}
[0-9]+                                  {return maketoken(lineno, NUMCONST, yytext);}
'([^'\\\n]]|\\.|^.)'                    {return maketoken(lineno, CHARCONST, yytext);}
\"(\\.|[^\\"])*\"                       {return maketoken(lineno, STRINGCONST, yytext);}

.                                       {printf("WARNING(%d): Invalid input character: %s. Character ignored.", lineno, lastToken); numWarnings++;}

%%