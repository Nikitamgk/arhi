#include "console.h"
#include <locale.h>
void
drawConsole ()
{
  mt_clrscrn ();
  printMemory ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[ICount]);
  printCommand ();
  setlocale (LC_ALL, ".UTF-8");
  bc_box (62, 7, 114, 18, 7, 0, "Редактируемая ячейка (увеличенно)", 1, 0);
  setlocale (LC_ALL, "");
  printBigCell (memory[ICount], 65, 9);
  printKeys ();
  printTerm (0, 0);
}