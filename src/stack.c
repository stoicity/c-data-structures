#include <stdlib.h>
#include <assert.h>

#include "stack.h"

#define T stack_t

/* Define a struct for stack */

/* Stack implemented as a linked list */
struct T {
    struct node {
        void *data;
        struct node *next;
    } *top; 

    int size;
};

T stack_create(){
    T stack;

    if((stack = (T)malloc(sizeof(struct T))) == NULL){
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void stack_destroy(T stack){
    struct node *next, *curr;
    
    assert(stack);

    for(curr = stack->top; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    free(stack);
}

void stack_clean(T stack){
    struct node *next, *curr;
    
    assert(stack);

    for(curr = stack->top; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    stack->top = NULL;
    stack->size = 0;
}

int stack_empty(const T stack){
    assert(stack);

    return stack->size == 0;
}

int stack_size(const T stack){
    assert(stack);

    return stack->size;
}


void *stack_top(const T stack){
    assert(stack);
    assert(stack->size > 0);

    return stack->top->data;
}

void stack_push(T stack, const void *data){
    struct node *new;
    
    assert(stack);
    
    new = (struct node*)malloc(sizeof(struct node));
    assert(new);
    
    new->data = (void*)data;
    new->next = stack->top;
    
    stack->top = new;
    stack->size++;
}

void *stack_pop(T stack){
    void *data;
    struct node *node;

    assert(stack);
    assert(stack->size > 0);
    
    node = stack->top;
    stack->top = node->next;
    stack->size--;

    data = node->data;
    free(node);

    return data;
}