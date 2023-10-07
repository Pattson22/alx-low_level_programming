#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its content to STDOUT.
 * @filename: A pointer to the name of the file to be read.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: If the function fails or if `filename` is NULL - 0.
 *         Otherwise, it returns the actual number of bytes read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	bytes_read = read(file_descriptor, buffer, letters);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (file_descriptor == -1 || bytes_read == -1 || bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
