#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <float.h>

struct node
{
    double value;
    struct node *next;
};
typedef struct node node;

struct queue
{
    node *head;
    node *tail;
};
typedef struct queue queue;

size_t size(queue *queue_);
bool is_empty(queue *queue_);

void init_queue(queue **queue_);
node* create_node(double node_value);
bool check_allocation(node *node_);

void push(queue *queue_, double node_value);
void pop(queue *queue_);

double front(queue *queue_);
double back(queue *queue_);

#endif