#include "monty.h"
/**
 * pall - print all nodes in stack
 * @h: head
 * @line_number: bytecode num
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *temp = *h;

	(void) line_number;
	if (mode == 0)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
	else if (mode == 1)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
