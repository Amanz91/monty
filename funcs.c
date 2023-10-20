#include "main.h"
/**
 * swap - a func to swap top 2 elements of stack
 * @head: head
 * @count: line count
 */
void swap(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l = 0;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev = NULL;
	*head = temp;
}
/**
 * add - a func to add top 2 elements of stack
 * @head: head
 * @count: line count
 */
void add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, s;

	l = 0;
	s = 0;
	temp = *head;

	while (temp)
	{
		temp = temp->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	s = temp->n + temp->next->n;
	temp->next->n = s;
	*head = temp->next;
	free(temp);
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
