#include "monty.h"
#include <stdio.h>

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1000];
	char *opcode;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		opcode = strtok(line, " \t\n");
		if (opcode && opcode[0] != '#')
		{
			get_op_func(&stack, opcode, line_number);
		}
		line_number++;
	}
	fclose(file);
	free_dlist(&stack);
	return (EXIT_SUCCESS);
}
