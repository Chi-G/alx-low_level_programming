#include "main.h"

/**
 * set_bit - this function sets a bit at a given index to 1
 * @n: this is a pointer to the number on change
 * @index: this is the index of the bit to set to 1
 *
 * Return: then 1 for success, -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
