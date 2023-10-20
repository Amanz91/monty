#include "main.h"
/**
 * f_run - a func to run opcode
 * @content: arg
 * @stack: stack
 * @count: line count
 * @file: monty file pointer
 * Return: 0 or 1
 */
int f_run(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	int i = 0;
	char *op;
	instruction_t ops[] = {{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divf},
		{"mul", mul},
		{"stack", stackf},
		{NULL, NULL}
	};

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);
	part.arg = strtok(NULL, " \n\t");

	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
