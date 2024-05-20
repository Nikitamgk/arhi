#include "../include/mySimpleComputer.h"
int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  int temp = 0;
  for (int i = 0; i <= 40; i++)
    {
      if (command == commands[i])
        temp = 1;
    }
  if (temp = 0)
    return -1;
  if (sign >= 1 || sign < 0 || operand > 127 || operand < 0)
    return -1;
  else
    {
      int new_comm = 0;
      new_comm = new_comm | command;
      new_comm = new_comm << 7;
      new_comm = new_comm | operand;
      *value = new_comm;
      return 0;
    }
}