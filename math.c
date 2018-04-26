#include "monty.h"
/**
 *add - adds the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;
	int nodes = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		nodes++;
		iterator = iterator->next;
	}
	if (nodes < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
