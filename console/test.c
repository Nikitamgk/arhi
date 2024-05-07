#include "../include/mySimpleComputer.h"

int
sc_MemoryInit ()
{
	for (int i = 0; i <= 127; i++)
	{
		memory[i] = 0;
	}
	return 0;
}

int
sc_MemorySet (int address, int value)
{
	if ((address < 0 || address > 127) || (value > 0x7FFF || value < 0))
	{
		return -1;
	}
	else
	{
		memory[address] = value;
		return 0;
	}
}

int
sc_MemoryGet (int address, int* value)
{
	if(address > 127 || address < 0 || value != NULL)
	{
		return -1;
	}
	else
	{
		*value = memory[address];
		return 0;
	}
}

int
sc_MemorySave (char* filename)
{
	FILE *fp;
	if ((fp == fopen (filename, "r+")) == NULL)
		return -1;
	else
	{
		fwrite(&memory[0], sizeof(int), 127, fp);
		return 0;
	}
}

int
sc_MemoryLoad (char* filename)
{
	FILE *fs;
	if ((fs == fopen(filename, "r+")) == NULL)
		return -1;
	else
	{
		fread(&memory[0], sizeof(int), 127, fs);
		return 0;
	}
}

int
sc_regInit ()
{
	for(int i = 0; i <= 2; i++)
	{		
		if(i == 2)
		{
			flags = ~flags&OFF;
		}
		else
		{
		flags = flags&(~OFF);
		}
	}
}

int
sc_regSet (int registr, int value)
{
    if(registr == IT_MASK || registr == MC_MASK || registr == SF_MASK || registr == ZD_MASK || registr == OO_MASK)
    {   
    if(value == 1)
    {
        flags = flags | registr;
        return 0;
    }
    if(value == 0)
    {
        flags = flags & (~registr);
        return 0;
    }
    return -1;
    }
	return -1;
}


int
sc_regGet (int registr, int* value)
{
	if(value == NULL || registr > 2 || registr < 0)
		return -1;
	else
	{
	int temp = flags;
	temp << 15-registr;
	temp >> 15+registr;
	*value = temp;
	return 0;
	}
}

int
sc_accumulatorInit ()
{
	Accum = 0;
}

int
sc_accumulatorSet (int value)
{
	if(value > 128 || value < -128)
		return -1;
	else
	{
		Accum = value;
		return 0;
	}
}

int
sc_accumulatorGet (int* value)
{
	if (value ==NULL)
		return -1;		 	
	else
	{
		*value = Accum;
		return 0;
	}
}

int
sc_icounterInit ()
{
	ICount = 0;
	return 0;
}

int
sc_icounterSet (int value)
{
	if (value > 127 || value < 0)
		return -1;
	else
	{
		ICount = value;
		return 0;
	}
}

int
sc_icounterGet (int* value)
{
	if(value == NULL)
		return -1;
	else
	{
		*value = ICount;
	}
}

int
sc_commandEncode (int sign, int command, int operand, int* value)
{
	int temp = 0;
	for(int i = 0; i <= 40; i++)
	{
		if (command == commands[i])
			temp = 1;
	}
	if (temp = 0)
		return -1;
	if (sign >= 1 || sign < 0 || operand > 127 || operand < 0)
		return -1;
	else
	{
		int new_comm = 0;
		new_comm = new_comm | command;
		new_comm = new_comm << 7;
		new_comm = new_comm | operand;
		*value = new_comm;
		return 0;
	}
}

int
sc_commandDecode (int value, int* sign, int* command, int* operand)
{
	int temp = value;
	if (temp >> 14 == 1)
		return -1;
	else
	{
		temp = temp >> 14;
		*sign = temp;
		temp = value;
		temp = temp << 1;
		temp = temp >> 8;
		*command = temp;
		temp = value;
		temp = temp &(~(*command << 7));
		*operand = temp;
		return 0;
	}
}

int
sc_commandValidate (int command)
{
	int temp = command;
	command << 1;
	command >> 8;
	for (int i = 0; i <= 40; i++)
	{
		if(command == commands[i])
		{
		command = temp;
			return 1;
		}
	}
	command = temp;
		return 0;

}

/*void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  printf ("sign = %d\n command = %d\n operand = %d\n", *sign, *command, *operand);
}

void
printFlags ()
{
    printf("Flag 0 is: %s \n", (flags&IT_MASK)== IT_MASK ? "I" : "_");
    printf("Flag 1 is: %s \n", (flags&MC_MASK)== MC_MASK ? "M" : "_");
    printf("Flag 2 is: %s \n", (flags&SF_MASK)== SF_MASK ? "S" : "_");
    printf("Flag 3 is: %s \n", (flags&ZD_MASK)== ZD_MASK ? "Z" : "_");
    printf("Flag 4 is: %s \n", (flags&OO_MASK)== OO_MASK ? "O" : "_");
}

void
printAccumulator ()
{
	printf ("Accumulator = %d \n", Accum);
}

void
printCounters ()
{
	printf ("Counter = %d \n", ICount);
}

int
main()
{
    // Инициализация оперативной памяти, аккумулятора, счетчика команд и
  // регистра флагов
  sc_MemoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  // Установка произвольных значений в оперативную память и вывод ее
  // содержимого (в данном примере установим все ячейки памяти в значение 5)  не прошло
  for (int i = 7; i < 26; i++)
    {
      sc_MemorySet (i, 5);
    }

  // Вывод содержимого оперативной памяти  прошло
  for (int i = 0; i < MEMORY_SIZE; i++)
    {
      printCell (i);
    }
  printf ("\n");

  // Попытка задать недопустимое значение ячейке памяти  прошло
  int invalidMemoryValue = 40000;
  int result = sc_MemorySet (10, invalidMemoryValue);
  printf ("Status of setting invalid memory value: %d\n", result);

  // Установка произвольных значений флагов и вывод их содержимого  не прошло
  sc_regSet (IT_MASK,1);
  sc_regSet (SF_MASK,1);
  sc_regSet (OO_MASK,1);
  printFlags ();

  // Попытка установить некорректное значение флага прошло
  result = sc_regSet (1,2);
  printf ("Status of setting invalid flag value: %d\n", result);

  // Установка значения аккумулятора и вывод его на экран  прошло
  sc_accumulatorSet (100);
  printAccumulator ();

  // Попытка задать недопустимое значение аккумулятору  прошло
  int invalidAccValue = 40000;
  result = sc_accumulatorSet (invalidAccValue);
  printf ("Status of setting invalid accumulator value: %d\n", result);

  // Установка значения счетчика команд и вывод его на экран  прошло
  sc_icounterSet (50);
  printCounters ();

  // Попытка задать недопустимое значение счетчику команд  прошло
  int invalidCounterValue = -10;
  result = sc_icounterSet (invalidCounterValue);
  printf ("Status of setting invalid counter value: %d\n", result);

  // Декодирование произвольной ячейки памяти и значения  прошло
  // аккумулятора
  printCell (8);
  printf ("\n");
  printAccumulator ();

  int command = 0x33;
  int encodedValue;
  sc_commandEncode (0, command, 0x59, &encodedValue); // прошло
  printf ("\nencoded command: %d\n", encodedValue);
    int decoded, decOper, decSign, decComm;
  sc_commandDecode(encodedValue, &decSign, &decComm, &decOper);
  printf ("decoded: sign %d command %d operand %d", decSign, decComm, decOper);

  return 0;
}*/