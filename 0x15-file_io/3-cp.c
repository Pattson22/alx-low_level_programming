#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates a 1024-byte buffer for file operations.
 * @file: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate buffer for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the program's arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do

	{
		if (source_fd == -1 || read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	write_bytes = write(destination_fd, buffer, read_bytes);
	if (destination_fd == -1 || write_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to write to file %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	read_bytes = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_file(source_fd);
	close_file(destination_fd);

	return (0);
}
