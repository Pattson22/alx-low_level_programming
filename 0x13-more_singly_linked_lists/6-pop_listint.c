#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the head of the list.
 *
 * Return: data of the deleted head node, or 0 if list is empty.
 */
int pop_listint(listint_t **head)
{
	int hnode = 0;
	listint_t *h;

	if (*head != NULL)
	{
	hnode = (*head)->n;
	h = (*head)->next;
	free(*head);
	*head = h;
	}

	return (hnode);
}
