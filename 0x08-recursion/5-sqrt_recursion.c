#include "main.h"
/**
 *_evaluate - square root of a number
 *@i: interger
 *@n: interger
 *Return: Always 0
 */

int _evaluate(int i, int n)
{
if (n == 0 || n == 1)
return (n);

else if (i * i < n)
return (_evaluate(i + 1, n));

else if (i * i == n)
return (i);

return (-1);

return (-1);
}

/**
 *_sqrt_recursion - a function that returns the natural square root of a number
 *@n: interger
 *Return: Sgrt_recursion
*/

int _sqrt_recursion(int n)
{
int i = 0;
if (i < 0)
return (-1);

else
{
return (_evaluate(i, n));
}

}
