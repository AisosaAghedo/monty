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
 * fpush - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @number: script line number
 * Return: nothing
 */
void fpush(stack_t **stack, unsigned int number)
{
	char *arg;
	int i;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || digit_check(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			number);
		exit(EXIT_FAILURE);
	}
	i = atoi(arg);
	if (!add_node(stack, i))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
 * fpall - prints all values on the stack starting from the top
 * @top: double pointer to head of stack
 * @number: line number being executed from script file
 * Return: void
 */
void fpall(stack_t **top, unsigned int number)
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
