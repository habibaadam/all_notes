#include "newnode.h"

int main()
{
	habie_n *head = NULL;

	insertnode(&head, 7);
	insertnode(&head, 17);
	insertnode(&head, 27);

	printf("Updated linked list after insertion: \n");
	printlist(head);

	removenode(&head); /*removes node at the beginning of linked list */

	printf("Linked List after removing node at begining: \n");
	printlist(head);

	insertnode_at_end(&head, 37);

	printf("Linked list after added a node at the end of list: \n");
	printlist(head);

	return (0);
}

