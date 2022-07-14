#include "monty.h"
/**
 * m_add - function that adds the top two elements of the stack
 * @top: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: void
 */
void m_add(stack_t **top, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		fprintf(stdout,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n += (*top)->n;
	m_pop(top, line_number);
	(*top)->n += n;
}

/**
 * m_swap - function that swaps top two elements of stack
 * @top: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void m_swap(stack_t **top, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		fprintf(stdout,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*top = (*top)->next;
		return;
	}
	next = (*top)->next;
	next->prev = (*top)->prev;
	(*top)->prev->next = next;
	(*top)->prev = next;
	(*top)->next = next->next;
	next->next->prev = *top;
	next->next = *top;
	*top = next;
}
