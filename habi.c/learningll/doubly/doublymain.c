#include "doubly.h"

int main(void)
{
    size_t element_count;
    doubly_habie *head = NULL;

    insertatstart(&head, 27);
    insertatstart(&head, 77);
    insertatstart(&head, 97);

    printf("Doubly linked list after insertion of nodes \n");
    printdoublylist(head);

    insert_atend(&head, 22);
    insert_atend(&head, 85);
    printf("Doubly list after insertion of nodes at the end \n");
    printdoublylist(head);
    
    element_count = numofelements(head);
    printf("%zu Elements \n", element_count);


    return (0);
}
