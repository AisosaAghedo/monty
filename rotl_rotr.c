#include "monty.h"
/**
 * rotl - function that puts the top of stack at the last and the second at the top
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_num)
{
	int temp1 = 0;
	stack_t *temp2 = *stack;

	(void)line_num;
	if (*stack == NULL)
		return;
	temp1 = temp2->n;
	while (temp2->next != NULL)
	{
		temp2->n = temp2->next->n;
		temp2 = temp2->next;
	}
	temp2->n = temp1;
}

/**
 * rotr - function that puts the last element of the stack at the last
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	int temp1 = 0;
	stack_t *temp2 = *stack;

	(void)line_num;
	if (*stack == NULL)
		return;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp1 = temp2->n;
	while (temp2->prev != NULL)
	{
		temp2->n = temp2->prev->n;
		temp2 = temp2->prev;
	}
	temp2->n = temp1;
}
