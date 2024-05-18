#include "../include/mySimpleComputer.h"

/// @brief 
/// @param registr  1 | 4096 | 16 | 65536 | 256
/// @param value 0 | 1
/// @return 0 | -1
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