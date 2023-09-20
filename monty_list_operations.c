#include "monty.h"
/**
 * add_end_node - add node to front
 * @h: pointer to head
 * @n: node data
 * Return: 0(success), -1(fail)
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *newer;

	if(!h)
	{
		return (-1);
	}
	newer = malloc(sizeof(struct stack_s));
	if (!newer)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	newer->n = n;
	if (*h == NULL)
	{
		*h = newer;
		newer->next = NULL;
		newer->prev = NULL;
	}
	else
	{
		newer->next = *h;
		(*h)->prev = newer;
		*h = newer;
	}
	return (0);
}
/**
 * delete_end_node - deletes node at end
 * @h: pointer to head
 */
void delete_end_node(stack_t **h)
{
	stack_t *deletion = NULL;

	deletion = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(deletion);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(deletion);
	}
}
