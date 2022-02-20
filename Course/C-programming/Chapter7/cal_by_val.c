#include<stdio.h>
void fn(int a,int *b)
{	
	a=*b;
	printf("%d,%d \n",a,*b);
	b=&a;
}
int main()
{
	int a,b;
	a=10;
	b=20;
	fn(a,&b);
	printf("%d,%d \n",a,b);

}

