#include "monty.h"
/**
 * pint - print top node
 * @h: head
 * @line_number: bytecode
 */
void pint(stack_t **h, unsigned int line_number)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
