#include "main.h"
/**
 * push - a func to add a value to stack
 * @head: head
 * @count: line count
 */
void push(stack_t **head, unsigned int count)
{
	int i, j, f;

	j = 0;
	f = 0;

	if (part.arg)
	{
		if (part.arg[0] == '-')
			j++;
		for (; part.arg[j] != '\0'; j++)
		{
			if (part.arg[j] > 57 || part.arg[j] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(part.file);
			free(part.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(part.arg);
	insert_node(head, i);
}
