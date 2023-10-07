#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocate a 1024-byte buffer.
 * @file: The file name for which the buffer is allocated.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to allocate memory for %s\n", file);
	exit(99);
	}

	return (buffer);
}

/**
 * close_file - Close a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int close_result;

	close_result = close(fd);

	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the contents of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit with code 97 if the argument count is incorrect.
 *              Exit with code 98 if file_from does not exist or cant be read.
 *              Exit with code 99 if file_to cannot be created or written to.
 *              Exit with code 100 if file_to or file_from cannot be closed.
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

	do

	{
		if (from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to read from file %s\n", argv[1]);
	free(buffer);
		exit(98);
	}

	w = write(to, buffer, r);
	if (to == -1 || w == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to write to %s\n", argv[2]);
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
