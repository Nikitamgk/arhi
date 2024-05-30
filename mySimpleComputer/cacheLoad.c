#include <mySimpleComputer.h>

void
cacheLoad (CACHE *changed)
{
  changed->c_number = ICount / 10;
  changed->c_uses = 0;
  for (int i = 0; i < 10; i++)
    {
      changed->c_line[i] = memory[(ICount / 10) * 10 + i];
    }
}