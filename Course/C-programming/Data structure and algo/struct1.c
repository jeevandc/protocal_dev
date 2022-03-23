#include<stdio.h>

int main()
{
	
	int n=0,i=0;
	char num[100][30];
	printf("Enter How many numbers to be stored:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dst number\n",i+1);
		scanf("%s",&num[i]);
	}

	   for(i=0;i<n;i++)
        {
                printf(" %dst number=%s\n",i+1,num[i]);
               
        }






	return 0;
}
