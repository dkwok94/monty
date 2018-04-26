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
/**
 *pop - deletes the top value off of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 *swap - swaps the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;
	int nodes = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		nodes++;
		iterator = iterator->next;
	}
	if (nodes < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
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
	int sum = (*stack)->n + (*stack)->next->n;
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
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 *nop - does nothing
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	return;
}
