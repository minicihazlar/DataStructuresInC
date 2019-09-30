#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct llist_s {
    struct llist_s  *next;
    int             data;
} llist_t;

uint32_t llist_get_size(llist_t **list)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        return 0;
    }
    uint32_t size = 1;
    llist_t *list_local = *list;
    while(list_local->next != NULL)
    {
        ++size;
        list_local = list_local->next;
    }
    return size;
}

uint32_t llist_push_head(llist_t **list, int data)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        // Initialise first
        *list = (llist_t *) malloc(sizeof(llist_t));
        if(*list == NULL)
        {
            return 1;
        }
        (*list)->next = NULL;
        (*list)->data = data;
    }
    else
    {
        // Already initialised
        llist_t *list_local = *list;
        *list = (llist_t *) malloc(sizeof(llist_t));
        if(*list == NULL)
        {
            *list = list_local;
            return 1;
        }
        (*list)->data = data;
        (*list)->next = list_local;
    }
    return 0;
}

uint32_t llist_push_end(llist_t **list, int data)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        // Initialise first
        *list = (llist_t *) malloc(sizeof(llist_t));
        if(*list == NULL)
        {
            return 1;
        }
        (*list)->next = NULL;
        (*list)->data = data;
    }
    else
    {
        // Already initialised
        llist_t *list_local = *list;
        while(list_local->next != NULL)
        {
            list_local = list_local->next;
        }
        list_local->next = (llist_t *) malloc(sizeof(llist_t));
        if(list_local->next == NULL)
        {
            return 1;
        }
        list_local->next->data = data;
        list_local->next->next = NULL;
    }
    return 0;
}

uint32_t llist_pop_head(llist_t **list, int *data)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        return 1;
    }
    llist_t *list_local = *list;
    *data = (*list)->data;
    *list = (*list)->next;
    free(list_local);
    return 0;
}

uint32_t llist_pop_end(llist_t **list, int *data)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        return 1;
    }
    if((*list)->next == NULL)
    {
        *data = (*list)->data;
        free(*list);
        *list = NULL;
    }
    else
    {
        llist_t *list_local = *list;
        llist_t *list_prev = *list;

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

uint32_t llist_pop_index(llist_t **list, int *data, uint32_t index)
{
     uint32_t i = llist_get_size(list);

    // Check if llist is initialised
    if(*list == NULL)
    {
        return 1;
    }
    if(index > i)
    {
        return 1;
    }
    else if(index == i)
    {
        return llist_pop_end(list, data);
    }
    else if(index == 1)
    {
        return llist_pop_head(list, data);
    }
    else
    {
        llist_t *list_local = *list;
        llist_t *list_prev = *list;
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

void llist_reverse(llist_t **list)
{    
    if(*list != NULL)
    {
        llist_t *head = NULL;
        llist_t *orig = *list;

        while (orig != NULL)
        {
            llist_t *orig_next = orig->next;

            orig->next = head;
            head = orig;
            orig = orig_next;
        }
        *list = head;
    }
}

void llist_print(llist_t **list)
{
    // Check if llist is initialised
    if(*list == NULL)
    {
        puts("List is empty!!!");
    }
    else
    {
        llist_t *list_local = *list;
        uint32_t i = 0;
        printf("-----------------------------\n");
        printf("\tLinked List Content:\n");
        while (1) 
        {
            printf("\t  Item %5d data is -> %5d\n", ++i, list_local->data);
            if (list_local->next == NULL)
            {
                break;
            }
            list_local = list_local->next;
        }
        printf("-----------------------------\n");
    }
}
