#include <mySimpleComputer.h>
int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (value & ~0x7FFF)
    return -1; // биты, не соответствующие формату команды
  *sign = (value & 0x4000) ? 1 : 0;
  *command = (value & 0x3F80) >> 7;
  *operand = value & 0x007F;
  return 0;
}