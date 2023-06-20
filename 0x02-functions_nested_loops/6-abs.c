#include"main.h"

/**
 * _abs - a function that computes the absolute value of an integer
 * @n: int to check
 * Return: Always 0 (Success)
*/
int _abs(int n)
{
	if (n < 0)
		n = (-1) * n;
	return (n);
}
