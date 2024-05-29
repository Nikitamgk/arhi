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
  printBigCell (memory[ICount], 65, 9);
  setlocale (LC_ALL, ".UTF-8");
  bc_box (61, 7, 114, 18, 7, 0, "Редактируемая ячейка (увеличенно)", 1, 0);
  printKeys ();
  printTerm (0, 0);
}