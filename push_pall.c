#include "monty.h"

/**
 * digit_check - function that checks if a string only contains digits
 * @str: string to be checked
 * Return: 0 if str contaons only digits, else 1
 */
static int digit_check(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: nothing
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int i;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || digit_check(arg))
	{
		fprintf(stdout,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(arg);
	if (!add_node(stack, i))
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
 * m_pall - prints all values on the stack starting from the top
 * @top: double pointer to head of stack
 * @line_number: line number being executed from script file
 * Return: void
 */
void m_pall(stack_t **top, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *top;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *top)
		{
			return;
		}
	}
}
