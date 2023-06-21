#ifndef AMR_A_
#define AMR_A_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct cmd_s - command struct
 * @op: name of operation
 * @arg: argument for function
 * @mode: stack or queue mode
 * @line_number: number of line being evaluated
 * @head: head of linked list
 * @tail: tail of linked list
 */
typedef struct cmd_s
{
	char *op;
	int arg;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;
} cmd_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(cmd_t *cmd);
} instruction_t;

/*******parse_line_cmd*******/
int parse(char *line, cmd_t *cmd);

/***data_structures_run_cmd.c**/
void run(cmd_t *cmd);

/*******stack_functions_1*******/
void push(cmd_t *cmd);
void pop(cmd_t *cmd);
void swap(cmd_t *cmd);
void rotl(cmd_t *cmd);
void rotr(cmd_t *cmd);


/*******stack_functions_2*******/
void pall(cmd_t *cmd);
void pint(cmd_t *cmd);
void pchar(cmd_t *cmd);
void pstr(cmd_t *cmd);
void nop(cmd_t *cmd);

/*******stack_operations_1*******/
void add(cmd_t *cmd);
void sub(cmd_t *cmd);
void divide(cmd_t *cmd);
void mul(cmd_t *cmd);
void mod(cmd_t *cmd);

/*******stack_operations_2*******/
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln);
void free_list(stack_t **head);

/*******lifo_fifo_func*******/
void stack_mode(cmd_t *cmd);
void queue_mode(cmd_t *cmd);

#endif

