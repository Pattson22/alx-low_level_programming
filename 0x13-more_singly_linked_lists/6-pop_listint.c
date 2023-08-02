#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The head node's data (n), or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (0);

	int data = (*head)->n;
		listint_t *temp = *head;

	*head = (*head)->next;
	free(temp);

	return (data);
}
