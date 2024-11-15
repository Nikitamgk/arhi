#include <myBigChars.h>

int
bc_printbigchar (int *big, int x, int y, enum Colors fg, enum Colors bg)
{
  int maxx, maxy;
  int bit;
  int i, j;
  char row[9];
  mt_getscreensize (&maxy, &maxx);
  if ((x < 0) || (y < 0) || (x + 8 > maxx) || (y + 8 > maxy))
    return -1;
  row[8] = '\0';
  if (fg != BLACK)
    mt_setfgcolor (fg);
  if (bg != BLACK)
    mt_setbgcolor (bg);
  for (i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
        {
          bc_getbigcharpos (big, j, i, &bit);
          if (!bit)
            row[j] = ' ';
          else
            row[j] = BOXCHAR_REC;
        }
      mt_gotoXY (x, y + i);
      bc_printA (row);
    }
  mt_setdefaultcolor ();
  return 0;
}