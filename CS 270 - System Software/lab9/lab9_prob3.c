#include <fcntl.h>

int main(int argc, char **argv)
{
  char temp[100];
  
  int fd = open("/proc/cpuinfo", O_RDONLY);

  if (fd == -1)
    exit (-1);

  int n = read(fd, temp, 100);

  system("sudo");

  printf("%s\n,temp");

  return 0;
}
