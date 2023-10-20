#include "main.h"
/**
 * swap - a func to swap top 2 elements of stack
 * @head: head
 * @count: line count
 */
void swap(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, v;

	l = 0;
	temp = *head;

	while (temp)
	{
		temp = temp->next;
		l++;
	}
	temp = *head;

	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	v = temp->n;
	temp->n = temp->next->n;
	temp->next->n = v;
}
/**
 * add - a func to swap top 2 elements of stack
 * @head: head
 * @count: line count
 */
void add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, v, s;

	l = 0;
	s = 0;
	temp = *head;

	while (temp)
	{
		temp = temp->next;
		l++;
	}
	temp = *head;

	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	v = temp->n;
	temp = temp->next;
	s = v;
	v = temp->n;
	s += v;
	temp->n = s;
}
/**
 * nop - a func that does nothing
 * @head: head
 * @count: line count
 */
void nop(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
}
