#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * verify_elf - Ensures that the file is in ELF format.
 * @e_ident: Pointer to an array containing ELF magic numbers.
 *
 * Description: Exits with error code 98 if the file is not in ELF format.
 */
void check_elf(unsigned char *e_ident)
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
 * display_magic - Displays the magic numbers of an ELF header.
 * @e_ident: Pointer to an array containing ELF magic numbers.
 *
 * Description: Magic numbers are displayed as hexadecimal values.
 */
void print_magic(unsigned char *e_ident)
{
	int index;
	printf("  Magic Numbers: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
	printf("%02x", e_ident[index]);

	if (index == EI_NIDENT - 1)
		printf("\n");
	else
		printf(" ");
	}
}

// ... (Pat's)
