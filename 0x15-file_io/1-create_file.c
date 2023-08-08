#include "main.h"

/**
 * create_file - Creates a new file and writes content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write into the file.
 *
 * Return: 1 if successful, -1 if an error occurs.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nletters, rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	nletters = 0;
	while (text_content[nletters])
		nletters++;

	rwr = write(fd, text_content, nletters);
	close(fd);

	return (rwr == nletters ? 1 : -1);
}
