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
#include "my_queue.h"

struct my_local_queue_s {
    struct my_local_queue_s  *next;
    struct my_local_queue_s  *prev;
    DATA_TYPE_t               data;
};

// Queue structure
struct my_queue_s {
    struct my_local_queue_s *queue_head;
    struct my_local_queue_s *queue_tail;    
};

/*-------------------------------------------------------------------*/

my_queue_t * my_queue_ctor(void)
{
    my_queue_t *queue = calloc(1, sizeof(my_queue_t));
    queue->queue_head = NULL;
    queue->queue_tail = NULL;
    return queue;
}

/*-------------------------------------------------------------------*/

void my_queue_dtor(my_queue_t *queue)
{
    if(queue != NULL)
    {
        struct my_local_queue_s *queue_local = NULL;
        while(queue->queue_head != NULL)
        {
            queue_local = queue->queue_head->next;
            free(queue->queue_head);
            queue->queue_head = queue_local;
        }
    }
    free(queue);
    queue = NULL;
}

/*-------------------------------------------------------------------*/

int my_queue_enqueue(my_queue_t *queue, DATA_TYPE_t data)
{
    if(queue == NULL)
    {
        return -1;
    }    
    struct my_local_queue_s *queue_local = calloc(1, sizeof(struct my_local_queue_s));
    queue_local->data = data;
    queue_local->next = queue->queue_head;
    queue->queue_head = queue_local;
    if(queue->queue_head->next != NULL)
    {
        queue->queue_head->next->prev = queue->queue_head;
    }
    if(queue->queue_tail == NULL)
    {
        queue->queue_tail = queue->queue_head;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_queue_dequeue(my_queue_t *queue, DATA_TYPE_t *data)
{
    if((queue == NULL) || (queue->queue_tail == NULL))
    {
        return -1;
    }
    *data = queue->queue_tail->data;
    if(queue->queue_tail->prev == NULL)
    {
        free(queue->queue_tail);
        queue->queue_tail = NULL;
        queue->queue_head = NULL;
    }
    else
    {
        struct my_local_queue_s *queue_local = queue->queue_tail->prev;
        queue_local->next = NULL;
        free(queue->queue_tail);
        queue->queue_tail = queue_local;
    }
    return 0;
}

/*-------------------------------------------------------------------*/

int my_queue_peek(my_queue_t *queue, DATA_TYPE_t *data)
{
    if((queue == NULL) || (queue->queue_tail == NULL))
    {
        return -1;
    }
    *data = queue->queue_tail->data;
    return 0;
}

/*-------------------------------------------------------------------*/

bool my_queue_is_empty(my_queue_t *queue)
{
    if(queue == NULL)
    {
        return true;
    } 
    return queue->queue_head == NULL ? true : false; 
}
