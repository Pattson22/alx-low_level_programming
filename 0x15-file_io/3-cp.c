#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(void);
void close_descriptor(int fd);

/**
 * allocate_buffer - Allocates a 1024-byte buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to allocate memory for the buffer\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, exit with code 97.
 *		If the source file cannot be opened or read, exit with code 98.
 *		If the dst file cannot be created or wrtn to, exit with code 99.
 *		If there is an issue closing a file dstor, exit with code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_result, write_result;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer();
	source_fd = open(argv[1], O_RDONLY);
	read_result = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_result = write(destination_fd, buffer, read_result);
		if (destination_fd == -1 || write_result == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_result = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_result > 0);

	free(buffer);
	close_descriptor(source_fd);
	close_descriptor(destination_fd);

	return (0);
}
