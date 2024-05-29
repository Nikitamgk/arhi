#include "console.h"
#include <locale.h>
#include <signal.h>

int
main (int argv, char *argc[])
{
  if (consoleInitial (argv, argc))
    return 1;
  FILE *file = fopen ("font.bin", "rb");
  int read_result;
  bc_bigcharread (fileno (file), (int *)font, 18, &read_result);
  fclose (file);

  mt_clrscrn ();

  // Инициализация памяти, регистров и аккумулятора
  sc_MemoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

  sc_regInit ();

  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);

  rk_mytermsave ();
  enum keys key;
  while (key != KEY_ESC)
    {
      drawConsole ();
      rk_readkey (&key);
      handleKeypress (&key);
      alarm (1);
      sleep (0.01);
    }
  return 0;
}