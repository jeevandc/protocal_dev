/* Ramesh’s basic salary is input through the keyboard. His dearness
allowance is 40% of basic salary, and house rent allowance is 20% of
basic salary. Write a program to calculate his gross salary
formula: gross salary=basic salary+DA+HRA.
*/
#include<stdio.h>
int main()
{
 float Basic_sal=0.0,Gross_sal=0.0;
 printf("Enter the basic salary of Ramesh : ");
 scanf("%f", &Basic_sal);
 Gross_sal=Basic_sal+(Basic_sal*40/100)+(Basic_sal*20/100);
 printf("Gross salary of Ramesh is %f.\n", Gross_sal);
 return 0;
}
