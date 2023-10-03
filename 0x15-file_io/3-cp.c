#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
int open_source_file(const char *source_filename);
int open_destination_file(const char *destination_filename);
int copy_file_contents(int source_fd, int destination_fd);

/**
 * main - Entry point. Copies the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	source_fd = open_source_file(argv[1]);
	if (source_fd == -1)
		return (98);

	destination_fd = open_destination_file(argv[2]);
	if (destination_fd == -1)
	{
		close(source_fd);
		return (99);
	}

	if (copy_file_contents(source_fd, destination_fd) == -1)
	{
		close(source_fd);
		close(destination_fd);
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		return (99);
	}

	if (close(source_fd) == -1 || close(destination_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		return (100);
	}

		return (0);
}

/**
 * open_source_file - Opens the source file for reading.
 * @source_filename: The name of the source file.
 *
 * Return: The file descriptor of the opened source file or -1 on error.
 */
int open_source_file(const char *source_filename)
{
	int source_fd;

	source_fd = open(source_filename, O_RDONLY);
	if (source_fd == -1)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source_filename);

	return (source_fd);
}

/**
 * open_destination_file - Opens the destination file for writing.
 * @destination_filename: The name of the destination file.
 *
 * Return: The file descriptor of the opened destination file or -1 on error.
 */
int open_destination_file(const char *destination_filename)
{
	int destination_fd;

	destination_fd = open(destination_filename, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (destination_fd == -1)
	dprintf(STDERR_FILENO, "Error: Can't write to file %s\n",
			destination_filename);

	return (destination_fd);
}

/**
 * copy_file_contents - Copies the contents of the
			- source file to the destination file.
 * @source_fd: The file descriptor of the source file.
 * @destination_fd: The file descriptor of the destination file.
 *
 * Return: 0 on success, or -1 on write error.
 */
int copy_file_contents(int source_fd, int destination_fd)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
	bytes_written = write(destination_fd, buffer, bytes_read);
	if (bytes_written == -1)
		return (-1);
	}

	return (0);
}
