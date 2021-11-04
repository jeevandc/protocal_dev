#include<stdio.h>

int main()
{
    /*Output Variables*/
    float Z=0.0,R=0.0,A=0.0,X=0.0;
    /*Input Variables*/
    float x=1,y=2,g=3,v=4,a=6,b=5,c=7;

    Z=((x+3)*x*x*x)/((y-4)*(y+5));

    R=(2*v+6.22*(c+b))/(g+v);

    A=((7.7*b)*(x*y+a)/(c-0.8+2*b))/((x+a)*(1/y));

    X=((12*x*x*x)/(4*x))+((8*x*x)/(4*x))+((x)/(8*x))+((8)/(8*x));

    printf("Inputs: x=%.1f,y=%.1f,g=%.1f,v=%.1f,b=%.1f,a=%.1f,c=%.1f \n",x,y,g,v,b,a,c);
    printf("Outputs:\n Z=%f \n R=%f \n A=%f \n X=%f",Z,R,A,X);

    return 0;
}
