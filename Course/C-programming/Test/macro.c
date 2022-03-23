#include<stdio.h>

#define CHECK_BIT(data,pos) ((data) & (1<<(pos)))
#define MUL(A,B) ((A)*(B))


void main()
{
	unsigned short int pos = 3;
	
	if(CHECK_BIT(7,pos))
	{
		printf("%d bit is High\n",pos);
	}
	else
	{
		printf("%d bit is Low\n",pos);
	}

	int result= MUL(2+1,4+1);

	printf("%d \n",result);
}
