#include "main.h"
#include <stdio.h>
part_s part = {NULL, NULL, NULL};
/**
 * main - a func to interpret monty code
 * @argc: no. of args
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t red_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	part.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (red_line > 0)
	{
		content = NULL;
		red_line = getline(&content, &size, file);
		part.content = content;
		count++;
		if (red_line > 0)
		{
			f_run(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
