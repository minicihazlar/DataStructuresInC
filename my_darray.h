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

#ifndef __MY_DARRAY_H
#define __MY_DARRAY_H

#include <stddef.h>

// Change the data type to be held in the dynamic array here.
typedef int DATA_TYPE_t;

// Forward declaration of the dynamic array data structure, implementation is hided
typedef struct my_darray_s my_darray_t;

my_darray_t * my_darray_ctor(size_t);
void my_darray_dtor(my_darray_t *);
int my_darray_resize(my_darray_t *, size_t);
size_t my_darray_get_size(my_darray_t *);
int my_darray_add_at(my_darray_t *, DATA_TYPE_t, size_t);
int my_darray_get_at(my_darray_t *, DATA_TYPE_t *, size_t);

#endif
