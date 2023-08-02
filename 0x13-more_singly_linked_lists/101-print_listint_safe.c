#include "lists.h"

/**
 * free_listp - frees a linked list
 * @head: pointer to the head of a list.
 *
 * Return: no return.
 */
void free_listp(listp_t **head)
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
 * print_listint_safe - prints a linked list.
 * @head: pointer to the head of a list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes = 0;
	listp_t *hptr = NULL, *new, *add;

	while (head != NULL)
	{
	new = malloc(sizeof(listp_t));

	if (new == NULL)
	{
	free_listp(&hptr);
	exit(98);
	}

	new->p = (void *)head;
	new->next = hptr;
	hptr = new;

	add = hptr;

	while (add->next != NULL)
	{
	add = add->next;
	if (head == add->p)
	{
	printf("-> [%p] %d\n", (void *)head, head->n);
	free_listp(&hptr);
	return (nnodes);
	}
	}

	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	nnodes++;
	}

	free_listp(&hptr);
	return (nnodes);
}
