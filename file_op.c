#include "monty.h"

void get_file(char *fname, stack_t **stack)
{
	FILE *fp;
	char *inbuffer = NULL, *token = NULL;
	size_t inbufsize = 0;
	int l_num = 1;
	opcode_fn ret;


	fp = fopen(fname, "r");
	err_fn_file(fp, fname, stack);

	while (getline(&inbuffer, &inbufsize, fp) != -1)
	{
		token = get_line(inbuffer);
		if (token == NULL || token[0] == '#')
		{
			l_num++;
			continue;
		}
		ret = get_opcode(token);
		if (ret == NULL)
		{
			printf("L%d: unknown instruction %s\n", l_num, token);
			exit_stack_err(stack);
		}
		ret(stack, l_num);
		l_num++;
	}
	free(inbuffer);
	if (fclose(fp) == -1)
		exit (-1);
}

char *get_line(char *token)
{
	char *op_code_str;

	op_code_str = strtok(token, "\n ");
	if (op_code_str == NULL)
		return (NULL);
	return (op_code_str);
}

opcode_fn get_opcode(char *token)
{
	int n = 0;

	instruction_t opcodes_list[] = {
		{"push", push_fn},
		{"pall", pall_fn},
		{NULL, NULL}};
	while (opcodes_list[n].f != NULL && strcmp(opcodes_list[n].opcode, token) != 0)
		n++;
	return (opcodes_list[n].f);
}
