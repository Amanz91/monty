#include "main.h"
/**
 * a fun to print the the value at top of stack
 * @head: head
 * @count: line counter
 */
void pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
