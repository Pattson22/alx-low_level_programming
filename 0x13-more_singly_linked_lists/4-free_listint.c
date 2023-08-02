#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: No return.
 */
void free_listint(listint_t *head)
{
listint_t *temp;

while (head != NULL)
{
/* Store the current node in a temporary variable */
temp = head;
/* Move to the next node before freeing the current one */
head = head->next;
/* Free the current node */
free(temp);
}
}
