#include<stdio.h>
void swap(int * x,int * y);
int main()
{
	int a=10,b=20;

	swap(&a,&b);
	printf("a=%d , b=%d \n",a,b);

	return 10;

}

void swap(int * x,int * y)
{
 int t=0;
 t=*x;
 *x=*y;
 *y=t;
}
