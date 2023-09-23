#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

/* Returns random number in the range [min, max]. */
int randint(int min, int max)
{
    return (rand() %
            (max - min + 1)) +
           min;
}

/* Returns 1 if all empty list test cases pass.
   Returns 0 if any empty list test case fails. */
int empty_list_test()
{
    printf("\n[empty_list_test]\n");

    list_t *emptyList;
    emptyList = list_alloc();

    /* List length test. */
    if (list_length(emptyList) != 0)
    {
        printf("list_length : FAILED\n");
        return 0;
    }
    else
    {
        printf("list_length : PASSED\n");
    }

    /* Free memory of list nodes. */
    list_free(emptyList);
    if (strcmp("NULL", listToString(emptyList)) != 0)
    {
        printf("list_free : FAILED\n");
        return 0;
    }

    /* Add to front of empty list. */
    for (int i = 0; i < 1000; i++)
    {
        int num = randint(-100, 100);
        list_add_to_front(emptyList, num);

        char tbuf[20];
        sprintf(tbuf, "%d->NULL", num);

        if (strcmp(tbuf, listToString(emptyList)) != 0)
        {
            printf("list_add_to_front : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_add_to_front : PASSED\n");

    /* Add to of back empty list. */
    for (int i = 0; i < 1000; i++)
    {
        int num = randint(-100, 100);
        list_add_to_back(emptyList, num);

        char tbuf[20];
        sprintf(tbuf, "%d->NULL", num);

        if (strcmp(tbuf, listToString(emptyList)) != 0)
        {
            printf("list_add_to_back : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_add_to_back : PASSED\n");

    /* Add to empty list at specified index. */
    for (int i = 0; i < 1000; i++)
    {
        int num = randint(-100, 100);
        int index = randint(-100, 100);
        list_add_at_index(emptyList, num, index);

        char tbuf[20];
        sprintf(tbuf, "%d->NULL", num);

        if (strcmp(tbuf, listToString(emptyList)) != 0)
        {
            printf("list_add_at_index : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_add_at_index : PASSED\n");

    /* Remove last element from empty list. */
    for (int i = 0; i < 1000; i++)
    {
        list_remove_from_back(emptyList);

        if (strcmp("NULL", listToString(emptyList)) != 0)
        {
            printf("list_remove_from_back : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_remove_from_back : PASSED\n");

    /* Remove first element from empty list. */
    for (int i = 0; i < 1000; i++)
    {
        list_remove_from_front(emptyList);

        if (strcmp("NULL", listToString(emptyList)) != 0)
        {
            printf("list_remove_from_front : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_remove_from_front : PASSED\n");

    /* Remove element at a specified index from empty list. */
    for (int i = 0; i < 1000; i++)
    {
        int index = randint(-100, 100);
        list_remove_at_index(emptyList, index);

        if (strcmp("NULL", listToString(emptyList)) != 0)
        {
            printf("list_remove_at_index : FAILED\n");
            return 0;
        }

        list_free(emptyList);
    }
    printf("list_remove_at_index : PASSED\n");

    /* Check is a value exists in an empty list. */
    for (int i = 0; i < 1000; i++)
    {
        int num = randint(-100, 100);
        if (list_is_in(emptyList, num))
        {
            printf("list_is_in : FAILED\n");
            return 0;
        };

        list_free(emptyList);
    }
    printf("list_is_in : PASSED\n");

    /* Retrieve element at given index from an empty list.  */
    for (int i = 0; i < 1000; i++)
    {
        int index = randint(-100, 100);
        if (list_get_elem_at(emptyList, index) != -1)
        {
            printf("list_get_elem_at : FAILED\n");
            return 0;
        };

        list_free(emptyList);
    }
    printf("list_get_elem_at : PASSED\n");

    /* Retrieve index of first occurance of a given value from an empty list.  */
    for (int i = 0; i < 1000; i++)
    {
        int num = randint(-100, 100);
        if (list_get_index_of(emptyList, num) != -1)
        {
            printf("list_get_index_of : FAILED\n");
            return 0;
        };

        list_free(emptyList);
    }
    printf("list_get_index_of : PASSED\n");

    return 1;
}

int main()
{
    // Change random number seed
    srand(time(NULL));

    /* Empty List Test Case */
    if (empty_list_test() == 1)
    {
        printf("->All empty_list_test cases have passed!\n");
    }
    else
    {
        printf("->An empty_list_test case has failed!\n");
    }

    list_t *mylist;
    mylist = list_alloc();

    list_print(mylist);
    list_remove_at_index(mylist, 3);
    list_print(mylist);

    if (strcmp("100->90->70->60->50->40->30->20->10->NULL", listToString(mylist)) != 0)
    {
        printf("list_remove_at_index : FAILED\n\n");
    }
    else
    {
        printf("list_remove_at_index : PASSED\n\n");
    }

    list_remove_at_index(mylist, 20);
    list_print(mylist);
    list_remove_at_index(mylist, 1);
    list_print(mylist);
    list_remove_at_index(mylist, 6);
    list_print(mylist);

    if (strcmp("90->70->60->50->40->20->NULL", listToString(mylist)) != 0)
    {
        printf("list_remove_at_index : FAILED\n\n");
    }
    else
    {
        printf("list_remove_at_index : PASSED\n\n");
    }

    printf("The list length is %d\n\n", list_length(mylist));

    list_add_to_back(mylist, 39);
    list_print(mylist);
    list_add_to_back(mylist, 18);
    list_add_to_back(mylist, 42);
    list_add_to_back(mylist, 190);
    list_print(mylist);

    if (strcmp("90->70->60->50->40->20->39->18->42->190->NULL", listToString(mylist)) != 0)
    {
        printf("list_add_to_back : FAILED\n\n");
    }
    else
    {
        printf("list_add_to_back : PASSED\n\n");
    }

    list_free(mylist);
    list_print(mylist);

    if (strcmp("NULL", listToString(mylist)) != 0)
    {
        printf("list_free : FAILED\n\n");
    }
    else
    {
        printf("list_free : PASSED\n\n");
    }

    list_add_to_front(mylist, 81);
    list_add_to_back(mylist, 4);
    list_add_to_front(mylist, 308);
    list_add_to_back(mylist, 70);
    list_add_to_front(mylist, 290);
    list_print(mylist);
    printf("The list length is %d\n\n", list_length(mylist));

    list_add_at_index(mylist, 21, 1);
    list_add_at_index(mylist, 65, 0);
    list_add_at_index(mylist, 10, 8);
    list_print(mylist);
    list_add_at_index(mylist, 10, 7);
    list_print(mylist);
    printf("\n");

    list_remove_from_back(mylist);
    list_print(mylist);
    list_remove_from_front(mylist);
    list_print(mylist);
    list_remove_at_index(mylist, 3);
    list_print(mylist);
    printf("\n");

    printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
    printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
    printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
    printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
    printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
    printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
    printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
    printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
    printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
    printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
    printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
    printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
    printf("\n");

    list_free(mylist);
    list_add_at_index(mylist, -1, -1);
    list_print(mylist);
    list_add_at_index(mylist, -1, -1);
    list_print(mylist);
    list_add_at_index(mylist, 10, 0);
    list_print(mylist);
    list_add_at_index(mylist, 20, 1);
    list_print(mylist);
    list_free(mylist);
    printf("The list length is %d\n", list_length(mylist));
    list_print(mylist);
    printf("\n");

    list_remove_from_back(mylist);
    list_remove_from_front(mylist);
    list_remove_at_index(mylist, -3);
    list_remove_at_index(mylist, 0);
    list_remove_at_index(mylist, 2);
    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 60);
    list_add_at_index(mylist, 50, 1);
    list_add_at_index(mylist, 0, 6);
    list_add_at_index(mylist, 70, 0);
    list_add_at_index(mylist, 80, 12);
    list_print(mylist);
    printf("\n");

    list_free(mylist);
    list_free(mylist);
    list_add_to_back(mylist, 100);
    list_print(mylist);
    list_remove_from_front(mylist);
    list_print(mylist);
    list_add_to_back(mylist, 13);
    list_print(mylist);
    list_remove_from_back(mylist);
    list_print(mylist);
    printf("\n");

    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 60);
    list_print(mylist);
    list_remove_at_index(mylist, 0);
    list_print(mylist);
    list_remove_at_index(mylist, -2);
    list_print(mylist);
    list_remove_at_index(mylist, 7);
    list_print(mylist);
    list_remove_at_index(mylist, 4);
    list_print(mylist);
    printf("\n");

    list_free(mylist);
    list_print(mylist);
    list_remove_at_index(mylist, 0);
    list_print(mylist);
    list_add_to_front(mylist, 60);
    list_print(mylist);
    list_remove_at_index(mylist, 1);
    list_print(mylist);
    list_add_to_front(mylist, 80);
    list_print(mylist);
    list_remove_at_index(mylist, 0);
    list_print(mylist);
    printf("\n");

    printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
    list_add_to_back(mylist, 50);
    list_add_to_back(mylist, 60);
    list_add_to_back(mylist, 70);
    list_add_to_back(mylist, 80);
    list_add_to_back(mylist, 90);
    list_print(mylist);
    printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
    printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
    printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
    list_add_to_back(mylist, 70);
    list_print(mylist);
    printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
    printf("\n");

    printf("The list length is %d\n", list_length(mylist));
    printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
    printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
    printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
    printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
    list_free(mylist);
    list_print(mylist);
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
    list_remove_at_index(mylist, 0);
    printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
    printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
    list_add_to_front(mylist, 10);
    list_add_to_front(mylist, 20);
    list_add_to_front(mylist, 30);
    list_add_to_front(mylist, 40);
    list_add_to_front(mylist, 50);
    list_print(mylist);
    printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
    printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
    printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
    printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
    list_add_to_front(mylist, 60);
    list_print(mylist);
    printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
    printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
    list_add_to_front(mylist, 10);
    list_print(mylist);
    printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
    list_add_to_back(mylist, 40);
    list_print(mylist);
    printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));
    printf("\n");

    return 0;
}