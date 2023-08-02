#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index in the list.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to be deleted (starting at 0).
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev = NULL;
	unsigned int count = 0;

	if (*head == NULL)
	return (-1);

	temp = *head;
	if (index == 0)
	{
	*head = temp->next;
	free(temp);
	return (1);
	}

	while (temp != NULL && count != index)
	{
	prev = temp;
	temp = temp->next;
	count++;
	}

	if (temp == NULL)
	return (-1);

	prev->next = temp->next;
	free(temp);
	return (1);
}
