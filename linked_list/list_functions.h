#ifndef LIST_HEADER
#define LIST_HEADER

typedef struct Liste Liste;
struct Liste
{
    int number;
    Liste *next;
};

Liste *init_list(int data);
void ll_print(Liste *list);

void ll_get_new_elem(Liste *list, int data);

// void ll_push_elem(Liste *list, Liste *elem);

void ll_pop(Liste **list);
void ll_free(Liste **list);

int ll_length(Liste *list);
void ll_add_index(Liste **list, int index, Liste *elem);
int ll_get_value_index(Liste **list, int index);
void ll_swap_index(Liste **list, int index0, int index1);
void ll_reverse(Liste **list);

#endif