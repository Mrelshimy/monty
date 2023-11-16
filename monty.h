#ifndef MONTY_H
#define MONTY_H


#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *h;
stack_t *start_node(int i);
typedef void (*opcode_fn)(stack_t **, unsigned int);

void get_file(char *fname);
int tokenizer(char *buffer, int l_num, int sorq);
void get_file_line(FILE *);
void get_opcode(char *, char *, int, int);
void free_stack(void);
void pall_stack(stack_t **, unsigned int);
void push_stack(stack_t **, unsigned int);
void push_queue(stack_t **, unsigned int);
void execute_op(opcode_fn, char *, char *, int, int);
void pint_stack(stack_t **, unsigned int);
void pop_stack(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_stack_nodes(stack_t **, unsigned int);
void add_stack_nodes(stack_t **, unsigned int);
void sub_stack_nodes(stack_t **, unsigned int);
void div_stack_nodes(stack_t **, unsigned int);
void mul_stack_nodes(stack_t **, unsigned int);
void mod_stack_nodes(stack_t **, unsigned int);
void err_switch_1(int err_id, ...);
void err_switch_2(int err_id, ...);

#endif
