#include<stdio.h>

int is_prime(int j);

int main()
{
        int i=0,count=0,j=0;
        int input=0,result=0;
        printf("Enter Number : \n");
        scanf("%d",&input);

                for(j=2;j<=input;j++)
                {
                       if(is_prime(j))
		       {
			  result+=j;
		       }
		    
                }
                printf("Result:%d\n",result);

return 0;

}


int is_prime(int j)
{

	int i=0,count=0;
                //      printf("j=%d\n",j);
         for(i=2;i<j;i++)
           {
               if(j%i==0)
               count++;
           }
           if(count==0)
           {
             return 1;  
           }
	   else
	   {
             return 0;
	   }

}
