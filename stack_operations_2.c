#include "monty.h"

/**
 * eval - evaluate operation
 * @line: line of input to parse
 * @h: head of doubly linked list
 * @t: tail of doubly linked list
 * @mode: stack or queue mode
 * @ln: line number being evaluated
 */
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln)
{
	cmd_t cmd;

	cmd.mode = mode;
	cmd.line_number = ln;
	cmd.head = h;
	cmd.tail = t;

	if (parse(line, &cmd))
		run(&cmd);
}

/**
 * free_list - free's a stack
 * @head: pointer to head
 */
void free_list(stack_t **head)
{
	stack_t *runner;
	stack_t *tmp;

	if (*head)
	{
		runner = *head;
		*head = NULL;

		while (runner->next)
		{
			tmp = runner;
			runner = runner->next;
			free(tmp);
		}
		free(runner);
	}
}

