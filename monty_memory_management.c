#include "monty.h"
/**
 * free_dlist - frees a doubly linked list
 * @h: pointer to head
 */
void free_dlist(stack_t **h)
{
	if (!h)
	{
		return;
	}
	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
