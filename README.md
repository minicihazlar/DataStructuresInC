# Data Structures In C

## Linked List (my_llist)

                  my_llist_t *list = my_llist_ctor();
                  int data = 0;

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
                  int data = 0;

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
  

## Implementation of some algorithms
### Greatest Common Divisor

                  gcd(23, 3435);

### Square Root

                  sqrt(344554);
