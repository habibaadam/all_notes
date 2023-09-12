#include <stdio.h>

int func(int a, int b)
{
	return (a + b);
}

int main(void)
{
	int (*point) (int, int);
	/*point is a function pointer*/

	point = func; /* assigning the adress of a function to a function
			 pointer */
	int result;

	result = point(12, 20); /*calling the function with the function
				  pointer*/

	printf("%d\n",result); /*ptinting result of the function within the
				 pointer after it was called*/
}
