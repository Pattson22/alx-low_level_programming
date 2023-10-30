#include "main.h"
/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: The path of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         Otherwise, it returns the actual number of bytes read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int count, fd_o, fd_r;

	if (filename == NULL)
		return (0);


	fd_o = open(filename, O_RDONLY);
	if (fd_o == -1)
		return (0);

	/* Allocate memory in the buffer to read the contents of fd_o */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd_r = read(fd_o, buffer, letters);
	if (fd_r == 0)
	{
		free(buffer);
		close(fd_o);
		return (0);
	}


	count = write(STDOUT_FILENO, buffer, fd_r);
	if (count == -1)
	{
		free(buffer);
		close(fd_r);
		close(fd_o);
		return (0);
	}

	close(fd_r);
	close(fd_o);

	return (count);
}
