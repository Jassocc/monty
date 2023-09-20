#include "monty.h"
/**
 * pall - print all nodes in stack
 * @h: head
 * @line_number: bytecode num
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!h || !*h)
	{
		return;
	}
	(void) line_number;
	temp = *h;
	while (tenp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
