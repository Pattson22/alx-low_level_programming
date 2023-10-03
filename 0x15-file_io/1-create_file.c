#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * create_file - Create a file with specific permission and write content.
 * @filename: The name of the file to create or truncate.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written;
	mode_t file_permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, file_permissions);
	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}
	}

	close(fd);
	return (1);
}
