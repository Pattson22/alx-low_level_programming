#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *message);

/**
 * main - Entry point. Displays information from the ELF header.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	return (98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)

	{
		print_error("Error: Can't open ELF file");
		return (98);
	}

	Elf64_Ehdr elf_header;
	ssize_t bytes_read = read(fd, &elf_header, sizeof(elf_header));

	if (bytes_read == -1 || bytes_read != sizeof(elf_header))

	{
		print_error("Error: Can't read ELF header");
		close(fd);
		return (98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Error: Not an ELF file");
		close(fd);
		return (98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
			elf_header.e_ident[EI_MAG0], elf_header.e_ident[EI_MAG1],
		elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
	printf("  Class:   %s\n",
			elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:    %s\n",
			elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" :
			"2's complement, big endian");
	printf("  Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:  %d\n", elf_header.e_ident[EI_OSABI]);
	printf("  ABI Ver: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:    %d\n", elf_header.e_type);
	printf("  Entry:   %lx\n", (unsigned long)elf_header.e_entry);

	close(fd);
	return (0);
}

/**
 * print_error - Prints an error message to stderr.
 * @message: The error message to print.
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}
