#include <console.h>
int main()
{
	int rows, cols;
	mt_getscreensize(&rows, &cols);
	if (cols < 90 || rows < 26)
		return -1;
  sc_MemoryInit();
  mt_clrscrn();
  for(int f = 0; f < 128; f++)
  {
      sc_MemorySet(f,rand()%127);
      printCell(f, 0, 0);
  }
  printAccumulator();
  printCounters();
  printFlags();
  printDecodedCommand(memory[0]);
  printCommand();
  for(int t = 0; t < 7; t++)
  {
  int new_adr = rand()%10;
  printTerm(new_adr,1);
  }
  mt_clrscrn();
  for(int f = 0; f < 128; f++)
  {
      printCell(f, 0, 0);
  }
  printAccumulator();
  printCounters();
  printFlags();
  printDecodedCommand(memory[0]);
  printCommand();
  printTerm(0,0);
  mt_gotoXY(100, 25);
  return 0;
}