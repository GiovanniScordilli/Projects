#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct node
{
    double value;
    struct node *next;
};
typedef struct node stack;

size_t size(stack *node);
bool is_empty(stack *node);

stack* create_node(double node_value);
void push(stack **node, double element_value);
void pop(stack **node);

void print_stack(stack *node);

#endif