#include<stdio.h>
int main()
{
	int arr[10];
	int i;
	arr[-5]=10;
	printf("%d",arr[-5]);
	for(i=0;i<10;i++)
	{
		printf("Enter %d th number\n",i);
		scanf("%d",&arr[i]);
	}

	for(i=9;i>=0;i--)
		printf("%d\n",arr[i]);


}
