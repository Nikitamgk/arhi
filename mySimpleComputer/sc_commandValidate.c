#include "../include/mySimpleComputer.h"
int
sc_commandValidate (int command)
{
  int temp = command;
  command = command << 1;
  command = command >> 8;
  for (int i = 0; i <= 40; i++)
    {
      if (command == commands[i])
        {
          command = temp;
          return 1;
        }
    }
  command = temp;
  return 0;
}