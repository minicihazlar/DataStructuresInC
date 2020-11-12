# Data Structures In C

## Linked List (my_llist)

                  my_llist_t *list = my_llist_ctor();
                  DATA_TYPE_t data = 0;

                  my_llist_push_head(list, 1);
                  my_llist_push_head(list, 2);
                  my_llist_push_head(list, 3);
                  my_llist_push_head(list, 4);
                  my_llist_push_head(list, 5);
                  
                  my_llist_reverse(list);

                  my_llist_push_end(list, 6);
                  my_llist_push_end(list, 7);
                  my_llist_push_end(list, 8);
                  my_llist_push_end(list, 9);
                  my_llist_push_end(list, 10);

                  my_llist_reverse(list);

                  printf("Size is %zu\n", my_llist_get_size(list));
 
                  my_llist_pop_at(list, &data, 3); printf("%d\n", data);
                  my_llist_pop_at(list, &data, 7); printf("%d\n", data);

                  my_llist_pop_end(list, &data); printf("%d\n", data);
                  my_llist_pop_end(list, &data); printf("%d\n", data);
                  my_llist_pop_end(list, &data); printf("%d\n", data);

                  my_llist_pop_head(list, &data); printf("%d\n", data);
                  my_llist_pop_head(list, &data); printf("%d\n", data);
                  my_llist_pop_head(list, &data); printf("%d\n", data);

                  my_llist_dtor(list);


## Double Linked List (my_dllist)

                  my_dllist_t *list = my_dllist_ctor();
                  DATA_TYPE_t data = 0;

                  my_dllist_push_head(list, 1);
                  my_dllist_push_head(list, 2);
                  my_dllist_push_head(list, 3);
                  my_dllist_push_head(list, 4);
                  my_dllist_push_head(list, 5);
                  
                  my_dllist_reverse(list);

                  my_dllist_push_end(list, 6);
                  my_dllist_push_end(list, 7);
                  my_dllist_push_end(list, 8);
                  my_dllist_push_end(list, 9);
                  my_dllist_push_end(list, 10);

                  my_dllist_iterator_start(list, &data);
                  printf("%d", data);
                  while(my_dllist_iterator_next(list, &data) == 0)
                  {
                    printf(", %d\n", data);
                  }
                  printf("\n");

                  my_dllist_reverse(list);

                  printf("Size is %zu\n", my_dllist_get_size(list));
 
                  my_dllist_pop_at(list, &data, 3); printf("%d\n", data);
                  my_dllist_pop_at(list, &data, 7); printf("%d\n", data);

                  my_dllist_pop_end(list, &data); printf("%d\n", data);
                  my_dllist_pop_end(list, &data); printf("%d\n", data);
                  my_dllist_pop_end(list, &data); printf("%d\n", data);

                  my_dllist_pop_head(list, &data); printf("%d\n", data);
                  my_dllist_pop_head(list, &data); printf("%d\n", data);
                  my_dllist_pop_head(list, &data); printf("%d\n", data);

                  my_dllist_dtor(list);


## Dynamic Array (my_darray)

                  my_darray_t *darray = my_darray_ctor(10);
                  DATA_TYPE_t data = 0;

                  my_darray_add_at(darray, 1, 0);
                  my_darray_add_at(darray, 2, 1);
                  my_darray_add_at(darray, 3, 2);
                  my_darray_add_at(darray, 4, 3);
                  my_darray_add_at(darray, 5, 4);
                  my_darray_add_at(darray, 6, 5);
                  my_darray_add_at(darray, 7, 6);
                  my_darray_add_at(darray, 8, 7);
                  my_darray_add_at(darray, 9, 8);
                  my_darray_add_at(darray, 10, 9);

                  my_darray_get_at(darray, &data, 0); printf("Data at index 0 is %d\n", data);
                  my_darray_get_at(darray, &data, 4); printf("Data at index 4 is %d\n", data);
                  my_darray_get_at(darray, &data, 7); printf("Data at index 7 is %d\n", data);
                  my_darray_get_at(darray, &data, 9); printf("Data at index 9 is %d\n", data);    
                  my_darray_get_at(darray, &data, 11); printf("Data at index 11 is %d\n", data); 

                  my_darray_dtor(darray);


## Stack (my_stack))

                  my_stack_t *stack = my_stack_ctor();
                  DATA_TYPE_t data = 0;

                  my_stack_push(stack, 1);
                  my_stack_push(stack, 2);
                  my_stack_push(stack, 3);
                  my_stack_push(stack, 4);
                  my_stack_push(stack, 5);
                  my_stack_pop(stack, &data); printf("Popped -> %d\n", data);
                  my_stack_peek(stack, &data); printf("Peeked -> %d\n", data);
                  while(!my_stack_is_empty(stack))
                  {
                      my_stack_pop(stack, &data); printf("Popped -> %d\n", data);
                  }
                  my_stack_dtor(stack);