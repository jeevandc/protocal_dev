#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct patient
{
	char name[256];
	char sex[10];
	char number[15];
	int age;
	int token;
};

struct patient *patient_db[100];

int patient_count=0;
int last_patient=0;
int first_patient=0;

void Add_patient()
{
	char name[256];
	char sex[10];
	char number[15];
	int age;
	int i=0;
	
	if(patient_count>100)
	{
		printf("\n**Patient DataBase Full**\n");
		return;
	}

	printf("Enter the Name , Gender , Age and Number \n");
	scanf("%s%s%d%s",name,sex,&age,number);

	patient_db[patient_count]=malloc(sizeof(struct patient));

	strcpy(patient_db[patient_count]->name,name);
	strcpy(patient_db[patient_count]->sex,sex);
	strcpy(patient_db[patient_count]->number,number);
	patient_db[patient_count]->age=age;
	patient_db[patient_count]->token=patient_count+1;
	patient_count++;last_patient++;
	return;
}

void Display_db()
{
	int i=0;
	if(first_patient==patient_count)
        {
                printf("\n**Patient Queue Empty**\n");
                return;
        }


	printf("\nName\t\tGender\tAge\tNumber\t\t\tToken\n");
	for(i=first_patient;i<patient_count;i++)
	{
		printf("%s\t\t%s\t%d\t%s\t\t%d\n",
			patient_db[i]->name,
	      		patient_db[i]->sex,
			patient_db[i]->age,
			patient_db[i]->number,
			patient_db[i]->token );		
	}


}


void Doctor_call()
{
	int i=0;
	
	printf("\nPatient Attended:");
	printf("\n%s\t\t%s\t%d\t%s\n",
                        patient_db[first_patient]->name,
                        patient_db[first_patient]->sex,
                        patient_db[first_patient]->age,
                        patient_db[first_patient]->number);

	free(patient_db[first_patient]);
	
	first_patient++;

  	if(first_patient==patient_count)
        {
                printf("\n**No patients**\n");
                return;
        }

	printf("\nNext Token:%d",patient_db[first_patient]->token);
	printf("\nNext Patient details:");
        printf("\n%s\t\t%s\t%d\t%s\n",
                        patient_db[first_patient]->name,
                        patient_db[first_patient]->sex,
                        patient_db[first_patient]->age,
                        patient_db[first_patient]->number);

	printf("\nRemaing Patients:%d\nPatient Queue:",last_patient-first_patient);
		
	Display_db();

}
void main ()
{
	int option=0;
	while(1)
	{
		printf("\n Enter your Option:\n 1. Add Patient\n 2. Display DB\n 3. Doctor Call\n 4. Exit\n");
		scanf("%d",&option);

		switch (option)
		{
			case 1:Add_patient();
				break;
			case 2:Display_db();
				break;
			case 3:Doctor_call();
				break;
			case 4:exit(0);
			default:
				printf("\nEnter vaid option\n");
		}
	}
	


}


