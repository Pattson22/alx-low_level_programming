#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Read and print the contents of a text file.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	close(fd);
	free(buffer);
	return (bytes_written);
}

/**
 * main - Entry point of the program.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(void)
{
	const char *filename = "example.txt";
	size_t letters_to_read = 1024;

	ssize_t letters_read = read_textfile(filename, letters_to_read);

	if (letters_read == 0)

	{
	fprintf(stderr, "Error: Unable to read or print the file.\n");
	return (EXIT_FAILURE);
	}

	printf("Number of letters read and printed: %zd\n", letters_read);

	return (EXIT_SUCCESS);
}
