#include "console.h"
void
printAccumulator ()
{
  int Col, Row;
  mt_getscreensize (&Row, &Col);
  mt_gotoXY (62, 1);
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (Accum, sign, command, operand);
  if (*sign == 0)
    printf ("+");
  else
    printf ("-");
  printf ("sc: %02d%02d ", *command, *operand);
  printf ("hex:%04X ", Accum);
  return;
}