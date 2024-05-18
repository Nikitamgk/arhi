#include "console.h"

void printCell (int address, enum Colors fg, enum Colors bg)
{
  int Col, Row;
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  mt_getscreensize(&Row, &Col);
  mt_gotoXY(1+address%10, 1+address%13);
  mt_setfgcolor(fg);
  mt_setbgcolor(bg);
  if(*sign == 0)
    printf("+");
  else
    printf("-");
  printf("%d%d ", *command, *operand);
  mt_setdefaultcolor();
  return;
}

void printFlags ()
{
  int Col, Row;
  mt_getscreensize(&Row, &Col);
  mt_gotoXY(82, 1);
  printf("%s", (flags&IT_MASK)== IT_MASK ? "I " : "_ ");
  printf("%s", (flags&MC_MASK)== MC_MASK ? "M " : "_ ");
  printf("%s", (flags&SF_MASK)== SF_MASK ? "S " : "_ ");
  printf("%s", (flags&ZD_MASK)== ZD_MASK ? "Z " : "_ ");
  printf("%s", (flags&OO_MASK)== OO_MASK ? "O " : "_ ");
  return;
}

void printAccumulator ()
{
  int Col, Row;
  mt_getscreensize(&Row, &Col);
  mt_gotoXY(2, Row-32);
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (Accum, sign, command, operand);
  if(*sign == 0)
    printf("+");
  else
    printf("-");
  printf("%d%d ", *command, *operand);
  return;
  printf("%4X", Accum);
}

void printCounters ()
{
  int Col, Row;
  mt_getscreensize(&Row, &Col);
  mt_gotoXY(5, Row-32);
  printf("%4X", ICount);
  return;
}

void printTerm()
{
  
}