#include <mySimpleComputer.h>
int
sc_MemoryLoad (char *filename)
{
  if (!filename)
    {
      return -1; // неверный указатель на имя файла
    }
  FILE *file = fopen (filename, "rb");
  if (!file)
    {
      return -1; // ошибка открытия файла
    }
  int buffer[128];
  if (fread (buffer, sizeof (int), 128, file) == 0)
    return -1;
  fclose (file);
  // Если чтение успешно, переносим содержимое в оперативную память
  for (int i = 0; i < 128; i++)
    {
      memory[i] = buffer[i];
    }
  return 0;
}
