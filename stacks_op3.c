#include "monty.h"

/**
 * mod_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void mod_stack_nodes(stack_t **stack, unsigned int l_num)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_switch_2(8, l_num, "mod");


	if ((*stack)->n == 0)
		err_switch_2(9, l_num);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * push_queue - Add node to queue.
 * @queue: Pointer to the new node.
 * @l_num: line number of the opcode.
 */
void push_queue(stack_t **queue, unsigned int l_num)
{
	stack_t *hold;

	(void) l_num;
	if (queue == NULL || *queue == NULL)
		exit(EXIT_FAILURE);
	if (h == NULL)
	{
		h = *queue;
		return;
	}
	hold = h;
	while (hold->next != NULL)
		hold = hold->next;

	hold->next = *queue;
	(*queue)->prev = hold;

}
