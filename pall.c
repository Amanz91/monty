#include "main.h"
/**
 * pall - a function to print a stack
 * @head: head
 * @count: unused
 * Return: Nothing
 */
void pall(stack_t **head, __attribute__((unused))unsigned int count)
{
	stack_t *temp;

	temp = *head;

	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
