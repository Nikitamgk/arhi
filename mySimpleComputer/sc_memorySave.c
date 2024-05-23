#include "main.c"
int
sc_MemorySave (char *filename)
{
  FILE *fp;
  if ((fp == fopen (filename, "r+")) == NULL)
    return -1;
  else
    {
      fwrite (&memory[0], sizeof (int), 127, fp);
      return 0;
    }
}