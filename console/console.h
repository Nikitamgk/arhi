#ifndef CNSL
#define CNSL
#pragma once
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"

#define memoryCell = 6;
#define FLAGS = 16;
#define Decoded = 32;
#define Accumulator = 16;
#define Counter = 16;
#define Command = 16;
#define in_out = 11;
#define clavs = 17;
#define cache = 56;
#define memroyCellsY = 10;

int IN_OUT_addres[4];

void printCell (int address, enum Colors fg, enum Colors bg);

void printFlags ();

void printAccumulator ();

void printCounters ();

void printTerm ();
#endif