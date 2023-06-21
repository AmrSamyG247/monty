#include "monty.h"

/**
 * mod - divides top two elements in the stack
 * @stack: pointer to a pointer to the top of the stack
 * @line_number: line number
 * Return: No Value
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n % (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * pchar - prints character based on ascii value at top of stack
 * @stack: pointer to pointer to first node of stack"
 * @line_number: line number
 * Return: No Value
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (((*stack)->n > 127) || ((*stack)->n < 0))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints string of ascii values defined by nodes in LL
 * @stack: a pointer to a pointer to the first node in the stack
 * @line_number: line number
 * Return: No Value
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	for (tmp = *stack; tmp; tmp = tmp->next)
	{
		if (tmp->n == 0)
			break;
		else if ((tmp->n > 127) || (tmp->n < 0))
			break;
		else
			printf("%c", tmp->n);
	}
	printf("\n");
}

/**
 * rotl - top element becomes last second becomes top
 * @stack: top of the stack - doubly linked list
 * @line_n: line number
 */
void rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *last = *stack, *head = *stack;

	if (line_n)
		line_n = line_n;
	if (head && head->next)
	{
		*stack = head->next;
		(*stack)->prev = NULL;
		for (; last->next; last = last->next)
			;
		last->next = head;
		head->next = NULL;
		head->prev = last;
	}
}

/**
 * rotr - last element becomes top
 * @stack: top of the stack - doubly linked list
 * @line_n: line number
 */
void rotr(stack_t **stack, unsigned int line_n)
{
	stack_t *last = *stack;

	if (line_n)
		line_n = line_n;
	if (*stack && (*stack)->next)
	{
		for (; last->next; last = last->next)
			;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

