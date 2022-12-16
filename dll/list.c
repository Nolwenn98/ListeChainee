#include <stdlib.h>
#include "list.h"

static element_t *list_create_element()
{
    element_t *new_element = (element_t *)malloc(sizeof(element_t));
    if (new_element != NULL)
    {
        new_element->data = NULL;
        new_element->next = NULL;
        new_element->previous = NULL;
    }
    else
        while (1)
        {
        }
    return new_element;
}

uint32_t list_length(list_t *list)
{
    uint32_t len = 0;
    element_t *elem = list->start;
    while (elem)
    {
        len++;
        elem = elem->next;
    }
    return len;
}

element_t *list_append(list_t *list, void *data)
{
    element_t *new_element = list_create_element();
    if (new_element != NULL)
    {
        new_element->data = data;
        new_element->previous = list->end;
        if (list->start == NULL)
            list->start = new_element;
        else
            list->end->next = new_element;
        list->end = new_element;
    }
    return new_element;
}

element_t *list_prepend(list_t *list, void *data)
{
    element_t *new_element = list_create_element();
    if (new_element != NULL)
    {
        new_element->data = data;
        new_element->next = list->start;
        if (list->end == NULL)
            list->end = new_element;
        else
            list->start->previous = new_element;
        list->start = new_element;
    }
    return new_element;
}

void *list_pop_first(list_t *list)
{
    void *ret;
    element_t *to_be_suppressed = list->start;
    if (to_be_suppressed)
    {
        list->start = to_be_suppressed->next;
        if (list->start)
            list->start->previous = NULL;
        if (to_be_suppressed->next == NULL)
            list->end = NULL;
        ret = to_be_suppressed->data;
        free(to_be_suppressed);
        return ret;
    }
    return NULL;
}

void *list_pop_last(list_t *list)
{
    void *ret;
    element_t *to_be_suppressed = list->end;
    if (to_be_suppressed)
    {
        list->end = to_be_suppressed->previous;
        if (list->end)
            list->end->next = NULL;
        if (to_be_suppressed->previous == NULL)
            list->start = NULL;
        ret = to_be_suppressed->data;
        free(to_be_suppressed);
        return ret;
    }
    return NULL;
}

element_t *list_insert_at(list_t *list, void *data, uint32_t index)
{
    element_t *new_element;

    if (!index || list->start == NULL)
        new_element = list_prepend(list, data);
    else if (index >= list_length(list))
        new_element = list_append(list, data);
    else
    {
        new_element = list_create_element();
        if (new_element != NULL)
        {
            element_t *previous_element = list->start;
            for (uint32_t i = 1; i < index; i++)
                previous_element = previous_element->next;

            new_element->data = data;
            new_element->previous = previous_element;
            new_element->next = previous_element->next;

            previous_element->next = new_element;
            new_element->next->previous = new_element;
        }
    }
    return new_element;
}

void *list_remove_at(list_t *list, uint32_t index)
{
    void *ret;
    element_t *to_be_suppressed = list->start;
    if (to_be_suppressed) // liste non vide
    {
        uint32_t i;
        for (i = 0; i < index && to_be_suppressed->next; i++)
            to_be_suppressed = to_be_suppressed->next;

        if (i == index)
        {
            if (to_be_suppressed->previous)
                to_be_suppressed->previous->next = to_be_suppressed->next;
            else
                list->start = to_be_suppressed->next;

            if (to_be_suppressed->next)
                to_be_suppressed->next->previous = to_be_suppressed->previous;
            else
                list->end = to_be_suppressed->previous;

            ret = to_be_suppressed->data;
            free(to_be_suppressed);
            return ret;
        }
    }
    return NULL;
}

void list_map(list_t *list, list_map_func_t function)
{
    element_t *elem = list->start;
    while (elem)
    {
        function(elem->data);
        elem = elem->next;
    }
}

int32_t list_index(list_t *list, void *data)
{
    element_t *elem = list->start;
    int32_t index = 0;
    while (elem)
    {
        if ((int)elem->data == (int)data)
            return index;
        elem = elem->next;
        index++;
    }
    return LIST_NOT_FOUND;
}