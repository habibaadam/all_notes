#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 5

int stack_array[MAXIMUM];
int tracker = -1;

void pushit(int data)
{

	if (tracker == MAXIMUM - 1)
	{
		printf("Stack is now full\n");
		return;
	}
	tracker = tracker + 1; /*incrementing to add arrays to the stack */
	stack_array[tracker] = data;
}

int popit()
{
	int val;
	val = stack_array[tracker];
	tracker = tracker - 1;
	return val;
}

int main()
{
	int i;
	int popped_data;

	pushit(1);
	pushit(2);
	pushit(3);
	pushit(4);
	pushit(5);
	popped_data = popit();

	if (tracker == -1)
	{
		printf("The stack is empty\n");
		exit(1);
	}

	for (i = 0; i <= tracker; i++)
	{
		printf("%d\n", stack_array[i]);
	}
	return (0);
}
