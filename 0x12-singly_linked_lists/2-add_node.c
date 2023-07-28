#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A pointer to the head of the linked list.
 * @str: The string to store in the new node.
 *
 * Return: The address of the new head of the list.
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
size_t nchar = 0;

/* Allocate memory for the new node */
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

/* Duplicate the string using strdup */
new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

/* Calculate the length of the string */
while (str[nchar])
nchar++;

new_node->len = nchar;
new_node->next = *head;

/* Update the head to point to the new node */
*head = new_node;
/* patrick's */
return (*head);
}
