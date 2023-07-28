#include "lists.h"
#include <stdio.h>
/**
 * print_list - Prints all the elements of a list_t list.
 * @h: A pointer to the head of the singly linked list.
 * Return: The number of elements in the list.
 */
size_t print_list(const list_t *h)
{
    size_t nelem = 0;

    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[%d] %s\n", 0, "(nil)");
        else
            printf("[%u] %s\n", h->len, h->str);

        h = h->next;
        nelem++;
    }

    return nelem;
}
