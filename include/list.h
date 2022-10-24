#ifndef LIST_H
#define LIST_H

#define T list_t
typedef struct T *T;

extern T list_create(void *data, ...);
extern void list_destroy(T list);
extern void list_clean(T list);
extern int list_empty(const T list);
extern int list_size(const T list);
extern void *list_front(const T list);
extern void *list_back(const T list);
extern void list_push_front(T list, void *data);
extern void list_push_back(T list, void *data);
extern void *list_pop_front(T list);
extern void *list_pop_back(T list);
extern void list_reverse(T list);
extern void list_append(T list, T tail);
extern T list_copy(const T list);
extern void **list_to_array(const T list);

#undef T 
#endif
