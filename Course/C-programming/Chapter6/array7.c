#include<stdio.h>
#include<stdlib.h>

int main()
{
	 int number=0,i=0;
 	 int *s_add,*l_add;
	
	 printf("Enter how many numbers \n");
	 scanf("%d",&number);

	 s_add=malloc(number*sizeof(number));
 	

	 for(i=0;i<number;i++)
	 {
		 printf("Enter %d th element \n",i);
		 scanf("%d",s_add+i);
	 }
        
	 printf("Reverse Order \n");

	 for(l_add=(s_add+(number-1));l_add>=s_add;l_add--)
	 {
		 printf("%d \n",*l_add);
	 }

}
