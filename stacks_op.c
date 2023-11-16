#include "monty.h"


/**
 * push_stack - Adds node to stack.
 * @nnode: Pointer to new node.
 * @l_num: line number of opcode.
 */
void push_stack(stack_t **nnode, unsigned int l_num)
{
	stack_t *hold;

	(void) l_num;
	if (nnode == NULL || *nnode == NULL)
		exit(EXIT_FAILURE);
	if (h == NULL)
	{
		h = *nnode;
		return;
	}
	hold = h;
	h = *nnode;
	h->next = hold;
	hold->prev = h;
}


/**
 * pall_stack - print all stack items.
 * @stack: Pointer to stack top.
 * @l_num: line number of  the opcode.
 */
void pall_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *hold;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	hold = *stack;
	while (hold != NULL)
	{
		printf("%d\n", hold->n);
		hold = hold->next;
	}
}

/**
 * pop_stack - print stack top node.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void pop_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *hold;

	if (stack == NULL || *stack == NULL)
		err_switch_2(7, l_num);

	hold = *stack;
	*stack = hold->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(hold);
}

/**
 * pint_stack - Prints the top node of the stack.
 * @stack: Pointer to stack top.
 * @l_num: line number of opcode.
 */
void pint_stack(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		err_switch_2(6, l_num);
	printf("%d\n", (*stack)->n);
}

/**
 * nop - nothing.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void nop(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}
