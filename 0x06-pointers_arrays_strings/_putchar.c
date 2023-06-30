#include "main.h"
#include <unistd.h>

/**
 * _putchar - write the character C to stdout
 * @C: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _puchar(char C)
{
	return (write(1, &C, 1));
}
