#include"main.h"

/**
 * _islower - function to check if character is lowercase
 * @c: char to be checked
 * Return: returns 1 if char is lowercase otherwise 0       
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
