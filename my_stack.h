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

#ifndef __MY_STACK_H
#define __MY_STACK_H

#include <stdbool.h>

// Change the data type to be held in the stack here.
typedef int DATA_TYPE_t;

// Forward declaration of the stack data structure, implementation is hided
typedef struct my_stack_s my_stack_t; 

// Stack handling functions
my_stack_t * my_stack_ctor(void);
void my_stack_dtor(my_stack_t *);
int my_stack_push(my_stack_t *, DATA_TYPE_t);
int my_stack_pop(my_stack_t *, DATA_TYPE_t *);
int my_stack_peek(my_stack_t *, DATA_TYPE_t *);
bool my_stack_is_empty(my_stack_t *);

#endif
