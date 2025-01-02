#include "queue.h"

size_t size(queue *queue_)
{
    size_t size = 0;
    if (queue_->head == NULL) return size;
    else 
    {
        while (queue_->head != NULL)
        {
            ++size;
            queue_->head = queue_->head->next;
        }
    
        return size;
    }   
}

bool is_empty(queue *queue_)
{
    if (queue_->head == NULL) return true;
    else return false;
}

void init_queue(queue **queue_)
{
    *queue_ = (queue*)malloc(sizeof(queue));
    (*queue_)->head = NULL;
    (*queue_)->tail = NULL;
}

node* create_node(double node_value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = node_value;
    new_node->next = NULL;

    return new_node;
}

bool check_allocation(node *node_)
{
    if (node_ == NULL) return false;
    else return true;
}

void push(queue *queue_, double node_value)
{
    node *new_node = create_node(node_value);

    if (!check_allocation(new_node)) return;
    if (queue_->tail == NULL && queue_->head == NULL)
    {
        queue_->tail = new_node;
        queue_->head = new_node;
        return;
    }

    queue_->tail->next = new_node;
    queue_->tail = new_node;
}

void pop(queue *queue_)
{
    if (is_empty(queue_)) return;
    node *tmp = queue_->head;
    queue_->head = queue_->head->next;
    free(tmp);
}

double front(queue *queue_)
{
    if (!is_empty(queue_)) return queue_->head->value;
    else return DBL_TRUE_MIN;
}

double back(queue *queue_)
{
    if (!is_empty(queue_)) return queue_->tail->value;
    else return DBL_TRUE_MIN;
}