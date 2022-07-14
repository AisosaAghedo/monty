#include "monty.h"
#include "monty.h"

/* global struct to hold flag for queue and stack length */
var_t var;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;
	char *lineptr = NULL, *op = NULL;
	int n = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr);
	on_exit(free_stack);
	on_exit(m_fs_close);
	while (fgets(lineptr, n, fs) != NULL)
	{
	
		line_number++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
