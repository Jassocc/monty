#include "monty.h"

/***
 * is_num - iterates each chars of string
 * @num: integer
 * Return: 0 if num, -1 if not
 */
int is_num(const char *num)
{
	int j = 0;

	if (*num == '-')
	{
		j = 1;
	}
	for (; *(num + j) != '\0'; j++)
	{
		if (isdigit(*(num + j)) == 0)
		{
			return (-1);
		}
	}
	return (0);
}
/**
 * push - adds node
 * @h: head of linked list
 * @line_number - bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
	{
		return;
	}
	if (is_num(n) == -1)
	{
		/* print error message if input is not a valid number*/
		printf("L%u: usage: push integer\n", line_number);
		/* free doubly linked list*/
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*add the new node to the end of the doublt linked list*/
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pop - removes node at front
 * @h: head of linked list
 * @line_number: bytecode line num
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		/* print error message if the stack is empty*/
		printf("L%u: can't pop an empty stack\n", line_number);
		/* free doubly linked list*/
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* delete the last node of the doubly linked list*/
		delete_end_node(h);
	}
}
