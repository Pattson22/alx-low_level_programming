#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The path of the file.
 * @text_content: The content to append at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int count, len = 0, fd, i;

	if (filename == NULL)
		return (-1);

	/* Open the file and obtain the file descriptor */
	fd = open(filename, O_WRONLY | O_APPEND, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	for (i = 0; text_content[i]; i++)
		len++;

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
