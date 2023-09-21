#include "monty.h"

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	tmp = *h;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*h)->prev = tmp;
	tmp->next = *h;
	(*h)->next->prev = NULL;
	*h = (*h)->next;
	tmp->next->next = NULL;
}
