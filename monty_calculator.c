#include "monty.h"

/**
 * _add - adds the top two elements in the stack
 * @h: top node
 * @line_number: node number
 */
void _add(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	pop(h, line_number);
}
/**
 * _sub - subtracts second node from the top node
 * @h: top of the list
 * @line_number: line of command
 */
void _sub(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n -= (*h)->n;
	pop(h, line_number);
}
/**
 * _mul - multiplies the second node and top node
 * @h: top of list
 * @line_number: line of command
 */
void _mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	pop(h, line_number);
}
/**
 * _div - divide second node from top node
 * @h: top of list
 * @line_number: line of command
 */
void _div(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n /= (*h)->n;
	pop(h, line_number);
}
/**
 * _mod - mod second node from the top node
 * @h: top of list
 * @line_number: line of command
 */
void _mod(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n %= (*h)->n;
	pop(h, line_number);
}
