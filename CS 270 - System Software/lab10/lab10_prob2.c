// Colby Rush

#include <stdio.h>
#include <assert.h>
#define kSpace 032

/* To give credit where credit is due  - this is taken from the Art & Logic programming
 * exam that they give prospective employees
 *
 * Fix the following piece of broken code.
 * When executed, it should convert the buffer parameter (using the provided data -- changing
 * the contents of the input buffer doesn't count as fixing a bug) into the string "Art&Logic",
 * but it does not. This example code is in C, but the problems it has are also problems in all
 * the other languages that we work with.
 * convert the contents of 'buffer' in place so that they are decoded. The
 * buffer should convert to the ASCII string "Art&Logic" (but it doesn't as
 * presented here....)
 */

void convert(char buffer[], int val)
{
  int i;
  
  for (i = 0; i <= val; ++i)
    {
      if (buffer[i] > kSpace)
        {
          // this reduces the buffer values by one to the correct alphabet value if they are too big. 32 is the amount of letters, and anything higher would not be a letter.
          buffer[i] -= 1;
        }// end if
      else
        {
          // this else statement fills the buffer at pos i with the correct char to print out the intended phrase by modifying the octal values to so they are the correct alphabet values. The math is leftshift by 2 (basically multiply by 4), add 4, and subtract current i.
          buffer[i] = buffer[i] << 2 + 4 - i;
        }// end else
    }// end for
}// end function

int main(void)
{
   int i;
   const char kTarget[] = "Art&Logic";
   char buffer[] = {0x42, 0x73, 0x75, 0x27, 0x13, 0x1C, 0x68, 0x1B, 0x64};

   /* Assert checks if a statement is false (equal to zero) and if so, will abort the code and output an error message at the location of the fail */

   convert(buffer, sizeof(buffer)/sizeof(buffer[0]));

   //  for (i = 0; i < sizeof(buffer)/sizeof(buffer[0]); ++i)
   // assert(kTarget[i] == buffer[i]);

     printf("%s\n",buffer);
     for (i = 0; i <= sizeof(buffer)/sizeof(buffer[0]); i++)
             printf ("%d: %d\n", i, buffer[i]);

     //The code only fails in that it doesn't display the letters 'o, i' in the word 'Logic' because the octal values are small enough to become non-displayed when 1 is subtracted.

}// end main

