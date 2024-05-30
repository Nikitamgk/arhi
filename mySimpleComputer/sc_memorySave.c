#include <mySimpleComputer.h>
int
sc_MemorySave (char *filename)
{
  if (!filename)
    {
      return -1; // неверный указатель на имя файла
    }
  FILE *file = fopen (filename, "wb");
  if (!file)
    {
      return -1; // ошибка открытия файла
    }
  if (fwrite (memory, sizeof (int), 128, file) == 0)
    return -1;
  fclose (file);
  return 0;
}
