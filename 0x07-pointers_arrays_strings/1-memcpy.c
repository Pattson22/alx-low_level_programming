#include "main.h"
/**
 * _memcpy - a function that copies memory area,
 * @dest: destination memory area.
 * @src: source memory area.
 * @n: number of bytes
 * Return: the pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) =  *(src + i);

	return (dest);
}
