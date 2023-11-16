#include "monty.h"

void free_stack(stack_t *head)
{
	stack_t *hold;

	while (head != NULL)
	{
		hold = head;
		head = head->next;
		free(hold);
	}
}

stack_t *add_dnode_beg(stack_t **h, const int n)
{
	stack_t *nnode;
	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
		return (NULL);
	if (*h == NULL)
	{
		nnode->n = n;
		nnode->next = NULL;
		nnode->prev = NULL;
		*h = nnode;
		return (*h);
	}
	(*h)->prev = nnode;
	nnode->n = n;
	nnode->next = *h;
	nnode->prev = NULL;
	*h = nnode;
	return (*h);
}

stack_t *add_dnode_end(stack_t **h, const int n)
{
	stack_t *hold = *h;
	stack_t *nnode;

	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
		return (NULL);
	nnode->n = n;
	if (*h == NULL)
	{
		nnode->next = NULL;
		nnode->prev = NULL;
		*h = nnode;
		return (nnode);
	}
	while (hold->next != NULL)
	{
		hold = hold->next;
	}
	hold->next = nnode;
	nnode->prev = hold;
	nnode->next = NULL;
	return (nnode);
}
