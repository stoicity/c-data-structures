#include <stdlib.h>
#include <assert.h>

#include "queue.h"

#define T queue_t

/* Define a struct for queue */

/* Queue implemented as a linked list */
struct T {
    struct node {
        void *data;
        struct node *next;
    } *head, *tail;

    int size; 
};

T queue_create(){
    T queue;

    if((queue = (T)malloc(sizeof(struct T))) == NULL){
        return NULL;
    }

    queue->head = queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(T queue){
    struct node *next, *curr;
    
    assert(queue);

    for(curr = queue->head; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    free(queue);
}

void queue_clean(T queue){
    struct node *next, *curr;
    
    assert(queue);

    for(curr = queue->head; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    queue->head = queue->tail = NULL;
    queue->size = 0;
}

int queue_empty(const T queue){
    assert(queue);

    return queue->size == 0;
}

int queue_size(const T queue){
    assert(queue);
    
    return queue->size;
}

void *queue_head(const T queue){
    assert(queue);
    assert(queue->size > 0);

    return queue->head->data;
}

void *queue_tail(const T queue){
    assert(queue);
    assert(queue->size > 0);

    return queue->tail->data;
}

void queue_enqueue(T queue, const void *data){
    struct node *new;

    assert(queue);
    
    new = (struct node*)malloc(sizeof(struct node));
    assert(new);
    
    new->data = (void*)data;
    new->next = NULL;

    if(queue->tail == NULL){
        queue->head = queue->tail = new;
    
    }else{
        queue->tail->next = new;
        queue->tail = new;
    }

    queue->size++;
}

void *queue_dequeue(T queue){
    void *data;
    struct node *node;

    assert(queue);
    assert(queue->size > 0);

    node = queue->head;
    queue->head = node->next;
    
    if(queue->head == NULL){
        queue->tail = NULL;
    }
    
    queue->size--;
    
    data = node->data;
    free(node);

    return data; 
}
