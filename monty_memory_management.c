#include "monty.h"
/**
 * free_dlist - frees a doubly linked list
 * @h: pointer to head
 */
void free_dlist(stack_t **h)
{
	stack_t *temp, *n;

	temp = *h;
	while (temp)
	{
		n = temp->next;
		free(temp);
		temp = n;
	}
	*h = NULL;
}
