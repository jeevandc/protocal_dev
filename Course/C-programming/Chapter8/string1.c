#include<stdio.h>
int main()
{
	char str[10]="Name";

	char *sptr=str;
	printf("%s\n",sptr);
	printf("%u ,%u \n",str,sptr);
}
