#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void validate_elf(unsigned char *e_ident);
void display_elf_magic(unsigned char *e_ident);
void display_elf_class(unsigned char *e_ident);
void display_elf_data(unsigned char *e_ident);
void display_elf_version(unsigned char *e_ident);
void display_elf_abi(unsigned char *e_ident);
void display_elf_osabi(unsigned char *e_ident);
void display_elf_type(unsigned int e_type, unsigned char *e_ident);
void display_elf_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);

/**
 * validate_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit with code 98.
 */
void validate_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_elf_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void display_elf_magic(unsigned char *e_ident)
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

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", argv[1]);
		exit(98);
	}
	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_elf_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf(header->e_ident);
	printf("ELF Header:\n");
	display_elf_magic(header->e_ident);
	display_elf_class(header->e_ident);
	display_elf_data(header->e_ident);
	display_elf_version(header->e_ident);
	display_elf_osabi(header->e_ident);
	display_elf_abi(header->e_ident);
	display_elf_type(header->e_type, header->e_ident);
	display_elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf_file(file_descriptor);
	return (0);
}
