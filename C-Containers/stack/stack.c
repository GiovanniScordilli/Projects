#include "stack.h"

size_t size(stack *node)
{
    size_t size = 0;
    while (node != NULL)
    {
        ++size;
        node = node->next;
    }
    return size;
}

bool is_empty(stack *node)
{
    if (node == NULL) return true;
    else return false;
}

stack* create_node(double node_value)
{
    stack *new_node = (stack*)malloc(sizeof(stack));
    new_node->value = node_value;
    new_node->next = NULL;

    return new_node;
}

void push(stack **node, double node_value)
{
    stack *new_node = create_node(node_value);
    new_node->next = *node;
    *node = new_node;
}

void pop(stack **node)
{
    if(!is_empty(*node))
    {
        stack *tmp = *node;
        *node = tmp->next;
        free(tmp);
    }
}

void print_stack(stack *node)
{
    stack *temp = node;

    while (temp != NULL)
    {
        printf("%g ", temp->value);
        temp = temp->next;
    }
    printf("\n");
} 