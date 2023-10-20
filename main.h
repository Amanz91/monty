#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct parts - a struct to hold args, filename, and content
 * @arg: Value
 * @file: monty file pointer
 * @content: content of line
 */
typedef struct parts
{
	char *arg;
	FILE *file;
	char *content;
} part_s;
extern part_s part;

int f_run(char *content, stack_t **stack, unsigned int count, FILE *file);
void insert_node(stack_t **head, int n);
void push(stack_t **head, unsigned int count);
void free_stack(stack_t *head);
void pall(stack_t **head, __attribute__((unused))unsigned int count);
void pint(stack_t **head, unsigned int count);
void pop(stack_t **head, unsigned int count);
void swap(stack_t **head, unsigned int count);
void add(stack_t **head, unsigned int count);
void nop(stack_t **head, unsigned int count);
void sub(stack_t **head, unsigned int count);

#endif
