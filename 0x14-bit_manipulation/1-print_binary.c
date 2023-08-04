#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary format.
 */
void print_binary(unsigned long int n)
{
	int bit_count = 0;
	unsigned long int mask = 1;

	/* Count the number of bits in the number */
	while ((n >> bit_count) > 0)
		bit_count++;

	/* Print the binary representation */
	if (bit_count == 0)
		_putchar('0');
	else
	{
	for (bit_count--; bit_count >= 0; bit_count--)
	{
	mask = 1 << bit_count;
		_putchar((n & mask) ? '1' : '0');
		}
	}
}
