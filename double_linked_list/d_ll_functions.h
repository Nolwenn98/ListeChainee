#ifndef LIST_DOUBLE_HEADER
#define LIST_DOUBLE_HEADER

typedef struct double_linked_list double_linked_list;
struct double_linked_list
{
    int number;
    double_linked_list *prev;
    double_linked_list *next;
};

double_linked_list *d_ll_get_new_elem(int data);
void d_ll_push_elem(double_linked_list *list, double_linked_list *elem);
void d_ll_pop(double_linked_list **list);
void d_ll_free(double_linked_list **list);
void d_ll_print(double_linked_list *list);
int d_ll_length(double_linked_list *list);
int d_ll_add_index(double_linked_list **list, int index, double_linked_list *elem);

#endif