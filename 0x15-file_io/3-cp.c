#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * error_file - Checks if files can be opened and exits with appropriate code.
 * @file_from: Source file descriptor.
 * @file_to: Destination file descriptor.
 * @argv: Arguments vector with file paths.
 *
 * Checks if source and destination files can be opened. Exits with code 98 and
 * prints error if source file can't be opened. Exits with code 99 and prints
 * error if destination file can't be opened.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}
	if (file_to == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	exit(99);
	}
}

/**
 * main - Copy content from one file to another.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: 0 on success, other values on failure.
 *
 * Copies content from a source file to a destination file. Exits with code 97
 * and prints usage message if argument count is incorrect. Exits with code 98
 * and prints error if source file can't be read. Exits with code 99 and prints
 * error if destination file can't be created or written to. Exit with code 100
 * and prints error if a file descriptor can't be closed.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
	exit(97);
	}

file_from = open(argv[1], O_RDONLY);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
error_file(file_from, file_to, argv);

nchars = 1024;
while (nchars == 1024)
	{
	nchars = read(file_from, buf, 1024);
	if (nchars == -1)
	error_file(-1, 0, argv);
	nwr = write(file_to, buf, nchars);
	if (nwr == -1)
	error_file(0, -1, argv);
	}
	if (close(file_from) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
	exit(100);
	}

	if (close(file_to) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
	exit(100);
	}
	return (0);
}
