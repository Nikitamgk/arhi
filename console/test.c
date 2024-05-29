#include "console.h"
#include <locale.h>
#include <signal.h>

int
main (int argv, char *argc[])
{
  if (consoleInitial (argv, argc))
    return 1;
  mt_clrscrn ();

  // Инициализация памяти, регистров и аккумулятора
  sc_MemoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  //                 0=======-------
  sc_MemorySet (0, 0b001000000001010);
  // загружаем ячейку 10 в аккумулятор
  sc_MemorySet (1, 0b001100000001011);
  // складываем значение аккумулятора с 11 ячейкой
  sc_MemorySet (2, 0b001100010001100);
  // вычитаем из аккумулятора с 12 ячейку
  sc_MemorySet (3, 0b001000010001101);
  // выгружаем из аккумулятора значение в 13 ячейку
  sc_MemorySet (4, 0b011000000001101);
  // логический двоичный сдвиг влево ячейки 13 [CHL]
  sc_MemorySet (5, 0b001000010001110);
  // выгружаем из аккумулятора значение в 14 ячейку
  sc_MemorySet (6, 0b010101010001101);
  // переход на 14 ячейку если в аккумуляторе
  // положительное число [JNS]

  sc_MemorySet (10, 2);
  sc_MemorySet (11, 2);
  sc_MemorySet (12, 6);

  // ожидаемый результат 13 ячейки: 25 + 125 - 50 = 100 (0x64)
  // ожидаемый результат 14 ячейки: 100 << 2 = 200 (0xC8)

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