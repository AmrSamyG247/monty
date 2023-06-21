#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}

/**
 * divide - divides the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int divs;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divs = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = divs;
}

/**
 * multiply - multiplies the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int mul;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = mul;
}

/**
 * mod - computes the modulus of the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int modd;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	modd = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = modd;
}

