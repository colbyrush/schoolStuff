%{
#include "unic.h"
#include <math.h>
%}

digit [0-9]
ident [a-z][a-z0-9]*

%%

"abstract" {return ABSTRACT ;}
"break" {return BREAK ;}
"by" {return BY ;}
"case" {return CASE ;}
"class" {return CLASS ;}
"create" {return CREATE ;}
"critical" {return CRITICAL ;}
"default" {return DEFAULT ;}
"do" {return DO ;}
"else" {return ELSE ;}
"end" {return END ;}
"every" {return EVERY ;}
"fail" {return FAIL ;}
"global" {return GLOBAL;}
"if" {return IF ;}
"import" {return IMPORT ;}
"initial" {return INITIAL ;}
"initially" {return INITIALLY ;}
"invocable" {return INVOCABLE ;}
"link" {return LINK ;}
"local" {return LOCAL ;}
"method" {return METHOD;}
"next" {return NEXT ;}
"not" {return NOT ;}
"of" {return OF ;}
"package" {return PACKAGE ;}
"procedure" {return PROCEDURE ;}
"record" {return RECORD ;}
"repeat" {return REPEAT ;}
"return" {return RETURN ;}
"static" {return STATIC ;}
"suspend" {return SUSPEND ;}
"then" {return THEN ;}
"to" {return TO ;}
"until" {return UNTIL ;}
"while" {return WHILE ;}
\"(\\.|[^""])*\" {return STRINGLIT ;}
\'(\\.|[^''])*\' {return CSETLIT ;}
{ident} {return IDENT ;}
{digit}[rR][a-z0-9]* {return INTLIT ;}
{digit}+"."{digit}* {return REALLIT ;}
"(" {return LPAREN ;}
")" {return RPAREN ;}
"|" {return BAR ;}
"&" {return AND ;}
"{" {return LBRACE ;}
"}" {return RBRACE ;}
";" {return SEMICOL ;}
"," {return COMMA ;}
":=" {return ASSIGN;}
"+:=" {return AUGPLUS;}
"-:=" {return AUGMINUS;}
"*:=" {return AUGSTAR;}
"/:=" {return AUGSLASH;}
[ \t\n]+
. printf ("Unrecognized character: %s\n", yytext );

%%
