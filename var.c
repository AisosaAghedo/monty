#include "monty.h"

/* global struct to hold flag for queue and stack length */
var_t var;

/**
 * main - function that acts as Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fs = NULL;

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
	exit(EXIT_SUCCESS);
}
