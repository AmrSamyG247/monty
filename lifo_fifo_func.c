#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: a pointer to the first node in the list
 * Return: No Value
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	for (; head->next; head = head->next)
	{
		if (head->prev)
			free(head->prev);
	}
	free(head->prev);
	free(head);
}

/**
 * queue - flips the doubly linked list
 * @stack: top of the stack - doubly linked list
 * @line_n: line number
 */
void queue(stack_t **stack, unsigned int line_n)
{
	stack_t *flip = *stack, *hold = *stack;

	if (line_n)
		line_n = line_n;
	if (*stack && ((*stack)->next))
	{
		while (1)
		{
			hold = flip->next;
			flip->next = flip->prev;
			flip->prev = hold;
			if (hold != NULL)
				flip = hold;
			else
				break;
		}

		*stack = flip;
	}
}

