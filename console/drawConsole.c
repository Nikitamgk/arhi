#include "console.h"
void
drawConsole ()
{
  int rows, cols;
  mt_getscreensize (&rows, &cols);
  if (cols < 90 || rows < 26)
    return -1;
  generateFont ();
  FILE *file = fopen ("font.bin", "rb");
  int read_result;
  bc_bigcharread (fileno (file), (int *)font, 18, &read_result);
  fclose (file);
  sc_MemoryInit ();
  mt_clrscrn ();
  printMemory ();
  printAccumulator ();
  printCounters ();
  printFlags ();
  printDecodedCommand (memory[0]);
  printCommand ();
  printBigCell (memory[1], 65, 9);
  printKeys ();
  printTerm (0, 0);
}