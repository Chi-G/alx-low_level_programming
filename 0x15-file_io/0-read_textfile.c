#include "main.h"
#include <stdlib.h>

/**
 * read_textfile -this function reads text files to STDOUT.
 * @filename: the text file that is read
 * @letters: this is the number of letters to be read
 * Return: w- the number of bytes read and printed
 * 0 when the function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	char *buf;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
