#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} insc_t;

extern global_t vglo;

/* opcode_instructuions*/
void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **doubly, unsigned int cline);
void my_pop(stack_t **doubly, unsigned int cline);
void my_swap(stack_t **doubly, unsigned int cline);
void my_queue(stack_t **doubly, unsigned int cline);
void my_stack(stack_t **doubly, unsigned int cline);
void my_add(stack_t **doubly, unsigned int cline);
void my_nop(stack_t **doubly, unsigned int cline);
void my_sub(stack_t **doubly, unsigned int cline);
void my_div(stack_t **doubly, unsigned int cline);
void my_mul(stack_t **doubly, unsigned int cline);
void my_mod(stack_t **doubly, unsigned int cline);
void my_pchar(stack_t **doubly, unsigned int cline);
void my_pstr(stack_t **doubly, unsigned int cline);
void my_rotl(stack_t **doubly, unsigned int cline);
void my_rotr(stack_t **doubly, unsigned int cline);

/*get function*/
void (*op_getter(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

#endif
