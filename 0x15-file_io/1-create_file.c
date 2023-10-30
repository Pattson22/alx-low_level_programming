#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The path of the file to create or truncate.
 * @text_content: The content to write to new file or truncated existing file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int count, len = 0, fd;

	if (filename == NULL)
		return (-1);

	/* Open the file and obtain the file descriptor */
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* Write into the file descriptor */
	count = write(fd, text_content, len);
	if (count == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
