#include<stdio.h>
int main()
{
int number=0,temp=0,i=0,value=0;

printf("Enter the number:");
scanf("%d",&number);
while(i<=number)
{

	temp=temp+i;
	i++;

}
    printf("Value=%d \n",temp);
    return 0;
}
