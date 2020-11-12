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
#include "my_darray.h"

struct my_darray_s
{
    DATA_TYPE_t  *darray;
    size_t        size;
};

/*-------------------------------------------------------------------*/

my_darray_t * my_darray_ctor(size_t size)
{
    my_darray_t *darray = calloc(1, sizeof(my_darray_t));
    if(darray != NULL)
    {
        darray->darray = calloc(size, sizeof(DATA_TYPE_t));
        darray->size = size;
    }
    return darray;
}

/*-------------------------------------------------------------------*/

void my_darray_dtor(my_darray_t *darray)
{
    if(darray != NULL)
    {
        if(darray->darray != NULL)
        {
            free(darray->darray);
        }
        free(darray);
    }
}

/*-------------------------------------------------------------------*/

int my_darray_resize(my_darray_t *darray, size_t size)
{
    if((darray == NULL) || (darray->darray == NULL)) 
    {
        return -1;
    }
    DATA_TYPE_t *darray_local = realloc(darray->darray, sizeof(DATA_TYPE_t) * size);
    if(darray_local == NULL)
    {
        return -1;
    }
    darray->darray = darray_local;
    darray->size = size;
    return 0;
}

/*-------------------------------------------------------------------*/

size_t my_darray_get_size(my_darray_t *darray)
{
    if(darray == NULL) 
    {
        return -1;
    }
    return darray->size;
}

/*-------------------------------------------------------------------*/

int my_darray_add_at(my_darray_t *darray, DATA_TYPE_t data, size_t index)
{
    if((darray == NULL) || (darray->darray == NULL) || (darray->size <= index))
    {
        return -1;
    }
    darray->darray[index] = data;
    return 0;
}

/*-------------------------------------------------------------------*/

int my_darray_get_at(my_darray_t *darray, DATA_TYPE_t *data, size_t index)
{
    if((darray == NULL) || (darray->darray == NULL) || (darray->size <= index)) 
    {
        return -1;
    }    
    *data = darray->darray[index];
    return 0;
}
