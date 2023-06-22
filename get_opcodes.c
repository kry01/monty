#include "monty.h"

/**
 * op_getter - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*op_getter(char *opc))(stack_t **stack, unsigned int line_number)
{
	insc_t instruct[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"queue", my_queue},
		{"stack", my_stack},
		{"add", my_add},
		{"nop", my_nop},
		{"sub", my_sub},
		{"mul", my_mul},
		{"div", my_div},
		{"mod", my_mod},
		{"pchar", my_pchar},
		{"pstr", my_pstr},
		{"rotl", my_rotl},
		{"rotr", my_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
