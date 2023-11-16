#include "monty.h"
int sorq = 0;

int main(int argc, char **argv)
{
	stack_t *nstack = NULL;

	err_fn_args(argc, &nstack);
	get_file(argv[1], &nstack);
	free_stack(nstack);
	return (0);
}
