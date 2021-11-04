##include<stdio.h>

int main()
{
    int mango;
    char ans;
    float price;
    printf("Mango available? Press y/n \n");
    scanf("%c",&ans);
    if(ans=='y')
    {
     printf("How many mango do u have? \n");
     scanf("%d",&mango);
     if(mango>=1)
     {
     printf("What is the price of mango? \n");
     scanf("%f",&price);
     if(price<=30)
     {
         printf("Give me 5kg \n");
     }
     else
     {
        printf("Give me only 2kg \n");
     }
     }
     else
     {
         printf("sorry no mango available \n");
     }

     }
     else
     {
         printf("sorry no stock \n");
     }


    return 0;
}
