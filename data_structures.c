#include "monty.h"

/**
 * free_stack - frees a stack_t list.
 * @head: a pointer to the head
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (!head)
		return;

	next = head;
	while (next)
	{
		head = next;
		next = head->next;
		free(head);
	}
}

/**
 * get_opcode - gets the opcode and sets push_arg if it's push
 * @string: the line of code
 *
 * Return: the opcode
 */
char *get_opcode(char *string)
{
	char *opcode;

	/** grabs first argument **/
	opcode = strtok(string, "\n\t ");
	return (opcode);
}

/**
 * is_int - checks if a string is valid for atoi
 * @str: the string
 *
 * Return: 1 for true, 0 for false
 */
int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (*str == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

