#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

struct node
{
    double value;
    struct node *next;
};
typedef struct node list_node;

list_node* create_node(double node_value);

size_t size(list_node *head);
bool is_empty(list_node *head);

void insert_at_head(list_node **head, double node_value);
void insert_at_end(list_node **head, double node_value);
void insert_at_positon(list_node **head, double node_value, size_t position);

void delete_at_head(list_node **head);
void delete_at_end(list_node **head);
void delete_at_position(list_node **head, size_t position);

#endif
