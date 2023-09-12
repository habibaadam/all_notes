#ifndef _NEWNODE_H
#define _NEWNODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct habiNode {
	int data;
	struct habiNode *next;
} habie_n;

habie_n *createnode(int data);
void insertnode(habie_n **head, int data);
void insertnode_at_end(habie_n **head, int data);
void printlist(habie_n *head);
void removenode(habie_n **head);

#endif /* _NEWNODE_H */
