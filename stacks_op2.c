#include "monty.h"

/**
 * swap_stack_nodes - Swap stack top two elements.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void swap_stack_nodes(stack_t **stack, unsigned int l_num)
{
	stack_t *hold;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_switch_2(8, l_num, "swap");
	hold = (*stack)->next;
	(*stack)->next = hold->next;
	if (hold->next != NULL)
		hold->next->prev = *stack;
	hold->next = *stack;
	(*stack)->prev = hold;
	hold->prev = NULL;
	*stack = hold;
}

/**
 * add_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void add_stack_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_switch_2(8, l_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void sub_stack_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_switch_2(8, l_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void div_stack_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_switch_2(8, l_num, "div");

	if ((*stack)->n == 0)
		err_switch_2(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to stack top
 * @l_num: line number of opcode.
 */
void mul_stack_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_switch_2(8, l_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
