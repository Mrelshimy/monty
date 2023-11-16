#include "monty.h"

/**
 * start_node - Create node.
 * @i: node data.
 * Return: pointer to node, if fail NULL.
 */
stack_t *start_node(int i)
{
	stack_t *nnode;

	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
		err_switch_1(4);
	nnode->next = NULL;
	nnode->prev = NULL;
	nnode->n = i;
	return (nnode);
}

/**
 * free_stack - Free all stack nodes.
 */
void free_stack(void)
{
	stack_t *hold;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		hold = h;
		h = h->next;
		free(hold);
	}
}
