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
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' &&
		    e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		printf(i == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	printf(e_ident[EI_VERSION] == EV_CURRENT ? " (current)\n" : "\n");
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n"); break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n"); break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n"); break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n"); break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n"); break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n"); break;
	case ELFOSABI_ARM:
		printf("ARM\n"); break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n"); break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_t: The ELF type.
 * @e_i: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_t, unsigned char *e_i)
{
	if (e_i[EI_DATA] == ELFDATA2MSB)
		e_t >>= 8;
	printf("  Type:                              ");
	if (e_t == ET_NONE)
		printf("NONE (None)\n");
	else if (e_t == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_t == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_t == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_t == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_t);
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_e: The address of the ELF entry point.
 * @e_i: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_e, unsigned char *e_i)
{
	printf("  Entry point address:               ");
	if (e_i[EI_DATA] == ELFDATA2MSB)
	{
		e_e = ((e_e << 8) & 0xFF00FF00) | ((e_e >> 8) & 0xFF00FF);
		e_e = (e_e << 16) | (e_e >> 16);
	}
	if (e_i[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_e);
	else
		printf("%#lx\n", e_e);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *h;
	int o, r;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	o = open(argv[1], O_RDONLY);
	if (o == -1)
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]), exit(98);
	h = malloc(sizeof(Elf64_Ehdr));
	if (!h)
		close_elf(o), dprintf(STDERR_FILENO, "Error\n"), exit(98);
	r = read(o, h, sizeof(Elf64_Ehdr));
	if (r == -1)
		free(h), close_elf(o), dprintf(STDERR_FILENO, "Error\n"), exit(98);
	check_elf(h->e_ident);
	printf("ELF Header:\n");
	print_magic(h->e_ident);
	print_class(h->e_ident);
	print_data(h->e_ident);
	print_version(h->e_ident);
	print_osabi(h->e_ident);
	print_abi(h->e_ident);
	print_type(h->e_type, h->e_ident);
	print_entry(h->e_entry, h->e_ident);
	free(h), close_elf(o);
	return (0);
}
