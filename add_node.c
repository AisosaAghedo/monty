#include "monty.h"

/**
 * add_node - adds a new node to a circular linked list
 * @top: double pointer to the beginning of the circular linked list
 * @n: number to add to the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **top, const int n)
{
	stack_t *temp;

	if (top == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	temp->n = n;
	if (*top == NULL)
	{
		temp->prev = temp;
		temp->next = temp;
	}
	else
	{
		(*top)->prev->next = temp;
		temp->prev = (*top)->prev;
		(*top)->prev = temp;
		temp->next = *top;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*top = temp;
	return (temp);
}
