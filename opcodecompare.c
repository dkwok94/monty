#include "monty.h"
/**
 *opcodecompare - compares opcodes and runs associated functions
 *@line_number: line number of command
 *
 *Return: void
 */
void opcodecompare(unsigned int line_number, char *opcode)
{
	int i = 0;
	stack_t *stack = NULL;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (_strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(&stack, line_number);
			return;
		}
		i++;
	}

	printf("L%u: unknown instruction %s\n", line_number, opcode);
	exit (EXIT_FAILURE);
}
