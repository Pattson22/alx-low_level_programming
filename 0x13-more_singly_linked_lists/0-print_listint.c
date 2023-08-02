#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a list.
 * @h: Head of a list.
 *
 * Return: Number of nodes.
 */
size_t print_listint(const listint_t *h)
{
const listint_t *current = h;
size_t node_count = 0;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
node_count++;
}

return (node_count);
}
