#include "main.c"
int
sc_regGet (int registr, int *value)
{
  if (value == NULL || registr > 2 || registr < 0)
    return -1;
  else
    {
      int temp = flags;
      temp << 15 - registr;
      temp >> 15 + registr;
      *value = temp;
      return 0;
    }
}