#include "main.h"
#include <unistd.h>

/**
 * _putchar - this function writes the character c to stdout
 * @c: this is the character to print
 *
 * Return: on success 1.
 * on error, -1 will be returned, and errno is set as it should
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
