#ifndef QUEUE_H
#define QUEUE_H

#define T queue_t
typedef struct T *T;

extern T queue_create();
extern void queue_destroy(T queue);
extern void queue_clean(T queue);
extern int queue_empty(const T queue);
extern int queue_size(const T queue);
extern void *queue_head(const T queue);
extern void *queue_tail(const T queue);
extern void queue_enqueue(T queue, const void *data);
extern void *queue_dequeue(T queue);

#undef T
#endif