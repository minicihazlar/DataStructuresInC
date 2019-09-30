#pragma once
#include <stdint.h>

typedef struct llist_s {
    struct llist_s  *next;
    int             data;
} llist_t;

uint32_t llist_get_size(llist_t **list);
uint32_t llist_push_head(llist_t **list, int data);
uint32_t llist_push_end(llist_t **list, int data);
uint32_t llist_pop_head(llist_t **list, int *data);
uint32_t llist_pop_end(llist_t **list, int *data);
uint32_t llist_pop_index(llist_t **list, int *data, uint32_t index);
void llist_reverse(llist_t **list);
void llist_print(llist_t **list);
