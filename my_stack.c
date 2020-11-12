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
#include "my_stack.h"

struct my_local_stack_s {
    struct my_local_stack_s  *next;
    DATA_TYPE_t               data;
};

// Stack structure
struct my_stack_s {
    struct my_local_stack_s *stack;
};

/*-------------------------------------------------------------------*/

my_stack_t * my_stack_ctor(void)
{
    my_stack_t *stack = calloc(1, sizeof(my_stack_t));
    stack->stack = NULL;
    return stack;
}

/*-------------------------------------------------------------------*/

void my_stack_dtor(my_stack_t *stack)
{
    if(stack != NULL)
    {
        struct my_local_stack_s *stack_local = NULL;
        while(stack->stack != NULL)
        {
            stack_local = stack->stack->next;
            free(stack->stack);
            stack->stack = stack_local;
        }
    }
    free(stack);
}

/*-------------------------------------------------------------------*/

int my_stack_push(my_stack_t *stack, DATA_TYPE_t data)
{
    if(stack == NULL)
    {
        return -1;
    }    
    struct my_local_stack_s *stack_local = calloc(1, sizeof(struct my_local_stack_s));
    stack_local->data = data;
    stack_local->next = stack->stack;
    stack->stack = stack_local;
    return 0;
}

/*-------------------------------------------------------------------*/

int my_stack_pop(my_stack_t *stack, DATA_TYPE_t *data)
{
    if((stack == NULL) || (stack->stack == NULL))
    {
        return -1;
    }
    *data = stack->stack->data;
    struct my_local_stack_s *stack_local = stack->stack->next;
    free(stack->stack);
    stack->stack = stack_local;
    return 0;
}

/*-------------------------------------------------------------------*/

int my_stack_peek(my_stack_t *stack, DATA_TYPE_t *data)
{
    if((stack == NULL) || (stack->stack == NULL))
    {
        return -1;
    }
    *data = stack->stack->data;
    return 0;
}

/*-------------------------------------------------------------------*/

bool my_stack_is_empty(my_stack_t *stack)
{
     if(stack == NULL)
     {
         return true;
     } 
    return stack->stack == NULL ? true : false; 
}
