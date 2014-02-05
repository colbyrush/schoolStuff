#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
  int i;
  int count = atoi(argv[2]);
  int time = atoi(argv[1]);
  int pid;
  sleep(time);
  pid = getpid();

  for (i = 1; i <= count; i++)
    printf("Executing processes, process id %d, iteration number %d\n", pid, i);

  return 0;
  
}// end main

