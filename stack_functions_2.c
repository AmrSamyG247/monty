#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int summ;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	summ = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = summ;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int swapper;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swapper = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swapper;
}

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

