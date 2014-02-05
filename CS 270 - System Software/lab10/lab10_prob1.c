// Colby Rush

#include <stdio.h>
#include <stdint.h>

int main(int argc, char ** argv)
{
	char var1 = 1;
	unsigned char var2 = 1;
	unsigned char total = 0;

	uint8_t var3 = -1;

	char bothered = -1;
	unsigned char notBothered = -1;

	printf("sizeof signed char (var1): %d\n", sizeof(var1));
	printf("sizeof unsigned char (var2): %d\n", sizeof(var2));
	printf("sizeof uint8_t (var3): %d\n", sizeof(var3)); 
	printf("\n");
	
	printf("value of var1: 0x%x\n", var1);
	printf("value of var2: 0x%x\n", var2);
	printf("value of var3: 0x%x\n", var3);
	
	
	printf("\n");
	
	printf("sizeof a char: %d\nvar2", sizeof(bothered));
	printf("sizeof unsigned char: %d\n", sizeof(notBothered));
	printf("value of bothered: 0x%x\n", bothered);
	printf("value of notBothered: 0x%x\n", notBothered);
	
	/* 
	 * The output of bothered as compared to notBothered bothers me
	 * explain in a comment here why bothered bothers me
	 * Hint look at the size compared to the outputprintf("Taking the lower 4 bits of 0x%x and moving them to the upper 4 bits of total\n", var2);
	 * Put your explanation here

         Bothered is a much larger size to store, as shown by the higher hex number output when it is outbut. Unsigned apparently makes the size huge on memory to store.

	 */
	
	
	
	
	/* 
	 * The following code is just so you can see what is happening with
	 * the bitwise operators.  You don't have to do anything for this section
	 */
	printf("\n");
	printf("var1 | var1 bitwise or (both signed) 0x%x\n", var1 | var1);
	printf("var1 | var2 bitwise or (one signed one unsigned) 0x%x\n", var1 | var2);
	printf("var1 & var2 bitwise and (one signed one unsigned) 0x%x\n", var1 & var2);
	printf("~var1: 0x%x\n", ~var1);
	printf("var2 >> 2: 0x%x\n", var2 >> 2);
	printf("var1 << 2: 0x%x\n", var1 << 2);
	printf("var1 ^= var3: 0x%x\n", var1 ^= var3);
	var1 <<= 4;
	printf("var1 <<= 4: 0x%x\n", var1);
	printf("\n");
	
	/*
	 * For this section explain what the ^= does
	 * and explain why this is the preferred way over
	 * use of a temp varaible
	 * Put your explanation here

         ^= swaps the values of var1 and var3, making temp variables obsolete for swapping variable amounts.

	 */
	
	var2 = 0xf0;
	var3 = 0x2f;
	
	printf("Before XOR\n");
	printf("var2: 0x%x\n", var2);
	printf("var3: 0x%x\n", var3);

	var2 ^= var3;
	var3 ^= var2;
	var2 ^= var3;

	printf("\n");
	
	printf("After XOR\n");
	printf("var2: 0x%x\n", var2);
	printf("var3: 0x%x\n", var3);

	printf("\n");
	
	/*
	 * Your tasks are:
	 * a) is bit 6 in var2 set?  Write the code to determine
	 * b) using total and var2 take the lower 4 bits (nibble) from var2 and 
	 *    make them the upper 4 bits of total.  
	 * c) using total and var3 take the upper 4 bits from var3 and 
	 *    make them the lower 4 bits of total - the upper bits should be
	 *    unchanged.
	 * 
	 *    Example: The user enters a character that is equivalent to 0xfa for var2.
	 *             The user enters a character that is equivalent to 0x2d.for var3.
	 *             Total when complete should contain 0xa2
	 */
	
	printf("Please enter a character ");
	var2 = getchar();printf("Taking the lower 4 bits of 0x%x and moving them to the upper 4 bits of total\n", var2);
	getchar(); // pesky carriage return
	
	printf("Please enter a character ");
	scanf("%c", &var3);
	
	printf("var2: 0x%x\n", var2);
	printf("var3: 0x%x\n", var3);
	
	/* your code for determining if bit 6 is set goes within the if */
	if((var2) & (1 <<(6)))
	  printf("Bit 6 IS set\n");
	
	else
	  printf("Bit 6 IS NOT set\n");
	
	/* your code to move the lower 4 bits of var2 and make them the upper 4 bits of total goes here */
	printf("Taking the lower 4 bits of 0x%x and moving them to the upper 4 bits of total\n", var2);
        var2 << 4;
	
	printf("total: 0x%x\n", total);
	
	
	/* your code to move the upper 4 bits of var3 and make them the lower 4 bits of total goes here */
	printf("Taking the upper 4 bits of 0x%x and moving them to the lower 4 bits of total\n", var3);
	var3 >> 4;
	
	printf("total: 0x%x\n", total);
	
	return 0;

}// end main

