#include <mySimpleComputer.h>
#include <myTerm.h>

int
cacheCheck (int instruction)
{
  CACHE *tmp = &cache[0];
  for (int i = 0; i < 5; i++)
    {
      if (cache[i].c_uses < tmp->c_uses)
        {
          tmp = &cache[i];
        }
      for (int j = 0; j < 10; j++)
        {
          if (cache[i].c_line[j] == instruction)
            {
              cache[i].c_uses += 1;
              return 0;
            }
        }
    }
  mt_gotoXY (0, 26);
  printf ("cacheload [%d]", ICount / 10);
  cacheLoad (tmp);
  return 1;
}