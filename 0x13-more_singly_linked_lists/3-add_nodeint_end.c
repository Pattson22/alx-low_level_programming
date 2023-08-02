#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list.
 * @head: A pointer to the head of the linked list.
 * @n: The value to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *temp;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
/* If the list is empty, make the new node the head of the list */
*head = new_node;
}
else
{
/* Traverse to the end of the list and append the new node */
temp = *head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new_node;
}

return (*head);
}
