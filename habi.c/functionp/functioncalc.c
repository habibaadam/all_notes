#include <stdio.h>

/* trying to do the calculator program by myself
   * using function pointers
   */

/* a collection of functions doing basic arithmetic) */
float add(float a,float b) {return (a + b);}
float sub(float a, float b) {return (a - b);}
float mul(float a, float b) {return (a * b);}
float div(float a, float b) {return (a / b);}

int main()
{
int choice;
float a, b; /* declaring choice of user, and two values user inputs*/

float (*funp[]) (float, float) = {add,sub,mul,div};
/*storing an array of function pointers */

printf("Enter a choice\n");
scanf("%d", &choice);
/**
  * asking user to pick a choice according to the
  * index of the function pointers, 0 is for add,
  * 1 is for sub, 2 is for mul, and 3 is for div
  * scanf as usual will read and store user input into
  * choice variable
 */

printf("Enter two values:\n");
/*asking user to input the two parameter argum-
  ents inside the function they chose */
scanf("%f%f", &a, &b);
printf("%f\n",(*funp[choice])(a,b));/* calling function pointer according to the choice of
			 user input */
return (0);
}
