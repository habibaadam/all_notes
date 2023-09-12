#include "doubly.h"
/**
 * createNode - creates an empty node
 * @data: member of linked list
 * Return: a new node
*/
doubly_habie *createNode(int data)
{
    doubly_habie *newhabie = malloc(sizeof(doubly_habie));
    if (newhabie == NULL)
    {
        return (NULL);
    }
    newhabie->data = data;
    newhabie->prev = NULL;
    newhabie->next = NULL;

    return (newhabie); 
}

doubly_habie *insertatstart(doubly_habie **head, int data)
{
    doubly_habie *firstnode = createNode(data);
    firstnode->data = data;
    firstnode->prev = NULL;
    firstnode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = firstnode;
    }
    *head = firstnode;
    return (firstnode);
}

 size_t printdoublylist( const doubly_habie *head)
{
    const doubly_habie *present = head;
    size_t countnode = 0;

    while (present != NULL)
    {
        printf("%d\n", present->data);
        present = present->next;
        countnode++;
    }
    printf("Number of nodes is: %zu\n", countnode);

    return (countnode);

}

size_t numofelements(const doubly_habie *head)
{
    const doubly_habie *present = head;
    size_t countelements = 0;

    while (present != NULL)
    {
        countelements++;
        present = present->next;
    }
    return (countelements);
}

doubly_habie *insert_atend(doubly_habie **head, int data)
{
    doubly_habie *present;
    doubly_habie *lastnode = createNode(data);
    if (lastnode == NULL)
    {
        return (NULL);
    }
    lastnode->data = data;
    lastnode->next = NULL;
    lastnode->prev = NULL;

    if (*head == NULL)
    {
        *head = lastnode;
    }

    present = *head;
    /* while loop transversing to when the next node is actually null, signifying the last node*/
    while (present->next != NULL)
    {
        present = present->next;
    }
    /*attaching the new lastnode to the previous last node*/
    present->next = lastnode;
    /* and attaching prev to be the address of previous last node*/
    lastnode->prev = present;

    return (lastnode);
}

void free_linked_list(doubly_habie **head)
{
    doubly_habie *present = *head;
    doubly_habie *temp;

    while (present != NULL)
    {
        temp = present;
        present = present->next;
        free(temp);
    }
    *head = NULL;

}

