#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "d_ll_functions.h"

double_linked_list *d_ll_get_new_elem(int data)
{
    double_linked_list *new_elem = malloc(sizeof(*new_elem));
    if (new_elem == NULL)
    {
        exit(1);
    }

    new_elem->number = data;
    new_elem->next = NULL;
    new_elem->prev = NULL;

    return new_elem;
}

void d_ll_push_elem(double_linked_list *list, double_linked_list *elem)
{
    if (list->next == NULL)
    {
        elem->prev = list;
        list->next = elem;
    }
    else
        d_ll_push_elem(list->next, elem);
}

void d_ll_pop(double_linked_list **list)
{
    double_linked_list *ptr = *list;
    *list = (*list)->next;
    if ((*list) != NULL)
    {
        (*list)->prev = NULL;
    }

    free(ptr);
}

void d_ll_free(double_linked_list **list)
{
    while ((*list)->next != NULL)
    {
        d_ll_pop(list);
    }

    d_ll_pop(list);
}

void d_ll_print(double_linked_list *list)
{
    double_linked_list *ptr = list;
    int i = 0;

    while (ptr != NULL && i < 10)
    {
        printf("%d => %d \n", i, ptr->number);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
}

int d_ll_length(double_linked_list *list)
{
    if (list == NULL)
    {
        return 0;
    }
    else if (list->next == NULL)
    {
        return 1;
    }
    return (1 + d_ll_length(list->next));
}

void d_ll_add_index(double_linked_list **list, int index, double_linked_list *elem)
{
    int length = d_ll_length(*list);
    if (index > length)
    {
        printf("Ajout impossible !");
        exit(1);
    }

    double_linked_list *ptr_next;
    double_linked_list *ptr_prev = *list;

    for (int i = 0; i < index - 1; i++)
    {
        ptr_prev = ptr_prev->next;
    }
    ptr_next = ptr_prev->next;
    elem->next = ptr_next;
    elem->prev = ptr_prev;
    ptr_prev->next = elem;
}