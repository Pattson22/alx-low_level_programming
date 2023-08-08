#include "main.h"
#include <stdio.h>

/**
 * check_elf - Checks if a file is a valid ELF file.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 *
 * Return: Nothing.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 0x7F && e_ident[index] != 'E' && e_ident[index] != 'L' && e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not a valid ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 *
 * Return: Nothing.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/* Other functions (print_class, print_data, etc.) go here */

/**
 * close_elf - Closes an ELF file.
 * @elf: File descriptor of the ELF file.
 *
 * Return: Nothing.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays information from the ELF header of a file.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, read_status;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		exit(97);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	read_status = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	print_magic(header->e_ident);
	/* Call other print functions here */

	free(header);
	close_elf(fd);

	return (0);
}
