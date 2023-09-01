#include "main.h"

/**
 * flip_bits - this function counts the number of bit to change to get from one number to another
 * @n: this is the first number
 * @m: this is the second number
 *
 * Return: this is the nmber of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int first;
	unsigned long int second = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		first = second >> i;
		if (first & 1)
			count++;
	}

	return (count);
}
