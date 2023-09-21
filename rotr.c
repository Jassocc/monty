#include "monty.h"

/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **h, unsigned int line_number)
{
	stack_t *tmp, *last;

	(void) line_number;

	if (*h && (*h)->next)
	{
	tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		last = tmp->prev;
		last->next = NULL;
		tmp->prev = NULL;
		tmp->next = *h;
		(*h)->prev = tmp;
		*h = tmp;
	}
}
