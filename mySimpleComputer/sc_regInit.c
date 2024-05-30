#include <mySimpleComputer.h>
int
sc_regInit ()
{
  flags = 0;
  flags = flags | IT_MASK;
  return 0;
}
