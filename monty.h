#ifndef AMR_A_
#define AMR_A_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - input buffer, push integer, and token opcode
 * @ipt: buffer with file info
 * @iptint: integer for push when called
 * @tokop: token of opcode
 * Description: input and token buffers along with integer for push
 * for stack, queues, LIFO, FIFO  Project
 */
typedef struct global_s
{
	char *ipt;
	int iptint;
	char *tokop;
} glo_t;

extern glo_t *glo;


/*******stack_functions_1*******/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);


/*******stack_functions_2*******/
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/*******stack_operations_1*******/
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*******stack_operations_2*******/
int bc_exe(char *ipt, stack_t **stack);
size_t print_stack(const stack_t *h);
void free_exit_ui(stack_t *stack, unsigned int lnum, char *mssg);
void free_exit(stack_t *stack, unsigned int lnum, char *mssg);
int nl_count(char *tok);
char *tokop_init(char *tok, int tok_offset);

/*******lifo_fifo_func and data_structure*******/
void free_stack(stack_t *head);
char *read_file(int fd);
void push_check(int toklenx, char *tok, stack_t *stack, int lnum);
bool comment_check(unsigned int *lnum, int i, char **tok);
void queue(stack_t **stack, unsigned int line_n);

#endif

