#include "../include/mySimpleComputer.h"
int
sc_MemoryLoad (char *filename)
{
  FILE *fs;
  if ((fs == fopen (filename, "r+")) == NULL)
    return -1;
  else
    {
      fread (&memory[0], sizeof (int), 127, fs);
      return 0;
    }
}