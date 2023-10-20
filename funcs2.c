#include "main.h"
/**
 * mul - a func to multiply top 2 elements of stack
 * @head: head
 * @count: line count
 */
void mul(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, s;

	s = 0;
	temp = *head;

	for (l = 0; temp != NULL; l++)
                temp = temp->next;
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	s = temp->n * temp->next->n;
	temp->next->n = s;
	*head = temp->next;
	free(temp);
}
/**
 * div - a func to find division of top 2 elements of stack
 * @head: head
 * @count: line count
 */
void divf(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, s;

	s = 0;
	temp = *head;

	for (l = 0; temp != NULL; l++)
		temp = temp->next;
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	s = temp->next->n / temp->n;
	temp->next->n = s;
	*head = temp->next;
	free(temp);
}
