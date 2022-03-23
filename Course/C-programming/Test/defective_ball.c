#include <stdio.h>
#define WEIGHT 10
int main()
{
    int ball[100];
    int i=0,group1_wght=0,group2_wght=0,group3_wght=0;
/**********Filling Balls weights***********************/
    for(i=0;i<10;i++)
    {
        ball[i]=WEIGHT;
    }
    for(i=10;i<80;i++)
    {
        ball[i]=WEIGHT;
    }
    ball[80]=30;    // Make 80th ball defective

    for(i=81;i<=99;i++)
    {
        ball[i]=WEIGHT;
    }
/***********************************************************/
// Printing all balls weight
    for(i=0;i<=99;i++)
    {
  printf("%d-  %d \n",i,ball[i]);
    }
//Calculate group1_wght
    for(i=0;i<40;i++)
    {
        group1_wght+=ball[i];
    }
//Calculate group2_wght
   for(i=40;i<80;i++)
    {
        group2_wght+=ball[i];
    }
//Calculate group3_wght
    for(i=80;i<=99;i++)
    {
        group3_wght+=ball[i];
    }

   printf("G1W=%d  G2W=%d G3W=%d\n",group1_wght,group2_wght,group3_wght);

    if(group1_wght==group2_wght)
    {
           for(i=80;i<=99;i++)
            {
                if(ball[i]!=WEIGHT)
                {
                printf(" Group 3 Ball number %d is defective\n",i);
                break;
                }
            }
    }
    else
    {
        if(group1_wght>group2_wght)
        {
            for(i=0;i<40;i++)
            {
                if(ball[i]!=WEIGHT)
                {
                printf(" Group 2 Ball number %d is defective\n",i);
                break;
                }
            }
        }
        else if(group1_wght<group2_wght)
        {
            for(i=40;i<80;i++)
            {
                if(ball[i]!=WEIGHT)
                {
                printf(" Group 3 Ball number %d is defective\n",i);
                break;
                }
            }
        }
    }

    return 0;
}
