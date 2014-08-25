
#include "tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#include "symtab.cpp"

static int indentno = -1;

void nodeprint(void *p);

#define INDENT indentno+=1
#define UNINDENT indentno-=1

#ifndef STMTNODE
#define STMTNODE

TreeNode* newStmtNode(StmtKind kind, int lineno)
{
  TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    
  int i;
  if(t==NULL)
    printf("Out of memory error at line ");
  else
    {
      for(i = 0;i < MAXCHILDREN; i++)
        t->child[i] = NULL;
        
      t->sibling = NULL;
      t->nodekind = StmtK;
      t->kind.stmt = kind;
      t->lineno = lineno;
    }
    
  return t;
}
#endif
#ifndef EXPNODE
#define EXPNODE
TreeNode* newExpNode(ExpKind kind, int lineno)
{
  TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    
  int i;
  if(t==NULL)
    printf("Out of memory error at line ");
  else
    {
      for(i = 0;i < MAXCHILDREN; i++)
        t->child[i] = NULL;
        
      t->sibling = NULL;
      t->nodekind = ExpK;
      t->kind.exp = kind;
      t->lineno = lineno;
      t->expType = Void;
    }
    
  return t;
}
#endif
#ifndef DECLNODE
#define DECLNODE
TreeNode* newDeclNode(DeclKind kind, int lineno)
{
  TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    
  int i;
  if(t==NULL)
    printf("Out of memory error at line ");
  else
    {
      for(i = 0;i < MAXCHILDREN; i++)
        t->child[i] = NULL;
        
      t->sibling = NULL;
      t->nodekind = DeclK;
      t->kind.decl = kind;
      t->lineno = lineno;
      t->expType = Void;
    }
    
  return t;
}
#endif
#ifndef PTREE
#define PTREE
void printTree(TreeNode* t)
{
  int i;
  int sibling = 1;
  char* op = NULL;
  char* type = NULL;
  char* array = NULL;
  INDENT;
    
  while(t != NULL)
    {
      printSpaces();
      if(t->nodekind==StmtK)
        switch(t->kind.stmt)
          {
          case ifK:
            printf("If [line: %d]\n", t->lineno);
            break;
          case returnK:
            printf("Return [line: %d]\n", t->lineno);
            break;
          case compoundK:
            printf("Compound [line: %d]\n", t->lineno);
            break;
          case breakK:
            printf("Break [line: %d]\n", t->lineno);
            break;
          case foreachK:
            printf("Foreach [line: %d]\n", t->lineno);
            break;
          case whileK:
            printf("While [line: %d]\n", t->lineno);
            break;
                    
          }
      else if(t->nodekind==ExpK)
        switch(t->kind.exp)
          {
          case opK:
            switch(t->attr.op)
              {
              case ppK:
                printf("Op: ++ [line: %d]\n", t->lineno);
                break;
              case mmK:
                printf("Op: -- [line: %d]\n", t->lineno);
                break;
              case ltK:
                printf("Op: < [line: %d]\n", t->lineno);
                break;
              case gtK:
                printf("Op: > [line: %d]\n", t->lineno);
                break;
              case equivK:
                printf("Op: == [line: %d]\n", t->lineno);
                break;
              case peqK:
                printf("Op: += [line: %d]\n", t->lineno);
                break;
              case meqK:
                printf("Op: -= [line: %d]\n", t->lineno);
                break;
              case neqK:
                printf("Op: != [line: %d]\n", t->lineno);
                break;
              case modK:
                printf("Op: mod [line: %d]\n", t->lineno);
                break;
              case UminusK:
                printf("U-");
                break;
              case UmultiK:
                printf("U*");
                break;
              case minusK:
                printf("Op: - [line: %d]\n", t->lineno);
                break;
              case plusK:
                printf("Op: + [line: %d]\n", t->lineno);
                break;
              case multiK:
                printf("Op: * [line: %d]\n", t->lineno);
                break;
              case divideK:
                printf("Op: / [line: %d]\n", t->lineno);
                break;
              case colonK:
                printf("Op: : [line: %d]\n", t->lineno);
                break;
              case lteqK:
                printf("Op: <= [line: %d]\n", t->lineno);
                break;
              case gteqK:
                printf("Op: >= [line: %d]\n", t->lineno);
                break;
              case notK:
                printf("Op: not [line: %d]\n", t->lineno);
                break;
              case eqK:
                printf("Op: = [line: %d]\n", t->lineno);
              case andK:
                printf("Op: and [line: %d]\n", t->lineno);
                break;
              case orK:
                printf("Op: or [line: %d]\n", t->lineno);
                break;
              default:
                printf("Error opK not found [line: %d]\n", t->lineno);
                break;
              }
            break;
                                
          case constK:
            switch(t->expType)
              {
              case Void:
                printf("Void ExpType Error [line: %d]\n", t->lineno);
                break;
              case Int:
                printf("Const: %d [line: %d]\n", t->attr.val, t->lineno);
                break;
              case Bool:
                printf("Boolean\n");
                break;
              case Char:
                printf("Const: %s [line: %d]\n", t->attr.string, t->lineno);
               break;
              case True:
                printf("Const: true [line: %d]\n", t->lineno);
                break;
              default:
                printf("Const: false [line: %d]\n", t->lineno);
                break;
              }
            break;
          case idK:
            printf("Id: %s [line: %d]\n", t->attr.name, t->lineno);
            break;
          case assignK:
            switch(t->attr.op)
              {
              case peqK:
                op = (char*)"+=";
                break;
              case meqK:
                op = (char*)"-=";
                break;
              case eqK:
                op = (char*)"=";
                break;
              case ppK:
                op = (char*)"++";
                break;
              case mmK:
                op = (char*)"--";
                break;
              default:
                printf("Error assign");
                break;
              }
            printf("Assign: %s [line: %d]\n", op, t->lineno);
            break;
          case callK:
            printf("Call: %s [line: %d]\n", t->attr.name, t->lineno);
            break;                        
          }                 
      else if(t->nodekind==DeclK)
        switch(t->kind.decl)
          {
          case varK:
            if(t->isArray == true)
              array = (char*)"is array";
            else
              array = (char*)"";
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"bool";
                break;
              case Char:
                type = (char*)"char";
                break;
              }
                        
            printf("Var %s %s of type %s [line: %d]\n", t->attr.name, array, type, t->lineno);
            break;
          case paramK:
            if(t->isArray == true)
              array = (char*)"is array";
            else
              array = (char*)"";
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"boolean";
                break;
              case Char:
                type = (char*)"char";
                break;
              }
            printf("Param %s %s of type %s [line: %d]\n", t->attr.name, array, type, t->lineno);                    
            break;
          case funcK:
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"bool";
                break;
              case Char:
                type = (char*)"char";
                break;
              default:
                type = (char*)"void";
                break;
              }
            printf("Func %s returns type %s [line: %d]\n", t->attr.name, type, t->lineno);
            break;
          }
      else printf("Unknown node kind");
        
      for(i=0; i<MAXCHILDREN; i++)
        {
          if(t->child[i]!=NULL)
            {
              printSpaces();
              printf("Child: %d\n", i+1);
            }
          printTree(t->child[i]);
        }
      if(t->sibling != NULL && indentno != 0)
        {
          UNINDENT;
          printSpaces();
          printf("Sibling: %d\n", sibling);
          sibling++;
          INDENT;
        }
      t = t->sibling;
    } 
  UNINDENT;
}
#endif

int checkErr(TreeNode *t)
{ 
  int i;
  int sibling = 1;
  char* type = NULL;
  char* array = NULL;
  bool check = true;

  treeNode *temp;
  
  int errors = 0;

  //  SymTab s = new SymTab(nodeprint);
  
  while(t != NULL)
    {
      if(t->nodekind==DeclK)
        switch(t->kind.decl)
          {
          case varK:
            if(t->isArray == true)
              array = (char*)"is array";
            else
              array = (char*)"";
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"bool";
                break;
              case Char:
                type = (char*)"char";
                break;
              }
            /*        check = s.insert(t->attr.name, t);
            if (check == false);
            {
              temp = (TreeNode*)(s.lookup(t->attr.name));
              printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", t->lineno, t->attr.name, temp->lineno);
              errors++;
              }*/
            check = true;
            break;
          case paramK:
            if(t->isArray == true)
              array = (char*)"is array";
            else
              array = (char*)"";
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"boolean";
                break;
              case Char:
                type = (char*)"char";
                break;
              }
           
            /*  check = s.insert(t->attr.name, t);
            if (check == false)
              {
                temp = (TreeNode*)(s.lookup(t->attr.name));
                printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", t->lineno, t->attr.name, temp->lineno);
                errors++;
                }*/
            check = true;
            break;
          case funcK:
            switch(t->expType)
              {
              case Int:
                type = (char*)"int";
                break;
              case Bool:
                type = (char*)"bool";
                break;
              case Char:
                type = (char*)"char";
                break;
              default:
                type = (char*)"void";
                break;
              }
            //printf("Func %s returns type %s [line: %d]\n", t->attr.name, type, t->lineno);
            break;
          }
        
      if(t->nodekind==ExpK)
        switch(t->kind.exp)
          {
          case opK:
            switch(t->attr.op)
              {
              case ppK:
                if (t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '++' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                break;
              case mmK:
                if (t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '--' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                break;
              case ltK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '<' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '<' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '<' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '<' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case gtK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '>' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '>' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '>' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '>' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case equivK:
                if (t->child[0]->expType != t->child[1]->expType)
                  {
                    printf("ERROR(%d): '==' requires operands of the same type but lhs is %s and rhs is %s.\n", t->lineno, t->child[0]->expType, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case peqK:
                if (t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '+=' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Int)
                  {
                    printf("ERROR(%d): '+=' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case meqK:
                if (t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '-=' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Int)
                  {
                    printf("ERROR(%d): '-=' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case neqK:
                if (t->child[0]->expType != t->child[1]->expType)
                  {
                    printf("ERROR(%d): '!=' requires operands of the same type but lhs is %s and rhs is %s.\n", t->lineno, t->child[0]->expType, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case modK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '%' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '%' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '%' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '%' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case minusK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '-' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '-' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '-' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '-' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case plusK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '+' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '+' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '+' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '+' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case multiK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                  {
                    printf("ERROR(%d): The operation '*' does not work with arrays.\n", t->lineno);             
                    errors++;
                  }
                    else
                      {
                        printf("ERROR(%d): '*' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '*' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '*' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case divideK:
                if (t->child[0]->expType != Int)
                  {
                    if (t->child[0]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '/' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '/' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                        errors++;
                      }
                  }
                if (t->child[1]->expType != Int)
                  {
                    if (t->child[1]->isArray == true)
                      {
                        printf("ERROR(%d): The operation '/' does not work with arrays.\n", t->lineno);             
                        errors++;
                      }
                    else
                      {
                        printf("ERROR(%d): '/' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                        errors++;
                      }
                  }
                break;
              case lteqK:
                if(t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '<=' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Int)
                  {
                    printf("ERROR(%d): '<=' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case gteqK:
                if(t->child[0]->expType != Int)
                  {
                    printf("ERROR(%d): '>=' requires operands of INT but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Int)
                  {
                    printf("ERROR(%d): '>=' requires operands of INT but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  }
                break;
              case eqK:
                if (t->child[0]->expType != t->child[1]->expType)
                  {
                    printf("ERROR(%d): '=' requires operands of the same type but lhs is %s and rhs is %s.\n", t->lineno, t->child[0]->expType, t->child[1]->expType);             
                    errors++;
                  }
                break;   
              case andK:
                if (t->child[0]->expType != Bool)
                  {
                    printf("ERROR(%d): 'and' requires operands of 'BOOL' but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Bool)
                  {
                    printf("ERROR(%d): 'and' requires operands of 'BOOL' but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  } 
                break;
              case orK:
                if (t->child[0]->expType != Bool)
                  {
                    printf("ERROR(%d): 'or' requires operands of 'BOOL' but lhs is of %s.\n", t->lineno, t->child[0]->expType);             
                    errors++;
                  }
                else if (t->child[1]->expType != Bool)
                  {
                    printf("ERROR(%d): 'or' requires operands of 'BOOL' but rhs is of %s.\n", t->lineno, t->child[1]->expType);             
                    errors++;
                  } 
                break;
              }
            break;
         
            
            if(t->nodekind==StmtK)
              switch(t->kind.stmt)
                {
                case ifK:
                  if (t->child[0]->expType == Int)
                    {
                      printf("ERROR(%d): Expecting Boolean test condition in 'if' statement but got %s.\n", t->lineno, t->child[0]->attr.op);
                      errors++;
                    }
                  break;
                case returnK:
                  //printf("Return [line: %d]\n", t->lineno);
                  break;
                case compoundK:
                  //printf("Compound [line: %d]\n", t->lineno);
                  break;
                case breakK:
                  //printf("Break [line: %d]\n", t->lineno);
                  break;
                case foreachK:
                  if (t->child[0]->kind.exp != idK)
                    {  
                      printf("ERROR(%d): 'Foreach' requires a left-hand operand of type 'ID', but lhs is of %s.\n", t->lineno, t->child[0]->kind.exp);
                      errors++;
                    }
                  else if (t->child[1]->nodekind != ExpK)
                    {
                      printf("Error(%d): 'Foreach' requires an expression as a right-hand operand, but rhs is of %s.\n", t->lineno, t->child[1]->nodekind);
                      errors++;
                    }
                  break;
                case whileK:
                  if (t->child[0]->expType == Int)
                    {
                      printf("ERROR(%d): Expecting Boolean test condition in 'while' statement but got %s.\n", t->lineno, t->child[0]->attr.op);
                      errors++;
                    }
                  break;
                }
            
          }
      
      for(i=0; i<MAXCHILDREN; i++)
        {
          checkErr(t->child[i]);
        }
      if(t->sibling != NULL)
        sibling++;
      t = t->sibling;
     
    }
  return errors;
}
 
void nodePrint(void *p)
{
  printf("test");
}

void printSpaces()
{
  int i;
  for(i=0; i<indentno; i++)
    printf("|   ");
}
