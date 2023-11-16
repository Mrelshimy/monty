#include "monty.h"

/**
 * err_switch_1 - Prints error messages determined by code.
 * @err_id: The error codes are the following:
 */

void err_switch_1(int err_id, ...)
{
	va_list argv;
	char *op_code;
	int l_num;

	va_start(argv, err_id);
	switch (err_id)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(argv, char *));
			break;
		case 3:
			l_num = va_arg(argv, int);
			op_code = va_arg(argv, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argv, int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * err_switch_2 - more errors.
 * @err_id: error code
 */
void err_switch_2(int err_id, ...)
{
	va_list argv;
	char *op_code;
	int l_num;

	va_start(argv, err_id);
	switch (err_id)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(argv, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(argv, int));
			break;
		case 8:
			l_num = va_arg(argv, unsigned int);
			op_code = va_arg(argv, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(argv, unsigned int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
