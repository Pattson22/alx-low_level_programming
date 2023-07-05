#include "main.h"
/**
 *_print_rev_recursion - a function that prints a string in reverse
 *@s: the string to be printed
 *Return: Always 0
 */

void _print_rev_recursion(char *s)
{
if (*s) /*If statement*/
{
_print_rev_recursion(s + 1); /*add s*/
_putchar(*s); /*print s*/
}
}
