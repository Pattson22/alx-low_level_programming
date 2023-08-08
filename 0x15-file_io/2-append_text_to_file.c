#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The content to add to the file.
 *
 * Return: 1 if successful, -1 if the file does not exist or an error occurs.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, nletters, rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		nletters = 0;
		while (text_content[nletters])
			nletters++;

		rwr = write(fd, text_content, nletters);
		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
