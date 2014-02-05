#include <stdlib.h>

int write(int fd, char *str, int len)
{
  return 0;
}

int syscall(int n, int q, char *str, int len)
{
  asm("mov %0, %%ecx\n"
      "mov $1, %%ebx\n"
      "mov $8, %%edx\n"
      "mov $4, %%eax\n"
      "int $0x80\n"
      : "r" ("goodbye\n")
      );
}

int main(int argc, char **argv)
{
  write(1, "hello\n",6);
  syscall(1,1, "goodbye\n", 8);
  exit(0);
}


/* a) It doesn't do anything because the function declaration overwrites the built-in frunction called write.
   b) Because syscall does the same as write, it just isn't overwritten since it has a different function call.
   c) It doesn't work because the syscall wasn't configured for 32 bit mode, only 64 bit. So the syscall isn't called.
   d) It would work if it was compiled in 64 bit mode.
   e) Because syscall is overwritten by the function declaration just like write was earlier.
   f) Goodbye is back because it stores the message into the locations specified by the function asm and reads it from there.
   g) C functions could interfere, but theres a really small chance it would because not only is it a really obscure name for a function, but the specifications are so bizzare it would probably error and point you to the problem.

 */
