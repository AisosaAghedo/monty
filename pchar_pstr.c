#include "monty.h"

/**
 * pchar - function that prints ascii character of number on top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((temp->n < 0) || (temp->n > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * pstr - function that prints out string using ascci characterss of the numbers in stack
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
