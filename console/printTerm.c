#include "console.h"

void
printTerm(int addres, int input)
{
  if (address > 128 || address < 0)
    return;
  if (input == 1)
  {
    int new_value;
    int temp = IN_OUT_addres[1];
    int temp_two = IN_OUT_addres[2];
    int temp_three = IN_OUT_addres[3];
    IN_OUT_addres[1] = IN_OUT_addres[0];
    IN_OUT_addres[2] = temp;
    IN_OUT_addres[3] = temp_two;
    IN_OUT_addres[4] = temp_three;
    IN_OUT_addres[0] = address;
    mt_gotoXY(67,17);
    printf("%d< ", address);
    scanf("%d", &new_value);
    sc_MemorySet(address, new_value);
  }
  for(int count = 0; count <= 4; count++)
  {
  mt_gotoXY(66,17+count);
  printf("%03d> ", IN_OUT_addres[count]);
  printf("%04d", memory[IN_OUT_addres[count]]);
  }
  return;
}