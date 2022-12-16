#ifndef LIST_H_
#define LIST_H_

#include <stdint.h>

#define LIST_NOT_FOUND (-1)

typedef struct _element
{
    void *data;
    struct _element *next;
    struct _element *previous;
} element_t;

typedef struct
{
    element_t *start;
    element_t *end;
} list_t;

typedef void (*list_map_func_t)(void *data);

#define LIST_INITIALIZER           \
    {                              \
        .start = NULL, .end = NULL \
    }

uint32_t list_length(list_t *list);
element_t *list_append(list_t *list, void *data);
element_t *list_prepend(list_t *list, void *data);
void *list_pop_first(list_t *list);
void *list_pop_last(list_t *list);
element_t *list_insert_at(list_t *list, void *data, uint32_t index);
void *list_remove_at(list_t *list, uint32_t index);
void list_map(list_t *list, list_map_func_t function);
int32_t list_index(list_t *list, void *value);

#endif /* LIST_H_ */