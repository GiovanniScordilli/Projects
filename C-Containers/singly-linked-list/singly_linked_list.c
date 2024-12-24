#include "singly_linked_list.h"

list_node* create_node(double node_value)
{
    list_node *node = (list_node*)malloc(sizeof(list_node));
    node->value = node_value;
    node->next = NULL;

    return node;
}

size_t size(list_node *head)
{
    list_node *temp = head;
    size_t size = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

bool is_empty(list_node *head)
{
    if (head == NULL) return true;
    else return false;
}

void insert_at_head(list_node **head, double node_value)
{
    list_node *new_node = create_node(node_value);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(list_node **head, double node_value)
{
    list_node *new_node = create_node(node_value);
    list_node *tmp = *head;

    if(is_empty(*head))
    {
        *head = new_node;
    }
    else 
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

void insert_at_positon(list_node **head, double node_value, size_t position)
{
    if (position == 0) insert_at_head(head, node_value);
    if (position == size(*head)) insert_at_end(head, node_value);
    else if (position > size(*head)) return;
    else 
    {
        list_node *new_node = create_node(node_value);
        list_node *temp = *head;

        for (size_t i = 0; i < position - 1 && temp->next != NULL; ++i)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_head(list_node **head)
{
    if (!is_empty(*head))
    {
        list_node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void delete_at_end(list_node **head)
{
    if (!is_empty(*head))
    {
        list_node *temp = *head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_position(list_node **head, size_t position)
{
    if (position == 0) delete_at_head(head);
    else if (position == (size(*head) - 1)) delete_at_end(head);
    else if (position >= size(*head)) return;
    else 
    {
        if (!is_empty(*head))
        {
            list_node *temp = *head;
            size_t temp_position = 0;

            while (temp_position != (position - 1))
            {
                temp = temp->next;
                temp_position++;
            }
            
            list_node *temp_next = temp->next->next;
            free(temp->next);
            temp->next = temp_next;
        }
    }
}

void print_list(list_node *head)
{
    list_node *temp = head;

    while (temp != NULL)
    {
        printf("%g ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}