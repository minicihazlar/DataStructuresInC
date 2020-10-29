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

#ifndef __MY_LLIST_H
#define __MY_LLIST_H

#ifdef __cplusplus
extern "C" {
#endif

// Change the data type to be held in the linked list here.
typedef int DATA_TYPE_t;

// Forward declaration of the linked list data structure, implementation is hided
typedef struct my_llist_s my_llist_t; 

// Linked list handling functions
my_llist_t * my_llist_ctor(DATA_TYPE_t);
void my_llist_dtor(my_llist_t *);
int my_llist_get_size(my_llist_t *);
int my_llist_push_head(my_llist_t **, DATA_TYPE_t);
int my_llist_push_end(my_llist_t **, DATA_TYPE_t);
int my_llist_pop_head(my_llist_t **, DATA_TYPE_t *);
int my_llist_pop_end(my_llist_t **, DATA_TYPE_t *);
int my_llist_pop_at(my_llist_t **, DATA_TYPE_t *, int);
void my_llist_reverse(my_llist_t **);

#ifdef __cplusplus
}
#endif

#endif
