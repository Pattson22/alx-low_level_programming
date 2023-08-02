#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked list.
 * @h: Head of the list.
 *
 * Return: Number of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
size_t node_count = 0;
const listint_t *current = h;

while (current != NULL)
{
/* Move to the next node */
current = current->next;
/* Increment the node count */
node_count++;
}

return (node_count);
}
