#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a = malloc(1024);
	printf("%d\n",a[1024]);
}
