/* Colby Rush, CS240. Shell program with alias, path extension, history ability, etc  3/30/12 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

char **args;
pid_t process;
char history[1000][50];
char aliases[50][50];
char aliaslist[50][50];

void clearit(char tmp[50])
{
  memset(tmp, '\0', 50);
}

int makehistory(char tmp[50])
{
  FILE * fFile;
  int i;
  char Htmp[50];
  for (i = 0; i < 50; i++) // copy tmp into Htmp so tmp isn't altered at all
    Htmp[i] = tmp[i];
  int historyCount = 0;

  fFile = fopen ("history.txt", "a+"); // this block creates the file, while also making sure even 'history' shows up in history
  if (fFile == NULL)
    fFile = fopen ("history.txt", "a+");
  strcat(Htmp, "\n"); 
  fputs(Htmp, fFile);
  fclose(fFile); // close file to reset file pointer

  fFile = fopen ("history.txt", "r+");
  while (fgets (history[historyCount], 50, fFile) != NULL) // keep copying contents of history into array
    {
      if (historyCount > 999) // just in case history gets too big
        {
          memset(history, '\0', sizeof(history));
          historyCount = 0;
        }
      else
        historyCount++;
    }
  fclose (fFile);
  return historyCount; // return history count for print loop
}

int makealias(int z, char aliases[50][50], char aliaslist[50][50], char tmp[50], char **args)
{
  int g = 2;
  char aTmp[50];
  strcpy (aliases[z], args[1]);//make a placement in the list of aliases for the new command
  while (args[g] != NULL)
    {
      strcat(aTmp, args[g]); //adds each chunk onto tmp to make it a whole string
      strcat(aTmp, " "); //space for the make args
      g++;
    }  
  aTmp[strlen(aTmp)-1] = '\0';
  strcpy (aliaslist[z], aTmp); //copies tmp as whole string instead of chunks so makeargs can be run on it
  strcat (aliaslist[z], "\0");
}

int removealias(int z, char aliases[50][50], char aliaslist[50][50])
{
  memset(aliases[z], '\0', sizeof(aliases[z])); //just zeroes out the places the information used to be
  memset(aliaslist[z], '\0', sizeof(aliaslist[z]));
}


int makeargs(char tmp[50], char **args)
{
  int argCount = 0;
  int j = 0;
  int i = 0;
  char *token = (char*)malloc(10*sizeof(char)); // allocate token memory
  char seps[] = " =':";   // allocate token seperators         
  
  for (i = 0; i < 50; i ++) //loop to compare args to alias list
    {
      if (strcmp (tmp, aliases[i]) == 0) //if args matches an alias
        {
          clearit(tmp);
          strcpy (tmp, aliaslist[i]);
        }
    }

  token = strtok(tmp,seps);      // split tmp into tokens for args array
  while (token != NULL)
    {         
      argCount++;
      strcat(token, "\0"); //end token in NULL
      strcpy(args[j], token); //copy tokens into args
      j++;
      token = strtok(NULL, seps);
    }
  args[j] = NULL; 
  return argCount;
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

void pipeit(int pipeArg, char **args, int argCount)
{
  int pipefd[2]; //file descriptors
  int p;
  int q = 0;
  char **Targs;
  Targs = (char**)malloc(10*sizeof(char*)); //allocate arg memory
  int j = 0; // mem allocation loop
  for (j = 0; j < 10; j++)
    Targs[j] = (char*)malloc(10*sizeof(char));

  for (p = pipeArg+1; p < argCount; p++)
    {
      strcpy(Targs[q],args[p]);
      strcat(Targs[q], "\0");
      q++;
    }
  args[pipeArg] = NULL; //NULL's out both lists
  Targs[q] = NULL;

  if (pipe(pipefd))
    {
      perror("pipe");
      exit(1);
    }
  
  switch (fork())
    {
    case -1:
      perror("fork"); //error check
      exit(1);
    case 0: //child that redirects and closes wrong side of pipe
      close(pipefd[0]);
      dup2(pipefd[1], 1); //automatically closes previous fd
      close(pipefd[1]); //cleanup
      execvp(args[0],args);
      perror("execvp");
    default: //parent, default to make sure this is the last thing that happens
      close(pipefd[1]);
      dup2(pipefd[0], 0); //closes fd 0
      close(pipefd[0]);
      execvp(Targs[0],Targs);
      perror("execvp");
    }
  wait();
}

void runit(pid_t process, char **args, int historyCount)
{
  int i;
  int r;
  if (strcmp (args[0], "history") == 0) //check for history command
    {
      for (r = 1; r <= historyCount; r++)
        printf("%d: %s", r, history[r-1]);
    }
  else if (process == 0)
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

void startup() // basically regular input in main, just modified to handle file input with fgetc instead of getc
{
  printf("Starting up...\n");

  int x = -1;
  int i = 0;
  char com;
  char tmp[50];
  int historyCount = 0;
  memset(tmp, '0', 50); //erase tmp array
  const char exit[] = "exit"; 
  int r;
  char *envValue;


  FILE * pFile;
  pFile = fopen (".nshsrc","r");
  if (pFile == NULL)
    perror ("Error opening file\n");
  else
    {            
      while (com != EOF)
        {
          envValue = getenv("PATH");

          char **args;
          args = (char**)malloc(10*sizeof(char*)); //allocate arg memory
          int j = 0;
          for (j = 0; j < 10; j++)
            args[j] = (char*)malloc(10*sizeof(char));
          for (i = 0; i < 50; i++)
            {
              com = (char)fgetc(pFile); //integer return             
              if (com == '\n' || com == EOF)
                {
                  tmp[i] = '\0'; // if carriage return or EOF, ends while loop automatically
                  break;
                }
              else
                tmp[i] = com; //copies com to tmp
            }
          if (tmp[0] != '\0') // if no command is given
            {
              makeargs(tmp, args);
              if (strcmp (args[0], exit) == 0) //check for exit command
                break;
              else if (strcmp (args[0], "PATH") == 0 && strcmp(args[1], "$PATH:") == 0) //check for path extension
                {
                  int envCheck;
                  envCheck = setenv(args[2], envValue, 0); //changes value of env variable
                  if (envCheck != 0)
                    {
                      perror("Setenv");
                      break;
                    }
                  clearit(tmp);
                } 
              else
                {
                  forkit();
                  runit(process, args, historyCount);
                  clearit(tmp); // clears tmp for next command
                }
            }
        }
      fclose (pFile);
    }
}


int main(int argc, char **argv)
{
  
  startup(); // run commands in the .nshsrc
  int x = -1; //bash run loop
  int i = 0; // com into tmp loop
  char com;
  char tmp[50];
  memset(tmp, '0', 50); //erase tmp array
  int historyCount;
  int r;
  int u;
  int z = 0; //alias scroll
  int d = 0; //pipe check
  int pipeArg = 0;
  int pid;
  int aliasCount = 0;
  int argCount;
  char *envValue;

  while (x < 1)
    {     
      argCount = 0;
      envValue = getenv("PATH");
      printf("?:");            
      char **args;      

      args = (char**)malloc(10*sizeof(char*)); //allocate arg memory
      int j = 0; // mem allocation loop
      for (j = 0; j < 10; j++)
        args[j] = (char*)malloc(10*sizeof(char));
      
      for (i = 0; i < 50; i++)
        {
          com = (char)getchar(); //integer return
          
          if (com == '\n')
            {
              tmp[i] = '\0'; // if carriage return, ends for loop automatically
              break;
            }
          else
            tmp[i] = com; //copies com to tmp
        }
      
      if (tmp[0] != '\0') // if a command is given
        {
          historyCount = makehistory(tmp); // create or get current history of shell
          argCount = makeargs(tmp,args);
        }        

      for (i = 0; i < argCount; i++) //check for pipe command
        {
          if (strcmp (args[i], "|") == 0) //search args for |
            {
              pipeArg = i; //give number of arg the pipe is for later reference
              fflush(stdout);
              switch ((pid = fork()))
                {
                case -1:
                  perror("fork");
                  break;
                case 0:
                  pipeit(pipeArg, args, argCount);
                  break;
                default:
                  wait();
                }
              d = 1;
            }
        }


      if (d == 1)
        d = 0;
      else if (strcmp (args[0], "alias") == 0) //check for alias
        {
          if (args[1] == NULL)
            {
              int b = 0;
              if (aliasCount == 0)
                printf("No aliases present.\n");
              else
                for (b = 0; b < aliasCount; b++)
                  printf("%s = '%s'\n", aliases[b], aliaslist[b]);
            }
          else
            {
              int o = 0;
              for (i = 0; i < 50; i++)
                if (strcmp (args[1], aliases[i]) == 0)
                  o = 1; //if alias is found
              if (o != 0)
                printf("Alias already used.\n");
              else
                {
                  makealias(z,aliases,aliaslist,tmp, args);
                  clearit(tmp);
                  aliasCount++;
                  z++; //move list down one to new spot
                }
            }
        }
      else if (strcmp (args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
        printf("%s\n", envValue);
      else if (strcmp (args[0], "unalias") == 0) //check for unalias
        {
          int k = 0;
          for (i = 0; i < 50; i++)
            if (strcmp (args[1], aliases[i]) == 0)
              k = 1; //if alias is found
          if (k == 0) //if alias is not found
            printf("Alias not used.\n");
          else
            {
              z--; //move alias up to take previous spot
              removealias(z,aliases,aliaslist);
              aliasCount--;
              clearit(tmp);
            }
        }
      else if (strcmp (args[0], "exit") == 0) //check for exit command
        return 1;
      else if (strcmp (args[0], "PATH") == 0 && strcmp(args[1], "$PATH") == 0)//check for path extension
        {
          int envCheck;
          envCheck = setenv(args[2], envValue, 0); //changes value of env variable
          if (envCheck != 0)
            {
              perror("Setenv");
              break;
            }
          clearit(tmp);
        }
      else if (strcmp (args[0], "history") == 0) //check for history command
        {
          for (r = 1; r <= historyCount; r++)
            printf("%d: %s", r, history[r-1]);
        }
      else if (strcmp (args[0], "!!") == 0) // check for !! command
        {
          clearit(tmp); //clears current tmp
          strcpy (tmp, history[historyCount-3]);
          tmp[strlen(tmp)-1] = '\0'; //makes sure tmp ends in NULL and not \n
          argCount = makeargs(tmp, args);
          forkit();
          runit(process, args, historyCount);
          clearit(tmp);
        }
      else if (strncmp (args[0], "!", 1) == 0) //check for !# command
        {
          clearit(tmp);
          int histnum;
          for (r = 0; r < 48; r++)
            args[0][r] = args[0][r+1]; //removes the ! so atoi works
          histnum = atoi(args[0]); //converts string to number
          if (histnum > historyCount)
            printf ("History not found.\n");
          else
            {
              strcpy (tmp, history[histnum-1]); //copies previous history into tmp
              tmp[strlen(tmp)-1] = '\0'; //makes tmp end in NULL
              argCount = makeargs(tmp, args);
              forkit();
              runit(process, args, historyCount);
              clearit(tmp);
            } 
        }
      else
        {
          forkit();
          runit(process, args, historyCount);
          clearit(tmp); // clears tmp for next command
        }
    }
  return 0;
}
