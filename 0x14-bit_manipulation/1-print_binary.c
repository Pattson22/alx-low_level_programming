#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary format.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int size = sizeof(unsigned long int) * 8;
	int flag = 0;

	while (size--)
	{
		if ((n >> size) & 1)
			flag = 1;

		if (flag)
			_putchar((n & mask) ? '1' : '0');

		mask <<= 1;
	}

	if (!flag)
		_putchar('0');
}
