#include "monty.h"

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **h, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*h && (*h)->next)
	{
		temp = *h;
		*h = (*h)->next;
		last = *h;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
		temp->prev = last;
	}
}
