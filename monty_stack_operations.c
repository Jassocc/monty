#include "monty.h"

/**
 * is_num - iterates each chars of string
 * @num: integer
 * Return: 0 if num, -1 if not
 */
int is_num(const char *num)
{
	int j = 0;

	if (num[0] == '-')
	{
		j = 1;
	}
	for (; num[j] != '\0'; j++)
	{
		if (!isdigit(num[j]))
		{
			return (0);
		}
	}
	return (1);
}
/**
 * push - adds node
 * @h: head of linked list
 * @line_number: bytecode line number
 */
void push(stack_t **h, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *arg = strtok(NULL, " \t\n");

	if (!arg || !is_num(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*h)
	{
		new_node->next = *h;
		(*h)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*h = new_node;
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
