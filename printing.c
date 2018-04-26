#include "monty.h"
/**
 *pall - prints all values starting from the top of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *iterator;

	iterator = *stack;
	if (*stack == NULL)
		return;
	while (iterator != NULL)
	{
		printf("%d\n", iterator->n);
		iterator = iterator->next;
	}
}
/**
 *pint - prints the top value of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
