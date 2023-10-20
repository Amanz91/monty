#include "main.h"
/**
 * swap - a func to swap top 2 elements of stack
 * @head: head
 * @count: line count
 */
void swap(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l;

	temp = *head;

	for (l = 0; temp != NULL; l++)
		temp = temp->next;
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

	s = 0;
	temp = *head;

	for (l = 0; temp != NULL; l++)
                temp = temp->next;
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
/**
 * sub - a func to find difference b/n top 2 elements of stack
 * @head: head
 * @count: line count
 */
void sub(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int l, s;

	s = 0;
	temp = *head;

	for (l = 0; temp != NULL; l++)
		temp = temp->next;
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", count);
		fclose(part.file);
		free(part.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	s = temp->next->n - temp->n;
	temp->next->n = s;
	*head = temp->next;
	free(temp);
}
