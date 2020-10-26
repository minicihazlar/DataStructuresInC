#include <stdlib.h>
#include "my_llist.h"

// Linked list structure
static struct my_llist_s {
    struct my_llist_s  *next;
    DATA                data;
};

/*-------------------------------------------------------------------*/

my_llist_t * my_llist_ctor(DATA data)
{
    my_llist_t *list = calloc(1, sizeof(my_llist_t));
    list->data = data;
    return list;
}

/*-------------------------------------------------------------------*/

void my_llist_dtor(my_llist_t *list)
{
    my_llist_t *list_local;

    while(list != NULL)
    {
        list_local = list->next;
        free(list);
        list = list_local;
    }
}

/*-------------------------------------------------------------------*/

int my_llist_get_size(my_llist_t *list)
{
    // Check if the list is initialised
    if(list == NULL)
    {
        return 0;
    }
    int size = 1;
    my_llist_t *list_local = list;
    while(list_local->next != NULL)
    {
        ++size;
        list_local = list_local->next;
    }
    return size;
}

/*-------------------------------------------------------------------*/

int my_llist_push_head(my_llist_t **list, DATA data)
{
    // Check if the list is initialised
    if(*list == NULL)
    {
        return -1;
    }
    else
    {
        my_llist_t *list_local = *list;
        *list = calloc(1, sizeof(struct my_llist_s));
        if(*list == NULL)
        {
            *list = list_local;
            return -1;
        }
        (*list)->data = data;
        (*list)->next = list_local;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_llist_push_end(my_llist_t **list, DATA data)
{
    // Check if the list is initialised
    if(*list == NULL)
    {
        return -1;
    }
    else
    {
        my_llist_t *list_local = *list;
        while(list_local->next != NULL)
        {
            list_local = list_local->next;
        }
        list_local->next = calloc(1, sizeof(struct my_llist_s));
        if(list_local->next == NULL)
        {
            return -1;
        }
        list_local->next->data = data;
        list_local->next->next = NULL;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_llist_pop_head(my_llist_t **list, DATA *data)
{
    // Check if the list is initialised
    if(*list == NULL)
    {
        return -1;
    }
    my_llist_t *list_local = *list;
    *data = (*list)->data;
    *list = (*list)->next;
    free(list_local);
    return 0;
}

/*-------------------------------------------------------------------*/

int my_llist_pop_end(my_llist_t **list, DATA *data)
{
    // Check if the list is initialised
    if(*list == NULL)
    {
        return -1;
    }
    if((*list)->next == NULL)
    {
        *data = (*list)->data;
        free(*list);
        *list = NULL;
    }
    else
    {
        my_llist_t *list_local = *list;
        my_llist_t *list_prev = *list;

        while(list_local->next != NULL)
        {
            list_prev = list_local;
            list_local = list_local->next;
        }
        *data = list_local->data;
        free(list_local);
        list_prev->next = NULL;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_llist_pop_at(my_llist_t **list, DATA *data, int index)
{
     int i = my_llist_get_size(list);

    // Check if the list is initialised
    if(*list == NULL)
    {
        return -1;
    }
    if(index > i)
    {
        return -1;
    }
    else if(index == i)
    {
        return my_llist_pop_end(list, data);
    }
    else if(index == 1)
    {
        return my_llist_pop_head(list, data);
    }
    else
    {
        my_llist_t *list_local = *list;
        my_llist_t *list_prev = *list;
        for(i = 1; i < index; ++i)
        {
            list_prev = list_local;
            list_local = list_local->next;
        }
        *data = list_local->data;
        list_prev->next = list_local->next;
        free(list_local);
    }
    return 0;
}

/*-------------------------------------------------------------------*/

void my_llist_reverse(my_llist_t **list)
{    
    if(*list != NULL)
    {
        my_llist_t *head = NULL;
        my_llist_t *orig = *list;

        while (orig != NULL)
        {
            my_llist_t *orig_next = orig->next;

            orig->next = head;
            head = orig;
            orig = orig_next;
        }
        *list = head;
    }
}
