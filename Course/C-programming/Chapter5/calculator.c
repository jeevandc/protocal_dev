#include<stdio.h>
int main()
{
float a=0.0,b=0.0,result=0.0;

int operation=0;
printf("\n*********************************************\n");
printf("            Menu Driven Calculator               ");
printf("\n*********************************************\n");
printf("Operations:\n 1.addition\n 2.subtraction\n 3.Multiplication\n 4.Division\n 5.Mod_div\n 6.Exit\n 7.Help\n");
for(;operation!=6;)
{
printf("\n Please select valid operation:");
scanf("%d",&operation);
if(operation==6)
       break;
if(operation<=7 && operation >0)
{
 if(operation==7)
{printf("\n Formula:\n Result= (A) operation (B); \n\n Example:\n Operation:2 \n Result=A-B \n\n Enter 6 to exit application\n");}
else
{
printf("\n Enter the value of A:");
scanf("%f",&a);
printf("\n Enter the value of B:");
scanf("%f",&b);
if(operation==1)
{	result=a+b;printf(" %.1f+%.1f=%.1f\n",a,b,result);}
else if(operation==2)
{	result=a-b;printf(" %.1f-%.1f=%.1f\n",a,b,result);}
else if(operation==3)
{	result=a*b;printf(" %.1fx%.1f=%.1f\n",a,b,result);}
else if(operation==4)
{        result=a/b;printf(" %.1f/%.1f=%.1f\n",a,b,result);}
else if(operation==5)
{        result=((int)a)%((int)b);printf(" %.1f mod %.1f=%.1f\n",a,b,result);}
}
}
else
{printf("\n **Please Enter Valid Operation**\n");}

}

return 0;

}
