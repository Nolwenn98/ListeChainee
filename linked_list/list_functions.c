#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_functions.h"

Liste *init_list(int data)
{
    Liste *first_element = malloc(sizeof(*first_element));
    if (first_element == NULL)
    {
        exit(1);
    }

    first_element->number = data;
    first_element->next = NULL;

    return first_element;
}

void ll_print(Liste *list)
{
    Liste *ptr = list;
    int i = 0;

    while (ptr != NULL && i < 10)
    {
        printf("%d => %d \n", i, ptr->number);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
}

// void ll_push_elem(Liste *list, Liste *elem){}
void ll_get_new_elem(Liste *list, int data)
{
    if (list->next == NULL)
    {
        Liste *ptr = malloc(sizeof(*ptr));
        ptr->number = data;
        ptr->next = NULL;
        list->next = ptr;
    }
    else
        ll_get_new_elem(list->next, data);
}

void ll_pop(Liste **list)
{
    Liste *ptr = *list;
    *list = (*list)->next;

    free(ptr);
}

void ll_free(Liste **list)
{
    while ((*list)->next != NULL)
    {
        ll_pop(list);
    }
    ll_pop(list);
}

int ll_length(Liste *list)
{
    if (list == NULL)
    {
        return 0;
    }
    else if (list->next == NULL)
    {
        return 1;
    }
    return (1 + ll_length(list->next));
}

void ll_add_index(Liste **list, int index, Liste *elem)
{
    int length = ll_length(*list);
    if (index > length)
    {
        printf("Ajout impossible !");
        exit(1);
    }

    Liste *ptr_next;
    Liste *ptr_prev = *list;

    for (int i = 0; i < index; i++)
    {
        ptr_prev = ptr_prev->next;
    }
    ptr_next = ptr_prev->next;
    elem->next = ptr_next;
    ptr_prev->next = elem;
}

int ll_get_value_index(Liste **list, int index)
{
    Liste *ptr = *list;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }
    return ptr->number;
}

void ll_swap_index(Liste **list, int index0, int index1)
{
    int length = ll_length(*list);
    if (index1 > length || index0 > length)
    {
        printf("Ajout impossible !");
        exit(1);
    }

    if (index0 > index1)
    {
        ll_swap_index(list, index1, index0);
    }

    Liste *ptr = *list;

    int value_index0 = ll_get_value_index(list, index0);
    int value_index1 = ll_get_value_index(list, index1);

    for (int i = 0; i < index1; i++)
    {
        if (i == index0)
        {
            ptr->number = value_index1;
        }
        ptr = ptr->next;
    }
    ptr->number = value_index0;
}

void ll_reverse(Liste **list)
{
    int length = ll_length(*list);
    int count_end = length - 1;
    for (int count_begin = 0; count_begin < length / 2; count_begin++)
    {
        ll_swap_index(list, count_begin, count_end);
        count_end--;
    }
}
