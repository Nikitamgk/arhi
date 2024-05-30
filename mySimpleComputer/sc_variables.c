#include <mySimpleComputer.h>

int memory[128] = { 0 };
int flags = 0;
int Accum = 0;
int ICount = 0;
int TACTS = 0;

CACHE cache[5] = { { 0 }, 0, 0 };