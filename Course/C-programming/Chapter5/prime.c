#include<stdio.h>
int main()
{
int num=0,i=0,count=0;

printf("Enter Number : \n");
scanf("%d",&num);
for(i=2;i<num;i++)
{
if(num%i==0)
count++;

}
if(count==0)
{
	printf("%d is a prime number \n",num);
}
else 
{
	printf("%d is not a prime number \n",num);
}

}
