#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ON 0xFFFE
#define OFF 0x0001
#define IT_MASK 0x001
#define MC_MASK 0x1000
#define SF_MASK 0x010
#define ZD_MASK 0x10000
#define OO_MASK 0x100

#define MEMORY_SIZE 128

int *memory[128];
int flags;
int Accum;
int ICount;
int commands[40] = {0x00, 0x01, 0x0A, 0x0B, 0x14, 0x15, 0x1E, 0x1F, 0x20, 0x21, 0x28, 0x29, 0x2A, 0x2B, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C};


int sc_MemoryInit (void);

int sc_MemorySet (int address, int value);

int sc_MemoryGet (int address, int *value);

int sc_MemorySave (char *filename);

int sc_MemoryLoad (char *filename);

int sc_regInit (void);

int sc_regSet (int reg, int value);

int sc_regGet (int reg, int *value);

int sc_accumulatorInit (void);

int sc_accumulatorSet (int value);

int sc_accumulatorGet (int *value);

int sc_icounterInit (void);

int sc_icounterSet (int value);

int sc_icounterGet (int *value);

int sc_commandEncode (int sign, int command, int operand, int *value);

int sc_commandDecode (int value, int *sign, int *command, int *operand);

int sc_commandValidate (int command);
