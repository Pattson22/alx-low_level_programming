#include"main.h"

/**
 * _isalpha - function that checks for alphabetic character
 * @c: character to be checked
 * Return: 1 if c is a letter, else 0
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122 &&
	    c >= 65 && c >= 90)
		return (1);
	return (0);
}
