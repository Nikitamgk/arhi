#include "console.h"
#include "test.c"

void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  printf ("sign = %d\n command = %d\n operand = %d\n", *sign, *command, *operand);
}

void
printFlags ()
{
    printf("Flag 0 is: %s \n", (flags&IT_MASK)== IT_MASK ? "I" : "_");
    printf("Flag 1 is: %s \n", (flags&MC_MASK)== MC_MASK ? "M" : "_");
    printf("Flag 2 is: %s \n", (flags&SF_MASK)== SF_MASK ? "S" : "_");
    printf("Flag 3 is: %s \n", (flags&ZD_MASK)== ZD_MASK ? "Z" : "_");
    printf("Flag 4 is: %s \n", (flags&OO_MASK)== OO_MASK ? "O" : "_");
}


void
printAccumulator ()
{
	printf ("Accumulator = %d \n", Accum);
}

void
printCounters ()
{
	printf ("Counter = %d \n", ICount);
}