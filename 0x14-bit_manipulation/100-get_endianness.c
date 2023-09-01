#include "main.h"

/**
 * get_endianness - this function checks if a machine is little or big endian
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int a = 1;
	char *c = (char *) &a;

	return (*c);
}
