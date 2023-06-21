#include "monty.h"
/**
 * pchar - prints the char at a the top
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isprint((*stack)->n))
	{
		fprintf(stdout, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - prints the string of list
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	UNUSED(line_number);
	while (tmp != NULL && tmp->n != 0 && isprint(tmp->n))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates to the left
 * @stack: monty stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int firstVal;

	UNUSED(line_number);
	tmp = *stack;
	if (tmp)
		firstVal = tmp->n;
	while (tmp != NULL)
	{
		if (tmp->next)
			tmp->n = tmp->next->n;
		else
			tmp->n = firstVal;
		tmp = tmp->next;
	}
}

/**
 * rotr - rotates to the right
 * @stack: monty stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int lastVal;

	UNUSED(line_number);
	if ((*stack) != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		lastVal = tmp->n;
		while (tmp->prev != NULL)
		{
			tmp->n = tmp->prev->n;
			tmp = tmp->prev;
		}
		tmp->n = lastVal;
	}
}

