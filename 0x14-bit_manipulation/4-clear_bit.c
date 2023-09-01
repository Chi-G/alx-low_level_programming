#include "main.h"

/**
 * clear_bit - this function sets the value of a given bit to 0
 * @n: this is a pointer to the number on change
 * @index: the index of the bit to clear
 *
 * Return: return 1 fro success, and -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
