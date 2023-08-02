#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely with loop detect
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	slow = head;
	fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;
	slow = slow->next;
	fast = fast->next->next;

	if (slow == fast)
	break;
	}

	if (slow == fast)
	{
	slow = head;
	while (slow != fast)
	{
	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;
	slow = slow->next;
	fast = fast->next;
	}
	printf("-> [%p] %d\n", (void *)slow, slow->n);
	}
	else
	{
	while (head != NULL)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	count++;
	head = head->next;
	}
	}

	return (count);
}
