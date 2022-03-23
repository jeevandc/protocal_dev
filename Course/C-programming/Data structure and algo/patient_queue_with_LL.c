#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct patient_info
{
	char name[256];
	char gender[10];
	char number[15];
       	int age;
	int token;	
};

struct linklist
{
	struct patient_info *patient;
	struct linklist *next;	
};

struct linklist *first_patient=NULL;
int tok=0;

void Add_patient()
{

	char name[256];
	char gender[10];
	char number[15];
	int  age;

	struct linklist *current_node;
	struct linklist *new_node;

	printf("please enter Name, Gender, Age and Number \n");
       	scanf("%s %s %d %s",name,gender,&age,number);	
	
	new_node=malloc(sizeof(struct linklist));
	new_node->patient=malloc(sizeof(struct patient_info));
	tok++;
	strcpy(new_node->patient->name,name);
	strcpy(new_node->patient->gender,gender);
	strcpy(new_node->patient->number,number);
	new_node->patient->age=age;
	new_node->patient->token=tok;
	new_node->next=NULL;
	
	printf("\n**New Patient  Added**\n");

	if(first_patient == NULL)
	{
		first_patient=new_node;
		return;
	}


	for(current_node=first_patient;current_node->next != NULL;current_node=current_node->next);

	current_node->next=new_node;

}

void Display_db()
{

	struct linklist *node;

	if(first_patient==NULL)
	{
		printf("Patient Queue is Enpty\n");
		return;
	}
	
	printf("Name\t\tGender\t\tage\tnumber\t\t\ttoken\n");
	for(node=first_patient;;node=node->next)
	{
		printf("%s\t\t%s\t\t%d\t%s\t\t%d\n",
				node->patient->name,
				node->patient->gender,
				node->patient->age,
				node->patient->number,
				node->patient->token);
		
		if(node->next==NULL)
		{
		return;
		}
	}
}

void Doctor_call()
{
	struct linklist *temp;

	if(first_patient==NULL)
        {
                printf("\n**Patient Queue Empty**\n");
                return;
        }

	temp=first_patient->next;

	printf("\nPatient Attended:%s -- Token:%d\n",first_patient->patient->name,first_patient->patient->token);

	free(first_patient->patient);
	free(first_patient);

	first_patient=temp;

	if(first_patient==NULL)
	{
		printf("\n**Patient Queue Empty**\n");
		return;
	}
	printf("\nNext Token:%d -- Name:%s\n\nList:\n",first_patient->patient->token,first_patient->patient->name);

	Display_db();

}

void main()
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
