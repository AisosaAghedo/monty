#include "monty.h"

/**
 * free_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;
	stack_t *temp1 = NULL;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;

	while (temp != NULL)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
}

/**
 * is_a_num - checks if the second argument from file is a number
 * @argument2: second argument from file
 * Return: nothing
 */
void is_a_num(char *argument2)
{
	char *arg1 = strtok(argument2, " \n\t");
	char *arg2 = strtok(NULL, " \n\t");
	char str[25];
	int i = 0;
	int len = strlen(arg2);
	int check_for_num = 0, j = 0;

	(void) arg1;
	while (arg2[i] != '\0')
	{
		if (isdigit(arg2[i]) || (arg2[i] == '-' && isdigit(arg2[i + 1])))
		{
			str[j] = arg2[i];
			check_for_num++;
			j++;
		}
		i++;
	}
	str[j] = '\0';

	if (check_for_num == len)
	{
		info.is_digit = true;
		info.value = atoi(str);
	}

	else
	{
		info.is_digit = false;
	}
}
