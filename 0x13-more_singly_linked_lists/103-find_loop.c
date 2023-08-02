#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list using Floyd's algorithm.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
	return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast != NULL && fast->next != NULL)
	{
	if (slow == fast)
	{
	slow = head;
	while (slow != fast)
	{
	slow = slow->next;
	fast = fast->next;
	}
	return (slow);
	}

	slow = slow->next;
	fast = fast->next->next;
	}

	return (NULL);
}
