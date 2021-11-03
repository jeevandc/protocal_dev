#include<stdio.h>
int main()
{
	float speed=0.0,fuel_level=0.0,distance=0.0;
	int mileage=0,T_distance=0;
	printf("Enter speed in Km/h \n");
	scanf("%f",&speed);
	printf("Enter Fuel level in liters \n");
	scanf("%f",&fuel_level);
	printf("Enter distance of approching fuel station in km \n");
	scanf("%f",&distance);
	printf("\n**************************\n");

	if(speed<100)
	{
		mileage=20;
		printf("Maileage is %d Kmpl\n",mileage);
	}
	if(speed>=100)
	{
		mileage=10;
		printf("Maileage is %d Kmpl\n",mileage);
	}
	
	T_distance=fuel_level*mileage;

	printf("You can travel %d kms\n",T_distance);

	if(T_distance<distance)
	{
		printf("Warning!!\nPlease Reduce the speed\n");
	}
	else
	{
		printf("Drive at same speed \n");
	}
	printf("**************************\n");
	return 0;
}
