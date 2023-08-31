#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing a binary number.
 *
 * Return: The converted number, or 0 if the string contains
 *         characters other than '0' or '1', or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
	return (0);

	while (*b)
	{
	if (*b != '0' && *b != '1')
	return (0);

		result = (result << 1) + (*b - '0');
		b++;
	}

	return (result);
}
