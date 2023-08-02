#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely with loop detection
 * @h: A pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast;
	size_t count = 0;

	if (h == NULL || *h == NULL)
	return (count);

	slow = *h;
	fast = *h;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
	slow = slow->next;
	fast = fast->next->next;

	if (slow == fast)
	{
	slow = *h;
	while (slow != fast)
	{
	count++;
	*h = (*h)->next;
	free(slow);
	slow = *h;
	}
	*h = NULL;
	count++;
	free(fast);
	return (count);
	}
	}

	while (*h != NULL)
	{
	count++;
	slow = *h;
	*h = (*h)->next;
	free(slow);
	}

	return (count);
}
