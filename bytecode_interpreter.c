#include "monty.h"
/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int file_desc, is_push = 0;
	unsigned int line_num = 1;
	ssize_t reading;
	char *buff, *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_desc = open(argv[1], O_RDONLY);
	if (file_desc == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
	{
		return (0);
	}
	reading = read(file_desc, buff, 10000);
	if (reading == -1)
	{
		free(buff);
		close(file_desc);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (is_push == 1)
		{
			push(&h, line_num, token);
			is_push = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line_num++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_push = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
			{
				get_op_func(token)(&h, line_num);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line_num++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h), free(buffer);
	close(file_desc);
	return (0);
}
