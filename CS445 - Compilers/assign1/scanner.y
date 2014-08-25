%{
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tokenStruct.h"
#include "tree.c"
#include "yyerror.cpp"
#define YYERROR_VERBOSE

  //
  extern int lineno;
  extern int yydebug;
  extern int yylex();
  extern FILE* yyin;
  static TreeNode *savedTree;
  int numErrors = 0;
  int numWarnings = 0;

%}


%union  
 {
   ExpType type;
   TokenData *tokenData;
   TreeNode *tNode;
}


%token <tokenData> ID NUMCONST CHARCONST STRINGCONST
%token <tokenData> AND BREAK BOOL CHAR ELSE FALSE FOREACH IF IN INT OR NOT RETURN TRUE STATIC WHILE
%token <tokenData> COMMA LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE SEMI
%token <tokenData> EQUIV NEQ LEQ LESSER GEQ GREATER ASSIGN PASSIGN MASSIGN DEC INC COLON
%token <tokenData> PLUS MINUS DIVIDE MOD MULTI

%type <tNode> program declarationlist declaration

%type <tNode> vardeclaration scopedvardeclaration vardecllist vardeclinitialize vardeclid

%type <tNode> fundeclaration params paramlist paramtypelist paramidlist paramid

%type <tNode> statement sstatement compoundstmt localdeclarations statementlist expressionstmt
%type <tNode> matchedselectionstmt unmatchedselectionstmt
%type <tNode> returnstmt breakstmt

%type <tNode> expression simpleexpression andexpression unaryrelexpression relexpression
%type <tNode> relop additiveexpression sumop term mulop unaryexpression unaryop
%type <tNode> factor mutable immutable call args arglist constant

%type <type> typespecifier scopedtypespecifier

%%

program:
 declarationlist                                     { savedTree = $1; }
;

declarationlist:
declarationlist declaration                         
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $2;
      $$ = $1;
    }
  else
    $$ = $2;
}

|   declaration                                         { $$ = $1; }
| error                                                          {$$ = NULL; };
;

declaration:   
vardeclaration                                      { $$ = $1; }
|   fundeclaration                                      { $$ = $1; }
;

vardeclaration:   
typespecifier vardecllist SEMI                      
{ 
  TreeNode* t = $2;
  while(t!=NULL)
    {
      t->expType=$1;
      t = t->sibling;
    }
  $$ = $2;
  $$->isStatic=false;
  
  yyerrok;

}
| typespecifier error SEMI                                       {$$ = NULL; yyerrok; };    //EE    
;

scopedvardeclaration:   
scopedtypespecifier vardecllist SEMI          
{ 
  TreeNode* t = $2;
  while(t!=NULL)
    {
      t->expType=$1;
      t = t->sibling;
    }
  $$ = $2;
  $$->isStatic=true; 
}
| typespecifier error SEMI                                       { $$=NULL; yyerrok; }; //EE
| STATIC typespecifier vardecllist SEMI                 
{ 
  TreeNode* t = $3;
  while(t!=NULL)
    {
      t->expType=$2;
      t = t->sibling;
    }
  $$ = $3;
  $$->isStatic=true;

  yyerrok;
}
| typespecifier vardecllist SEMI                        
{
  TreeNode* t = $2;
  while(t!=NULL)
    {
      t->expType=$1;
      t = t->sibling;
    }
  $$ = $2;
  $$->isStatic=false;

  yyerrok;
}
;

vardecllist:   
vardecllist COMMA vardeclinitialize                 
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $3;
      $$ = $1;
    }
  else
    $$ = $3;

  yyerrok; 

}
|   vardeclinitialize                                   { $$ = $1; }
| error COMMA vardeclinitialize                                  {$$ = NULL; yyerrok; }; //EE
;

vardeclinitialize: 
vardeclid                                                  { $$ = $1; }
|   vardeclid COLON simpleexpression                    { $$ = $1; $$->child[0] = $3; }
| vardeclid COLON error                                          { $$ = NULL; }; //EE
;

vardeclid:   
ID                                                  { $$ = newDeclNode(varK,yylval.tokenData->lineno); $$->attr.name=$1->idvalue; }
|   ID LBRACKET NUMCONST RBRACKET                       { $$ = newDeclNode(varK,yylval.tokenData->lineno); $$->attr.name=$1->idvalue; $$->isArray=true; }
| ID LBRACKET error                                                   {$$ = NULL; yyerrok;}; //EE
;

scopedtypespecifier: 
typespecifier                                             { $$ = $1;}
|STATIC typespecifier                                        { $$ = $2;}

;

typespecifier:
INT                                                 { $$ = Int; }
|   BOOL                                                { $$ = Bool; }
|   CHAR                                                { $$ = Char; }
;

fundeclaration:  
typespecifier ID LPAREN params RPAREN statement     { int lineno = $2->lineno; $$ = newDeclNode(funcK,lineno); $$->child[0]=$4; $$->child[1]=$6; $$->attr.name=$2->idvalue; $$->expType=$1; }
|   ID LPAREN params RPAREN statement                   { int lineno = $1->lineno; $$ = newDeclNode(funcK,lineno); $$->child[0]=$3; $$->child[1]=$5; $$->attr.name=$1->idvalue; $$->expType=Void; }
| typespecifier error LPAREN params RPAREN statement                  { $$ = NULL; yyerrok; }; //EE
| typespecifier ID LPAREN error                                    { $$ = NULL; }; //EE
| ID LPAREN error RPAREN statement                                     { $$ = NULL; yyerrok; }; //EE
| error RPAREN statement                                            { $$ = NULL; yyerrok; }; //EE
;

params: 
paramlist                                           { $$ = $1; }
|                                                       { $$ = NULL; }
;

paramlist:  
paramlist SEMI paramtypelist                        
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $3;
      $$ = $1;
    }
  else
    $$ = $3;
}
|   paramtypelist                                       { $$ = $1; }
| error SEMI paramtypelist                                      {$$ = NULL; yyerrok; }; //EE
;

paramtypelist:  
typespecifier paramidlist                           
{
  TreeNode* t = $2;
  while(t!=NULL)
    {
      t->expType=$1;
      t = t->sibling;
    }
  $$ = $2;
} 
| typespecifier error                                           {$$ = NULL; }; //EE
;

paramidlist:
paramidlist COMMA paramid                         
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $3;
      $$ = $1;
    }
  else
    $$ = $3;
  
  yyerrok;
}
|   paramid                                            
| error COMMA paramid                                             {$$ = NULL; yyerrok; }; //EE
| paramidlist COMMA error                                        {$$ = NULL; yyerrok; }; //EE
;

paramid:   
ID                                                  { $$ = newDeclNode(paramK,yylval.tokenData->lineno); $$->attr.name=$1->idvalue; }
|   ID LBRACKET RBRACKET                                { $$ = newDeclNode(paramK,yylval.tokenData->lineno); $$->attr.name=$1->idvalue; $$->isArray=true; }
| error LBRACKET NUMCONST RBRACKET                                         {$$ = NULL; yyerrok; }; //EE
| ID LBRACKET error                                                   {$$ = NULL; yyerrok;}; //EE
;

statement:
matchedselectionstmt                                { $$ = $1; }
| unmatchedselectionstmt                              { $$ = $1; }
| matchedselectionstmt error                                                  {$$ = $1;}; //EE
| unmatchedselectionstmt error                                                {$$ = $1;}; //EE
;

sstatement:
expressionstmt                                      { $$ = $1; }
|   compoundstmt                                        { $$ = $1; }
|   returnstmt                                          { $$ = $1; }
|   breakstmt                                           { $$ = $1; }
;

compoundstmt:  
LBRACE localdeclarations statementlist RBRACE       { int lineno=$1->lineno; $$ = newStmtNode(compoundK,lineno); $$->child[0]=$2; $$->child[1]=$3; }
| error RBRACE                                                      {$$ = NULL; yyerrok; }; //EE
| LBRACE error statementlist RBRACE                                   {$$ = NULL; yyerrok; }; //EE
;

localdeclarations:  
localdeclarations scopedvardeclaration              
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $2;
      $$ = $1;
    }
  else
    $$ = $2;
}
|                                                       { $$ = NULL; }
;

statementlist:   
statementlist statement                             
{ 
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $2;
      $$ = $1;
    }
  else
    $$ = $2;
}
|                                                       { $$ = NULL; }
| statementlist error                                           {$$ = NULL; }; //EE
;

expressionstmt:
expression SEMI                                     { $$ = $1; yyerrok;}
|   SEMI                                                { $$ = NULL; yyerrok;}
| error SEMI                                                      {$$ = NULL; yyerrok; }; //EE
;

matchedselectionstmt:
IF LPAREN simpleexpression RPAREN matchedselectionstmt ELSE matchedselectionstmt            { int lineno=$1->lineno; $$ = newStmtNode(ifK,lineno); $$->child[0]=$3; $$->child[1]=$5; $$->child[2]=$7; }
|   WHILE LPAREN simpleexpression RPAREN matchedselectionstmt                                   { int lineno=$1->lineno; $$ = newStmtNode(whileK,lineno); $$->child[0]=$3; $$->child[1]=$5; }
|   FOREACH LPAREN mutable IN simpleexpression RPAREN matchedselectionstmt                      { int lineno=$1->lineno; $$ = newStmtNode(foreachK,lineno); $$->child[0]=$3; $$->child[1]=$5; $$->child[2]=$7; }
|   sstatement                                                                                  { $$ = $1; }
| IF LPAREN error                                                   {$$ = NULL; }; //EE
| error RPAREN matchedselectionstmt ELSE matchedselectionstmt       {$$ = NULL; yyerrok; }; //EE
| WHILE LPAREN error                                                {$$ = NULL; }; //EE
| FOREACH LPAREN error                                              {$$ = NULL; }; //EE
;

unmatchedselectionstmt:
IF LPAREN simpleexpression RPAREN statement                                                 { int lineno=$1->lineno; $$ = newStmtNode(ifK,lineno); $$->child[0]=$3; $$->child[1]=$5; }
|   IF LPAREN simpleexpression RPAREN matchedselectionstmt ELSE unmatchedselectionstmt          { int lineno=$1->lineno; $$ = newStmtNode(ifK,lineno); $$->child[0]=$3; $$->child[1]=$5; $$->child[2]=$7; }
|   WHILE LPAREN simpleexpression RPAREN unmatchedselectionstmt                                 { int lineno=$1->lineno; $$ = newStmtNode(whileK,lineno); $$->child[0]=$3; $$->child[1]=$5; }
|   FOREACH LPAREN mutable IN simpleexpression RPAREN unmatchedselectionstmt                    { int lineno=$1->lineno; $$ = newStmtNode(foreachK,lineno); $$->child[0]=$3; $$->child[1]=$5; $$->child[2]=$7; }
| IF LPAREN simpleexpression RPAREN error ELSE unmatchedselectionstmt              {$$ = NULL; yyerrok; }; //EE
| IF LPAREN error                                                                           {$$ = NULL; }; //EE
| WHILE LPAREN error                                                                  {$$ = NULL; }; //EE
| FOREACH LPAREN error                                                                 {$$ = NULL; }; //EE
| error RPAREN statement                                                               {$$ = NULL; yyerrok; }; //EE

;

returnstmt:
RETURN SEMI                                         { $$ = newStmtNode(returnK,yylval.tokenData->lineno); }
|   RETURN expression SEMI                              { $$ = newStmtNode(returnK,yylval.tokenData->lineno); $$->child[0] = $2; }
| RETURN error                                                   {$$ = NULL; }; //EE
;

breakstmt:
BREAK SEMI                                          { $$ = newStmtNode(breakK,yylval.tokenData->lineno); }
;

expression:
mutable ASSIGN expression                           
{
  TreeNode* t = $3;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      $$ = newExpNode(assignK,yylval.tokenData->lineno);
      $$->attr.op = eqK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
  else
    {
      $$ = newExpNode(assignK,yylval.tokenData->lineno);
      $$->attr.op = eqK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
}
|   mutable PASSIGN expression                          
{
  TreeNode* t = $3;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      $$ = newExpNode(assignK,yylval.tokenData->lineno);
      $$->attr.op = peqK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
   else
     {
       $$ = newExpNode(assignK,yylval.tokenData->lineno);
       $$->attr.op = peqK;
       $$->child[0] = $1;
       $$->child[1] = $3;
     }
 }
|   mutable MASSIGN expression                          
{
  TreeNode* t = $3;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      $$ = newExpNode(assignK,yylval.tokenData->lineno);
      $$->attr.op = meqK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
  else
    {
      $$ = newExpNode(assignK,yylval.tokenData->lineno);
      $$->attr.op = meqK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
 }
|   mutable INC                                         { $$ = newExpNode(assignK,yylval.tokenData->lineno); $$->attr.op = ppK; $$->child[0] = $1; }
|   mutable DEC                                         { $$ = newExpNode(assignK,yylval.tokenData->lineno); $$->attr.op = mmK; $$->child[0] = $1; }
|   simpleexpression                                    { $$ = $1; }
| error ASSIGN expression                                      {$$ = NULL; yyerrok; }; //EE
| mutable ASSIGN error                                         {$$ = NULL; }; //EE
| error INC                                                      {$$ = NULL; yyerrok; }; //EE
| error DEC                                                      {$$ = NULL; yyerrok; }; //EE
| mutable error expression                                       {$$ = NULL; yyerrok; }; //EE
;

simpleexpression:
simpleexpression OR andexpression                   
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      $$ = newExpNode(opK,yylval.tokenData->lineno);
      $$->attr.op = orK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
  else
    {
      $$ = newExpNode(opK,yylval.tokenData->lineno);
      $$->attr.op = orK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
}
|   andexpression                                       { $$ = $1; }
| error OR OR                                       {$$ = NULL; yyerrok; }; //EE
| simpleexpression OR error                                     {$$ = NULL; }; //EE
;

andexpression:  
andexpression AND unaryrelexpression                
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      $$ = newExpNode(opK,yylval.tokenData->lineno);
      $$->attr.op = andK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
  else
    {
      $$ = newExpNode(opK,yylval.tokenData->lineno);
      $$->attr.op = andK;
      $$->child[0] = $1;
      $$->child[1] = $3;
    }
}
|   unaryrelexpression                                  { $$ = $1; }
| error AND unaryrelexpression                                 {$$ = NULL; yyerrok; }; //EE
| OR AND error                                        {$$ = NULL; }; //EE
;

unaryrelexpression: 
NOT unaryrelexpression                              { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = notK; $$->child[0]=$2; }
|   relexpression                                       { $$ = $1; }
| NOT error                                                      {$$ = NULL; }; //EE
;

relexpression:
additiveexpression relop additiveexpression                   { $$ = $2; $$->child[0] = $1; $$->child[1] = $3; }
|   additiveexpression                                       { $$ = $1; }
| error relop additiveexpression                                {$$ = NULL; yyerrok; }; //EE
| additiveexpression relop error                                {$$ = NULL; }; //EE
;

relop:
LEQ                                                 { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = lteqK; }
|   LESSER                                              { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = ltK; }
|   GREATER                                             { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = gtK; }
|   GEQ                                                 { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = gteqK; }
|   EQUIV                                               { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = equivK; }
|   NEQ                                                 { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = neqK; }
;

additiveexpression:  
additiveexpression sumop term                            { $$ = $2; $$->child[0]=$1; $$->child[1]=$3; }
|   term                                                { $$ = $1; }
| error sumop term                                               {$$ = NULL; yyerrok; }; //EE
| additiveexpression sumop error                                {$$ = NULL; }; //EE
;

sumop:   
PLUS                                                { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = plusK; }
|   MINUS                                               { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = minusK; }
;


term:
term mulop unaryexpression                          { $$ = $2; $$->child[0] = $1; $$->child[1]=$3; }
|   unaryexpression                                     { $$ = $1; }
| error mulop unaryexpression                                   {$$ = NULL; yyerrok; }; //EE
| term mulop error                                               {$$ = NULL; }; //EE
;

mulop:
MULTI                                               { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = multiK; }
|   DIVIDE                                              { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = divideK; }
|   MOD                                                 { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = modK; }
;

unaryexpression: 
unaryop unaryexpression                             { $$ = $1; $$->child[0]=$2; }
|   factor                                              { $$ = $1; }
| unaryop error                                                  {$$ = NULL; }; //EE
;

unaryop:
MINUS                                               { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = UminusK; }
|   MULTI                                               { $$ = newExpNode(opK,yylval.tokenData->lineno); $$->attr.op = UmultiK; }
;

factor: 
immutable                                           { $$ = $1; }
|   mutable                                             { $$ = $1; }
;

mutable:
ID                                                  { $$ = newExpNode(idK,yylval.tokenData->lineno); $$->attr.name=$1->idvalue; }
|   ID LBRACKET expression RBRACKET                     { $$ = newExpNode(idK,$1->lineno); $$->child[0] = $3; $$->attr.name=$1->idvalue; $$->isArray = true; }
| ID LBRACKET error                                                   {$$ = NULL; }; //EE
| error RBRACKET                                                      {$$ = NULL; yyerrok; }; //EE
;

immutable:
LPAREN expression RPAREN                            { $$ = $2; yyerrok;}
|   call                                                { $$ = $1; }
|   constant                                            { $$ = $1; $$->isConstant = true; }
| LPAREN error                                                      {$$ = NULL; }; //EE
| error RPAREN                                                      {$$ = NULL; yyerrok; }; //EE
;

call:
ID LPAREN args RPAREN                               { $$ = newExpNode(callK, yylval.tokenData->lineno); $$->child[0] = $3; $$->attr.name=$1->idvalue;  }
| error LPAREN args RPAREN                                             {$$ = NULL; yyerrok; }; //EE
| ID LPAREN error                                                   {$$ = NULL; }; //EE
;

args:  
arglist                                             { $$ = $1; }
|                                                       { $$ = NULL; }
;

arglist:  
arglist COMMA expression                            
{
  TreeNode* t = $1;
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = $3;
      $$ = $1;
    }
  else
    $$ = $3;

  yyerrok;
}
|   expression                                          { $$ = $1; }
| error COMMA expression                                           {$$ = NULL; yyerrok; }; //EE
;

constant: 
NUMCONST                                            { $$ = newExpNode(constK,yylval.tokenData->lineno); $$->attr.val = $1->numvalue; $$->expType=Int; }
|   CHARCONST                                           { $$ = newExpNode(constK,yylval.tokenData->lineno); $$->attr.string = $1->tokenstr; $$->expType=Char; }
|   STRINGCONST                                         { $$ = newExpNode(constK,yylval.tokenData->lineno); $$->attr.string = $1->tokenstr; $$->expType=Char; }
|   TRUE                                                { $$ = newExpNode(constK,yylval.tokenData->lineno); $$->expType=True; }
|   FALSE                                               { $$ = newExpNode(constK,yylval.tokenData->lineno); }
;

%%

int main(int argc, char* argv[])
{
  int c;
  extern char* optarg;
  extern int optind;
  char **inputfile;
  
  int yydebug=0;
  
  inputfile = argv + optind;
  yyin = fopen((inputfile[0]), "r");
    
  initYyerror();
  yyparse(); 
  //  printTree(savedTree);
  //  checkErr(savedTree);
  
  while((c = getopt(argc, argv, "d:")) != -1)
    {
      switch(c)
        {
        case 'd':
          yydebug=1;
          printf("YYDEBUG==%d",yydebug);
          break;
        case 'p':
          printTree(savedTree);
          break;
        case 's':
          (DEBUG_TABLE | DEBUG_PUSH);
        default:
          printf("Unknown option(s)\n");
          break;
        }
      c = getopt(argc, argv, "dps:");
    }
  
  //  if (numErrors==0) scopeAndType(savedTree)
  
  printf("Number of errors: %d\n", numErrors);
  printf("Number of warnings: %d\n", numWarnings);
  
  return 0;
  
}

