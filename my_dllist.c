/*

Copyright (c) 2020, Murat YILDIZ
Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted, provided
that the above copyright notice and this permission notice appear
in all copies.
THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

*/

#include <stdlib.h>
#include "my_dllist.h"

struct my_local_dllist_s 
{
    struct my_local_dllist_s  *next;
    struct my_local_dllist_s  *prev;
    DATA_TYPE_t               data;
};

struct my_dllist_s 
{   
    struct my_local_dllist_s  *head;
    struct my_local_dllist_s  *tail;
    struct my_local_dllist_s  *iterator;
    size_t                    size;

};

/*-------------------------------------------------------------------*/

my_dllist_t * my_dllist_ctor(void)
{
    my_dllist_t *llist = calloc(1, sizeof(my_dllist_t));
    return llist;
}

/*-------------------------------------------------------------------*/

void my_dllist_dtor(my_dllist_t *list)
{
    if(list != NULL)
    {
        struct my_local_dllist_s *head = list->head;

        while(head != NULL)
        {
            struct my_local_dllist_s *head_local = head->next;
            free(head);
            head = head_local;
        }
        free(list);
    }
}

/*-------------------------------------------------------------------*/

size_t my_dllist_get_size(my_dllist_t *list)
{
    if(list == NULL)
    {
        return 0;
    }
    return list->size;
}

/*-------------------------------------------------------------------*/

int my_dllist_push_head(my_dllist_t *list, DATA_TYPE_t data)
{
    if(list == NULL)
    {
        return -1;
    }
    else
    {
        struct my_local_dllist_s *head = list->head;
        list->head = calloc(1, sizeof(struct my_local_dllist_s));
        if(list->head == NULL)
        {
            list->head = head;
            return -1;
        }
        list->head->data = data;
        list->head->next = head;
        list->head->prev = NULL;
        list->size += 1;
        if(head == NULL)
        {
            list->tail = list->head;
        }
        else
        {
            head->prev = list->head;
        }
        
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_dllist_push_end(my_dllist_t *list, DATA_TYPE_t data)
{
    if((list == NULL) || (list->tail == NULL))
    {
        return -1;
    }
    else
    {
        struct my_local_dllist_s *tail = calloc(1, sizeof(struct my_local_dllist_s));
        tail->data = data;
        tail->next = NULL;
        tail->prev = list->tail;
        list->tail->next = tail;
        list->tail = tail;
        list->size += 1;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_dllist_pop_head(my_dllist_t *list, DATA_TYPE_t *data)
{
    if((list == NULL) || (data == NULL) || (list->head == NULL))
    {
        return -1;
    }
    struct my_local_dllist_s *head = list->head;
    *data = head->data;
    list->head = head->next;
    list->head->prev = NULL;
    free(head);
    list->size -= 1;
    return 0;
}

/*-------------------------------------------------------------------*/

int my_dllist_pop_end(my_dllist_t *list, DATA_TYPE_t *data)
{
    if((list == NULL) || (data == NULL) || (list->head == NULL) || (list->tail == NULL))
    {
        return -1;
    }
    if(list->head->next == NULL)
    {
        *data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;        
    }
    else
    {
        struct my_local_dllist_s *tail = list->tail;
        *data = tail->data;
        list->tail = tail->prev;
        list->tail->next = NULL;
        list->size -= 1; 
        free(tail);
    }
    return 0;
}

/*-------------------------------------------------------------------*/

// ATTENTION: index starts from 1 and not from 0.
int my_dllist_pop_at(my_dllist_t *list, DATA_TYPE_t *data, size_t index)
{
    if((list == NULL) || (data == NULL) || (list->head == NULL) || (list->tail == NULL) || (index == 0))
    {
        return -1;
    }
    if(index > list->size)
    {
        return -1;
    }
    else if(index == list->size)
    {
        return my_dllist_pop_end(list, data);
    }
    else if(index == 1)
    {
        return my_dllist_pop_head(list, data);
    }
    else
    {
        struct my_local_dllist_s *list_local = NULL;

        if(index > (list->size >> 1))
        {
            list_local = list->tail;
            size_t i = list->size;
            while(i > index)
            {
                list_local = list_local->prev;
                i--;
            }
        }
        else
        {
            list_local = list->head;
            size_t i = 1;
            while(i < index)
            {
                list_local = list_local->next;
                i++;
            }            
        }        
        *data = list_local->data;
        list_local->prev->next = list_local->next;
        list_local->next->prev = list_local->prev;  
        list->size -= 1;
        free(list_local);
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_dllist_iterator_start(my_dllist_t *list, DATA_TYPE_t *data)
{
    if((list == NULL) || (data == NULL) || (list->head == NULL))
    {
        return -1;
    }
    *data = list->head->data;
    list->iterator = list->head->next;
    return 0;
}

/*-------------------------------------------------------------------*/

int my_dllist_iterator_next(my_dllist_t *list, DATA_TYPE_t *data)
{
    if((list == NULL) || (data == NULL) || (list->iterator == NULL))
    {
        return -1;
    }
    *data = list->iterator->data;
    list->iterator = list->iterator->next;
    return 0;
}

/*-------------------------------------------------------------------*/

void my_dllist_reverse(my_dllist_t *list)
{    
    if((list != NULL) && (list->head != NULL) && (list->tail != NULL) && (list->size > 1))
    {
        struct my_local_dllist_s *head = NULL;
        struct my_local_dllist_s *tail = NULL;
        struct my_local_dllist_s *orig = list->head;

        while (orig != NULL)
        {
            struct my_local_dllist_s *orig_next = orig->next;

            orig->next = head;
            head = orig;
            orig = orig_next;
        }
        list->head = head;
        orig = list->tail;
        head = NULL;
        while (orig != NULL)
        {
            struct my_local_dllist_s *orig_prev = orig->prev;

            orig->prev = head;
            head = orig;
            orig = orig_prev;
        }
        list->tail = head;
    }
}
