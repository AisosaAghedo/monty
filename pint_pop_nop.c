#include "monty.h"
/**
 * m_pint - function that prints value on top of `stack', or exit if stack is empty
 * @top: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void m_pint(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;

	if (var.stack_len == 0)
	{
		fprintf(stdout,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * m_pop - function that removes top element off of `stack'
 * @top: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void m_pop(stack_t **top, unsigned int line_number)
{
	stack_t *pop = *top;

	if (var.stack_len == 0)
	{
		fprintf(stdout,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*top)->next->prev = (*top)->prev;
	(*top)->prev->next = (*top)->next;
	if (var.stack_len != 1)
		*top = (*top)->next;
	else
		*top = NULL;
	free(pop);
	var.stack_len--;
}

/**
 * m_nop - function where no operation is performed
 * @top: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void m_nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}
