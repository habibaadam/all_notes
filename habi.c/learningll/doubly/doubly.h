#ifndef _DOUBLY_H_
#define _DOUBLY_H_

#include <stdio.h>
#include <stdlib.h>

 typedef struct Habinode {
    int data;
    struct Habinode *prev;
    struct Habinode *next;
} doubly_habie;

doubly_habie *createNode(int data);
doubly_habie *insertatstart(doubly_habie **head, int data);
size_t printdoublylist(const doubly_habie *head);
size_t numofelements(const doubly_habie *head);
doubly_habie *insert_atend(doubly_habie **head, int data);
void free_linked_list(doubly_habie *head);


#endif /*_DOUBLY_H_*/
