#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_beffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this function allocates 1024 bytes for a buffer
 * @file: this is the name of the file buffer that is storing chars
 *
 * Return: this is a pointer to the newly-allocated buffer
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

			if (buffer == NULL)
			{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
			exit(99);
}

return (buffer);
}

/**
 * close_file - this function closes file descriptors
 * @fd: this is the file descriptor to be closed
 */

void close_file(int fd)
{
int c;

c = close(fd);

if (c == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
}

/**
 * main - this function copies the contents of a file to another file
 * @argc: this is the number of arguments supplied to the program
 * @argv: this is array of pointers to the arguments
 *
 * Return: 0 in success
 *
 * description: if the argument count is incorrect - exit with code 97
 * if file_from does not exist or cannot be read - exit code 98
 * if file_to cannot be created or written to - exit with code 99
 * if file_to or file_from cannot be close - exit with with code 100
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

