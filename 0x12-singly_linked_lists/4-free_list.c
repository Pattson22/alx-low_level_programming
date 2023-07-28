#include <stdlib.h>
#include "lists.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
void free_list(list_t *head)
{
    list_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current->str);
        free(current);
    }
}
