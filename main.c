#include "monty.h"
stack_t *h = NULL;

/**
 * main - entry point
 * @ac: args count
 * @av: args list
 * Return: 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	get_file(av[1]);
	free_stack();
	return (0);
}
