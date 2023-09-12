#include "newnode.h"

habie_n* createnode(int data);
void insertnode(habie_n **head, int data); /*insert node at start*/
void insertnode_at_end(habie_n **head, int data); /* insert at the end */
void printlist(habie_n *head); /* print each node */
void removenode(habie_n **head); /* removes a node */


habie_n *createnode(int data)
{
	habie_n *newhabie = malloc(sizeof(habie_n));
	if (newhabie == NULL)
	{
		return (NULL);
	}

	newhabie->data = data;
	newhabie->next = NULL;
	return (newhabie);
}

void insertnode(habie_n **head, int data)
{
	habie_n *newhabie = createnode(data);
	newhabie->next = *head;
	*head = newhabie;
}

void insertnode_at_end(habie_n **head, int data)
{
	habie_n *current; /* will store the head if it is not empty */
	habie_n *lasthabie = createnode(data);
	if (lasthabie == NULL)
	{
		return;
	}
	lasthabie->data = data;
	lasthabie->next = NULL;

	if (*head == NULL)
	{
		*head = lasthabie; /*if head is empty, last node becomes head*/
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		} /*while loop moving to the very last node */
		current->next = lasthabie; /*the current last node is now linked
					     to our new last node lasthabie */
	}
}


void printlist(habie_n *head)
{
	habie_n *current = head; /*local varable to store value of og head */
	while (current != NULL) /* while loop to iterate through list if members
				   of linked list is not empty */
	{
		printf("%i\n", current->data); /*printing value of data */
		current = current->next; /* allows iterator to move to the
					    next member of linked list */
	}
	printf("\n");
}

void removenode(habie_n **head)
{
	if (*head == NULL)
	{
		return;
	}
	habie_n *temp = *head;
	*head = (*head)->next;
	free(temp);
}


