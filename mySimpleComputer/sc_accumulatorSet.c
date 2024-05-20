#include "../include/mySimpleComputer.h"
int
sc_accumulatorSet (int value)
{
  if (value > 127 || value < -127)
    return -1;
  else
    {
      Accum = value;
      return 0;
    }
}