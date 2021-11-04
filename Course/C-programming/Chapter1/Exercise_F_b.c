/* The distance between two cities (in km.) is input through the
keyboard. Write a program to convert and print this distance in
meters, feet, inches and centimeters.*/

#include<stdio.h>
int main()
{ 
  float meters,feet,inches,cm,km;
  printf("Enter the distance in km\n");
  scanf("%f",&km);
  meters=km*1000.0;
  cm=meters*100.0;
  feet=3.28084*meters;
  inches=12.0*feet;
  printf("*********************************\n");
  printf("The distance in meters = %.2f\n",meters);
  printf("The distance in centimeters = %.2f\n",cm);
  printf("The distance in feet = %.2f\n",feet);
  printf("The distance in inches = %.2f\n",inches);
  printf("*********************************\n");
  return 0;
 }
