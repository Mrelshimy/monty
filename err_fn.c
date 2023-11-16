#include "monty.h"

void err_fn_args(int argc, stack_t **stack)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_stack_err(stack);
	}
}

void err_fn_file(FILE *fp, char *argv, stack_t **stack)
{
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit_stack_err(stack);
	}
}

void exit_stack_err(stack_t **stack)
{
	if (*stack)
		free_stack(*stack);
	exit(EXIT_FAILURE);
}
