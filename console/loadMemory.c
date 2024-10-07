#include "console.h"
int
loadMemory ()
{
  char filename[20];
  printf ("Enter load file name: ");
  fgets (filename, 20, stdin);
  mt_clrscrn ();
  mt_gotoXY (1, 27);
  filename[strlen (filename) - 1] = '\0';
  if (sc_MemoryLoad (filename))
    {
      printf ("\nFailed to load memory               ");
      return -1;
    }
  else
    {
      printf ("\nSuuccessful load memory             ");
    }
  return 0;
}
