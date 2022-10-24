#ifndef STACK_H
#define STACK_H

#define T stack_t
typedef struct T *T;

extern T stack_create();
extern void stack_destroy(T stack);
extern void stack_clean(T stack);
extern int stack_empty(T stack);
extern int stack_size(T stack);
extern void *stack_top(T stack);
extern void stack_push(T stack, const void *data);
extern void *stack_pop(T stack);

#undef T
#endif
