#include "monty.h"

void push_fn(stack_t **stack, unsigned int l_num)
{
	stack_t *nnode;
	char *opcode_arg;
	int int_arg = 0;

	nnode = malloc(sizeof(stack_t));
	if (!nnode)
	{
		printf("Error: malloc failed\n");
		exit_stack_err(stack);
	}

	opcode_arg = strtok(NULL, "\n ");
	if (is_number(opcode_arg) == 1 && opcode_arg != NULL)
		int_arg = atoi(opcode_arg);
	else
	{
		printf("L%d: usage: push integer\n", l_num);
		exit_stack_err(stack);
	}

	if (sorq == 1)
	{
		add_dnode_end(stack, int_arg);
	}
	if (sorq == 0)
	{
		add_dnode_beg(stack, int_arg);
	}
}

void pall_fn(stack_t **stack, unsigned int l_num)
{
	stack_t *hold;

	(void) l_num;
	hold = *stack;
	while (hold != NULL)
	{
		printf("%d\n", hold->n);
		hold = hold->next;
	}
}

int is_number(char *str)
{
	unsigned int n = 0;

	if (str == NULL)
		return (0);

	while (str[n])
	{
		if (str[0] == '-')
		{
			n++;
			continue;
		}
		if (!isdigit(str[n]))
			return (0);
		n++;
	}
	return (1);
}
