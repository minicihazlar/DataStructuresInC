#include "stdafx.h"
#include <stdio.h>
#include "llist.h"
#include "general.h"

llist_t *list = NULL;

void test_llist(void)
{
    uint16_t i = 0;
    int d = 0;

    printf("Pushing %u numbers into Linked List\n", 0xFFFF);
    for (i = 1; i != 0; ++i)
    {
        ++d;
        if (llist_push_head(&list, d) != 0)
        {
            printf("Error while pushing %d\n", d);
            break;
        }
    }

    //llist_print(&list);

    printf("Linked List size is %d\n", llist_get_size(&list));

    printf("Reversing Linked List\n");
    llist_reverse(&list);
    //llist_print(&list);

    for (i = 0; i < 5; i++)
    {
        if (llist_pop_head(&list, &d) != 0)
        {
            printf("Error while popping head from linked list!!!\n");
            break;
        }
        else
        {
            printf("Popped head data from linked list is %d\n", d);
        }
    }

    //llist_print(&list);

    if (llist_pop_index(&list, &d, 3) != 0)
    {
        printf("Index 3 is out of bounds\n");
    }
    else
    {
        printf("Popped data at index 3 from linked list is %d\n", d);
    }

    //llist_print(&list);

    if (llist_pop_index(&list, &d, 1) != 0)
    {
        printf("Index 1 is out of bounds\n");
    }
    else
    {
        printf("Popped data at index 1 from linked list is %d\n", d);
    }

    //llist_print(&list);

    if (llist_pop_index(&list, &d, 14) != 0)
    {
        printf("Index 14 is out of bounds\n");
    }
    else
    {
        printf("Popped data at index 14 from linked list is %d\n", d);
    }

    if (llist_pop_index(&list, &d, 13) != 0)
    {
        printf("Index 13 is out of bounds\n");
    }
    else
    {
        printf("Popped data at index 13 from linked list is %d\n", d);
    }

    //llist_print(&list);

    for (i = 0; i < 20; i++)
    {
        if (llist_pop_end(&list, &d) != 0)
        {
            printf("Error while popping end from linked list!!!\n");
            break;
        }
        else
        {
            printf("Popped end data from linked list is %d\n", d);
        }
    }
    //llist_print(&list);
}

#if 1

#define FSM         
#define STATE(x)        s_##x :
#define NEXTSTATE(x)    goto s_##x 

void fsm(void)
{
    int s = 0;

    int i = 0;

    printf("Pushing 10 data into Linked List\n");
    for (i = 0; i < 10; ++i)
    {
        if (llist_push_head(&list, i + 1) != 0)
        {
            break;
        }
    }

    NEXTSTATE(0);

    FSM
    {
        STATE(0)
        {
            llist_print(&list);
            NEXTSTATE(1);
        }
        STATE(1)
        {
            printf("Reversing Linked List\n");
            llist_reverse(&list);
            llist_print(&list);
            NEXTSTATE(2);
        }
        STATE(2)
        {
            printf("TEST END\n");
        }
    }
}

#endif

int main()
{
    test_llist();
    //fsm();
    return 0;
}

