#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char ** argv)
{
  struct stat fileStat;
  DIR *dp;
  struct dirent *dirp;
  char * perms;
 
  if(argc != 2)
    {
      perror("Not enough arguments\n");
      exit(-1);
      
    }// end if
  
  if( (dp = opendir(argv[1])) == NULL)
    perror("Could not open directory\n");

  if(stat(argv[1],&fileStat) < 0)
    return 1;

  dirp = readdir(dp);
  dirp = readdir(dp);

  while((dirp = readdir(dp)) != NULL)
    {
      stat(dirp->d_name,&fileStat);
      printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
      printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
      printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
      printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
      printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
      printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
      printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
      printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
      printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
      printf((fileStat.st_mode & S_IXOTH) ? "x " : "- ");
      printf("%d ",fileStat.st_uid);
      printf("%d ",fileStat.st_gid);
      printf("%d ",fileStat.st_size);
      printf("%d ",fileStat.st_ctime);
      printf("%s\n", dirp->d_name);
    }
  
  return 0;
  
}// end main

