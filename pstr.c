#include "monty.h"

/**
 * pstr - print top nodes
 * @h: head of list
 * @line_number: bytecode line number
 */
void pstr(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	if (!h || !*h)
	{
		fprintf(stderr,"L%u: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	while ((temp != NULL) && (temp->n != 0) &&
			(temp->n >= 0) && (temp->n < 128))
	{
		printf("%c", (temp)->n);
		temp = temp->next;
	}
	printf("\n");
}
