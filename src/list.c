#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "list.h"

#define T list_t

struct T {
    struct node {
        void *data;
        struct node *prev, *next;
    } *head, *tail;
    
    int size;
};

T list_create(void *data, ...){
    T list;
    va_list ap;
    struct node **p;

    if((list = (T)malloc(sizeof(struct T))) == NULL){
        return NULL;
    }

    list->head = list->tail = NULL;
    list->size = 0;

    va_start(ap, data);

    for(p = &list->head; data; data = va_arg(ap, void*)) {
        *p = (struct node*)malloc(sizeof(struct node));
        (*p)->data = data;
        (*p)->prev = list->tail;
        list->tail = *p;
        p = &(*p)->next;
        list->size++;
    }

    *p = NULL;
    va_end(ap);
    return list;
}

void list_destroy(T list){
    struct node *curr, *next;
    
    assert(list);

    for(curr = list->head; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    free(list);
}

void list_clean(T list){
    struct node *curr, *next;
    
    assert(list);

    for(curr = list->head; curr; curr = next){
        next = curr->next;
        free(curr);
    }

    list->size = 0; 
}

int list_empty(const T list){
    assert(list);

    return list->size == 0;
}

int list_size(const T list){
    assert(list);

    return list->size;
}

void *list_front(const T list){
    assert(list);
    assert(list->size > 0);

    return list->head->data;
}

void *list_back(const T list){
    assert(list);
    assert(list->size > 0);
    
    return list->tail->data;
}

void list_push_front(T list, void *data){
    struct node *head, **p;

    assert(list);
    head = list->head;
    p = &list->head;
    *p = (struct node*)malloc(sizeof(struct node));
    (*p)->data = data;
    (*p)->next = head;
    (*p)->prev = NULL;

    if(head != NULL){
        head->prev = *p;
    }

    if(list->tail == NULL){
        list->tail = *p;
    }

    list->size++;
}

void list_push_back(T list, void *data){
    struct node *tail, **p;

    assert(list);
    tail = list->tail;
    p = &list->tail;
    *p = (struct node*)malloc(sizeof(struct node));
    (*p)->data = data;
    (*p)->prev = tail;
    (*p)->next = NULL;

    if(tail != NULL){
        tail->next = *p;
    }

    if(list->head == NULL){
        list->head = *p;
    }

    list->size++;
}

void *list_pop_back(T list){
    void *data;
    struct node *p;

    assert(list);
    assert(list->size > 0);

    p = list->tail;
    data = p->data;
    list->tail = p->prev;
    if(list->tail == NULL){
        list->head = NULL;
    }
    free(p);
    list->size--;
    return data;
}

void *list_pop_front(T list){
    void *data;
    struct node *p;

    assert(list);
    assert(list->size > 0);

    p = list->head;
    data = p->data;
    list->head = p->next;
    if(list->head == NULL){
        list->tail = NULL;
    }
    free(p);
    list->size--;
    return data;
}

void list_reverse(T list){
    struct node *head, *tail, *curr, *next;

    assert(list);
    head = NULL;
    tail = list->head;
    for(curr = list->head; curr; curr = next){
        next = curr->next;
        curr->prev = next;
        curr->next = head;
        head = curr;
    }

    list->head = head;
    list->tail = tail;
}

T list_copy(const T list){
    T clone;
    struct node *p, **n;

    assert(list);
    clone = (T)malloc(sizeof(struct T));
    clone->head = clone->tail = NULL;
    clone->size = 0;

    for(p = list->head, n = &clone->head; p; p = p->next){
        *n = (struct node*)malloc(sizeof(struct node));
        (*n)->data = p->data;
        (*n)->prev = clone->tail;
        clone->tail = *n;
        n = &(*n)->next;
    }

    *n = NULL;
    clone->size = list->size;
    return clone;
}

void list_append(T list, T tail){
    assert(list);
    assert(tail);

    if(list_empty(list)){
        list->head = tail->head;
    }else{
        list->tail->next = tail->head;
    }
    list->size += tail->size;

    free(tail);
}

void **list_to_array(const T list){
    int i, n;
    void **array;
    struct node *curr;

    assert(list);
    n = list_size(list);

    array = malloc(n * sizeof(void*));

    for(curr = list->head, i = 0; i < n; i++){
        array[i] = curr->data;
        curr = curr->next;
    }

    return array;
}