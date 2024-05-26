#include "console.h"
void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  printf ("sign = %d\n command = %d\n operand = %d\n", *sign, *command,
          *operand);
  return;
}