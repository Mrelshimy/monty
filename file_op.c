#include "monty.h"

/**
 * get_file - open file
 * @fname: file name
 */

void get_file(char *fname)
{
	FILE *fp = fopen(fname, "r");

	if (fname == NULL || fp == NULL)
		err_switch_1(2, fname);
	get_file_line(fp);
	fclose(fp);
}


/**
 * get_file_line - read file line by line
 * @fp: file pointer
 */

void get_file_line(FILE *fp)
{
	int l_num, format = 0;
	char *inbuffer = NULL;
	size_t inbufsize = 0;

	for (l_num = 1; getline(&inbuffer, &inbufsize, fp) != -1; l_num++)
	{
		format = tokenizer(inbuffer, l_num, format);
	}
	free(inbuffer);
}

/**
 * tokenizer - line into tokens
 * @inbuffer: line from the file
 * @l_num: line number
 * @sorq:  If 0 nodes will be stack , 1 queue.
 * Return: 0 if opcode is stack, 1 if queue.
 */

int tokenizer(char *inbuffer, int l_num, int sorq)
{
	char *op_code, *token;
	const char *delim = "\n ";

	if (inbuffer == NULL)
		err_switch_1(4);

	op_code = strtok(inbuffer, delim);
	if (op_code == NULL)
		return (sorq);
	token = strtok(NULL, delim);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);
	get_opcode(op_code, token, l_num, sorq);
	return (sorq);
}

/**
 * get_opcode - find the required fn for the opcode
 * @op_code: opcode
 * @op_val: argument of opcode
 * @sorq:  If 0 nodes will be stack , 1 queue.
 * @l_num: line number
 */

void get_opcode(char *op_code, char *op_val, int l_num, int sorq)
{
	int n;
	int m;
	instruction_t op_code_list[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"nop", nop},
		{"swap", swap_stack_nodes},
		{"add", add_stack_nodes},
		{"sub", sub_stack_nodes},
		{"div", div_stack_nodes},
		{"mul", mul_stack_nodes},
		{"mod", mod_stack_nodes},
		/*{"pchar", print_char},*/
		/* {"pstr", print_str},*/
		/* {"rotl", rotl},*/
		/* {"rotr", rotr},*/
		{NULL, NULL}
	};
	if (op_code[0] == '#')
		return;
	for (m = 1, n = 0; op_code_list[n].opcode != NULL; n++)
	{
		if (strcmp(op_code, op_code_list[n].opcode) == 0)
		{
			execute_op(op_code_list[n].f, op_code, op_val, l_num, sorq);
			m = 0;
		}
	}
	if (m == 1)
		err_switch_1(3, l_num, op_code);
}


/**
 * execute_op - Calls the required function.
 * @op_func: Pointer to called function
 * @op_code: opcode.
 * @op_val: stack new value.
 * @l_num: line number
 * @sorq: If 0 nodes will be stack , 1 queue.
 */
void execute_op(opcode_fn op_func,
		char *op_code, char *op_val, int l_num, int sorq)
{
	stack_t *nnode;
	int m;
	int n;

	m = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (op_val != NULL && op_val[0] == '-')
		{
			op_val = op_val + 1;
			m = -1;
		}
		if (op_val == NULL)
			err_switch_1(5, l_num);
		for (n = 0; op_val[n] != '\0'; n++)
		{
			if (isdigit(op_val[n]) == 0)
				err_switch_1(5, l_num);
		}
		nnode = start_node(atoi(op_val) * m);
		if (sorq == 0)
			op_func(&nnode, l_num);
		if (sorq == 1)
			push_queue(&nnode, l_num);
	}
	else
		op_func(&h, l_num);
}
