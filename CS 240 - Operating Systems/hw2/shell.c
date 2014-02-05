#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

char **args;
pid_t process;
 
void clearit(char tmp[50], char **args)
{
  memset(tmp, '\0', 50);
}


void makeargs(char tmp[50], char **args)
{
  int q = 0;
  int j = 0;
  char *token = (char*)malloc(20*sizeof(char)); // allocate token memory
  char seps[] = " ";   // allocate token seperators
  token = strtok(tmp,seps);      // split tmp into tokens for args array
  while (token != NULL)
    {         
      token[(sizeof(token))] = '\0';
      strcpy(args[q], token); //copy tokens into args
      q++;
      token = strtok(NULL, seps);
    }
  args[q] = NULL; 
}

void forkit()
{
  process = 0;
  process = fork(); //forks program

  if (process < 0) // checks for fork error
    {
      perror("fork");
      exit(1);
    }
}

void runit(char tmp[50], pid_t process, char **args)
{
  int i = 0;
    if (process == 0)
    {
      i = execvp(args[0],args); //run command
      if (i == -1)
        {
          printf("Command not found.\n");
          exit(1);
        }
      else
        exit(0);
    }
    wait(); // kill all zombie processes
}

int main(int argc, char **argv)
{
  
  int x = -1;
  int i = 0;
  int d = 0;
  char com;
  char tmp[50];
  memset(tmp, '0', 50); //erase tmp array
  const char exit[] = "exit";  
  
  while (x < 1)
    {      
      printf("?:");      
      
      char **args;
      args = (char**)malloc(10*sizeof(char*)); //allocate arg memory
      int j = 0;
      for (j = 0; j < 10; j++)
        args[j] = (char*)malloc(10*sizeof(char));
      

      for (i = 0; i < 50; i++)
        {
          com = (char)getchar(); //son a bitching integer return
          
          if (com == '\n')
            {
              tmp[i] = '\0'; // if carriage return, ends for loop automatically
              break;
            }
          else
            tmp[i] = com; //copies com to tmp
        }
      makeargs(tmp, args);
      if (strncmp (args[0], exit, 4) == 0) //check for exit command
        break;
      forkit();
      runit(tmp, process, args);
      clearit(tmp, args); // clears tmp for next command
    }
  return 0;
}
