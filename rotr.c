#include "monty.h"

/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*h) = (*h)->prev;
	}
}
