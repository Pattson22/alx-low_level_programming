#include "lists.h"

/**
 * free_listp2 - frees a linked list
 * @head: pointer to the head of a list.
 *
 * Return: no return.
 */
void free_listp2(listp_t **head)
{
	listp_t *temp;

	if (head != NULL)
	{
	while (*head != NULL)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	}
	}
}

/**
 * free_listint_safe - frees a linked list.
 * @h: pointer to the head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nnodes = 0;
	listp_t *hptr = NULL, *new, *add;
	listint_t *curr;

	while (*h != NULL)
	{
	new = malloc(sizeof(listp_t));

	if (new == NULL)
	{
	free_listp2(&hptr);
	exit(98);
	}

	new->p = (void *)*h;
	new->next = hptr;
	hptr = new;

	add = hptr;

	while (add->next != NULL)
	{
	add = add->next;
	if (*h == add->p)
	{
	*h = NULL;
	free_listp2(&hptr);
	return (nnodes);
	}
	}

	curr = *h;
	*h = (*h)->next;
	free(curr);
	nnodes++;
	}

	*h = NULL;
	free_listp2(&hptr);
	return (nnodes);
}
