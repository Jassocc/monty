#include "monty.h"
/**
 * pchar - print top node
 * @h: head
 * @line_number: bytecode line number
 */
void pchar(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*h)->n) >= 0 && ((*h)->n) < 128)
	{
		printf("%c\n", (*h)->n);
	}
	else
	{
		printf("L%u: can't pchar, value out of range\m", line_number);
		exit(EXIT_FAILURE);
	}
}
