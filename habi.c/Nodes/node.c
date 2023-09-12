#include <stdio.h>
#include <stdlib.h>

typedef struct myfirstnode
{
    int me;
    struct *myfirstnode;
}; myfirstnode
int main()
{
    struct myfirstnode *head; 
    *newnode;
    newnode = malloc(sizeof(myfirstnode));

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
    head->me = 70;                      /* data can now be stored in the node */
    head->next = newnode;
    printf("%d\n", head->me);
              }          /* this will print out the content of the node */
    return (0);
}
