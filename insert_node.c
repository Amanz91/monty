#include "main.h"
/**
 * insert_node - a func to add node to stack
 * @head: head of stack
 * @n: value
 * Return: nothing
 */
void insert_node(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));

	if  (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
	{
		temp->prev = new;
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
