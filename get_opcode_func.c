#include "monty.h"

/**
 * get_op_func - function to select correct operation function
 * @stack: 1st bytecode input (opcode)
 * @opcode: pointer to correct operation function
 * @line_number: line number of args
 */
void get_op_func(stack_t **stack, char *opcode,  unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"push", push},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].opcode != NULL)
	{
		if (strcmp(opcode, instruction_s[i].opcode) == 0)
		{
			instruction_s[i].f(stack, line_number);
			return;
		}
		i++;
	}
	if (instruction_s[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_dlist(stack);
		exit(EXIT_FAILURE);
	}
}
