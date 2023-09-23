// list/list.c
//
// Implementation for linked list.
//
// Christian Nicolas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc()
{
    list_t *mylist = (list_t *)malloc(sizeof(list_t));
    mylist->head = NULL;

    return mylist;
}

void list_free(list_t *l)
{

    while (l->head != NULL)
    {
        node_t *node = l->head;
        l->head = node->next;

        free(node);
    }
    // free(l);
}

void list_print(list_t *l)
{
    node_t *curr = l->head;
    while (curr != NULL)
    {
        printf("%d->", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

char *listToString(list_t *l)
{
    char *buf = (char *)malloc(sizeof(char) * 1024);
    char tbuf[20];

    node_t *curr = l->head;
    while (curr != NULL)
    {
        sprintf(tbuf, "%d->", curr->value);
        curr = curr->next;
        strcat(buf, tbuf);
    }
    strcat(buf, "NULL");
    return buf;
}

int list_length(list_t *l)
{
    int length = 0;

    node_t *curr = l->head;
    while (curr != NULL)
    {
        length++;
        curr = curr->next;
    }

    return length;
}

void list_add_to_back(list_t *l, elem value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;

    if (l->head == NULL)
    {
        l->head = new_node;
    }
    else
    {
        node_t *node = l->head;

        while (node->next != NULL)
        {
            node = node->next;
        }

        node->next = new_node;
    }
}

void list_add_to_front(list_t *l, elem value)
{
    node_t *cur_node = (node_t *)malloc(sizeof(node_t));
    cur_node->value = value;
    cur_node->next = NULL;

    /* Insert to front */

    node_t *head = l->head; // get head of list

    cur_node->next = head;
    l->head = cur_node;
}

void list_add_at_index(list_t *l, elem value, int index)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;

    /* If index is outside of list
    all element to end of list */
    int length = list_length(l);
    if (index > length || index < 1)
    {
        list_add_to_back(l, value);
    }
    else if (index == 1)
    {
        list_add_to_front(l, value);
    }
    else
    {
        node_t *node = l->head;

        /* Retrieve the node before the index where
        the new node should be inserted */
        int count = 1;
        while (count < index - 1)
        {
            count++;
            node = node->next;
        }

        new_node->next = node->next;
        node->next = new_node;
    }
}

elem list_remove_from_back(list_t *l)
{
    node_t *head = l->head;

    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        elem removed_value = head->value;
        l->head = head->next;
        free(head);
        return removed_value;
    }

    node_t *prev = l->head;
    node_t *curr = prev->next;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    elem removed_value = curr->value;
    prev->next = curr->next;
    free(curr);
    return removed_value;
}

elem list_remove_from_front(list_t *l)
{
    if (l->head == NULL)
    {
        return -1;
    }

    node_t *head = l->head;
    l->head = head->next;

    elem removed_value = head->value;
    free(head);
    return removed_value;
}

elem list_remove_at_index(list_t *l, int index)
{
    if (l->head == NULL)
    {
        return -1;
    }

    if (index <= 1)
    {
        elem removed_value = list_remove_from_front(l);
        return removed_value;
    }
    else if (index >= list_length(l))
    {
        elem removed_value = list_remove_from_back(l);
        return removed_value;
    }

    node_t *node = l->head;

    int count = 1;
    while (count < index - 1)
    {
        node = node->next;
        if (node == NULL)
        {
            return -1;
        }
        count++;
    }

    node_t *node_to_remove = node->next;
    node->next = node_to_remove->next;

    elem removed_value = node_to_remove->value;
    free(node_to_remove);

    return removed_value;
}

bool list_is_in(list_t *l, elem value)
{
    if (l->head == NULL)
    {
        return false;
    }

    node_t *node = l->head;
    while (node != NULL)
    {
        if (node->value == value)
        {
            return true;
        }
        node = node->next;
    }

    return false;
}

elem list_get_elem_at(list_t *l, int index)
{
    if (index > list_length(l) || index < 1)
    {
        return -1;
    }

    node_t *node = l->head;

    int i = 1;
    while (i < index)
    {
        node = node->next;
        i++;
    }

    return node->value;
}

int list_get_index_of(list_t *l, elem value)
{
    if (l->head == NULL)
    {
        return -1;
    }
    
    node_t *node = l->head;

    int index = 1;
    while (node != NULL)
    {
        if (node->value == value)
        {
            return index;
        }

        node = node->next;
        index++;
    }

    return -1;
}
