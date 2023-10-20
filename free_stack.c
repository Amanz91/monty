#include "main.h"
/**
 * free_stack -  a func to free a stack
 * @head: head
 */
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
