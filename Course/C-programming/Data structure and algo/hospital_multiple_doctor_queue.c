#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DOCTOR 10

struct patient_info
{
	char name[256];
	char gender[10];
	char number[15];
	int dr_ID;
	int age;
	int token;
};

struct doctor
{
	char name[256];
	int ID;
};


struct linklist
{
	struct patient_info *patient;
	struct linklist *next;
};

int doctor_count=0;

struct linklist *patient_queue[MAX_DOCTOR]={NULL};

struct doctor *doctor_db[MAX_DOCTOR];

void Display_db()
{
     struct linklist *node;
     int i=0;
               
  
     for(i=1;i<=doctor_count;i++)
        {
              

      	  if(patient_queue[i]==NULL)
          {
                printf("Doctor %s Patient Queue is Empty\n",doctor_db[i-1]->name);
		continue;
          }
        
	 printf("\nDoctor %s, Patient Queue:\n Name\t\tGender\t\tage\tnumber\t\t\ttoken\n-----\n",doctor_db[i-1]->name);
         for(node=patient_queue[i];node!=NULL;node=node->next)
         {
                printf("%s\t\t%s\t\t%d\t%s\t\t%d\n",
                                node->patient->name,
                                node->patient->gender,
                                node->patient->age,
                                node->patient->number,
                                node->patient->token);
        }
	printf("-----\n");

        }

        
}

void Add_patient()
{

        char name[256];
        char dr_name[256];
	char gender[10];
        char number[15];
        int  age;
	int Dr_ID=0;
	int i;

        struct linklist *current_node;
        struct linklist *new_node;
	
	printf("Enter consulting doctor Name:\n");
	scanf("%s",dr_name);

	if(doctor_count <1)
        {
                printf("\n**doctor list  Empty**\n");
                return;
        }


  
        for(i=0;i<doctor_count;i++)
        {  
            if(strcmp(doctor_db[i]->name,dr_name)==0)
	    {
	      Dr_ID=doctor_db[i]->ID;
	      printf("Doctor ID:%d\n",doctor_db[i]->ID);
	       break;
	    }
                       
        }
	if(Dr_ID==0)
	{
		printf("\n**Doctor Not found**\n");
		return;

	}

        printf("please enter Name, Gender, Age and Number \n");
        scanf("%s %s %d %s",name,gender,&age,number);

        new_node=malloc(sizeof(struct linklist));
        new_node->patient=malloc(sizeof(struct patient_info));
        strcpy(new_node->patient->name,name);
        strcpy(new_node->patient->gender,gender);
        strcpy(new_node->patient->number,number);
        new_node->patient->age=age;
	new_node->patient->dr_ID=Dr_ID;
        new_node->next=NULL;

        printf("\n**New Patient  Added to Doctor ID:%d**\n",Dr_ID);

        if(patient_queue[Dr_ID] == NULL)
        {
                patient_queue[Dr_ID]=new_node;
                return;
	}
        for(current_node=patient_queue[Dr_ID];current_node->next != NULL;current_node=current_node->next);

        current_node->next=new_node;

}



void Add_doctor()
{
        char name[256];
	int i=0;

        if(doctor_count>MAX_DOCTOR)
        {
                printf("\n**Doctor DataBase Full**\n");
                return;
        }

        printf("Enter Doctor Name \n");
        scanf("%s",name);
	if(doctor_count > 0)
	{
	for(i=0;i<doctor_count;i++)
	{
		if(strcmp(doctor_db[i]->name,name)==0)
		{
			printf("Doctor name already exist, please add last name and try again\n");
			return;
		}
	}
	}

        doctor_db[doctor_count]=malloc(sizeof(struct doctor));

        strcpy(doctor_db[doctor_count]->name,name);
        doctor_db[doctor_count]->ID=doctor_count+1;
        doctor_count++;
        return;


}

void display_doctors()
{
	int i=0;
        if(doctor_count <1)
        {
                printf("\n**doctor list  Empty**\n");
                return;
        }


        printf("\nName\t\t\tID\n");
        for(i=0;i<doctor_count;i++)
        {
                printf("%s\t\t\t%d\n",
                        doctor_db[i]->name,
                        doctor_db[i]->ID );
        }

}


void Doctor_call()
{
	char dr_name[256];
	int i=0,Dr_ID=0;

	struct linklist *temp;

	if(doctor_count <1)
        {
                printf("\n**doctor list  Empty**\n");
                return;
        }

        printf("Enter doctor Name:\n");
        scanf("%s",dr_name);

 	for(i=0;i<doctor_count;i++)
        {
            if(strcmp(doctor_db[i]->name,dr_name)==0)
            {
              Dr_ID=doctor_db[i]->ID;
              printf("Doctor ID:%d\n",doctor_db[i]->ID);
               break;
            }

        }

	if(Dr_ID==0)
	{
		printf("\n**Doctor Not Found**\n");
		return;
	}

        if(patient_queue[Dr_ID]==NULL)
        {
                printf("\n**Patient Queue Empty**\n");
                return;
        }

	printf("\nPatient Attended:%s \n",patient_queue[Dr_ID]->patient->name);
	
	temp=patient_queue[Dr_ID]->next;
        free(patient_queue[Dr_ID]->patient);
        free(patient_queue[Dr_ID]);

        patient_queue[Dr_ID]=temp;

        if(patient_queue[Dr_ID]==NULL)
        {
                printf("\n**Patient Queue Empty**\n");
                return;
        }
        printf("\nNext Patient Name:%s\n\nList:\n",patient_queue[Dr_ID]->patient->name);

	Display_db();
}

void main()
{
        int option=0;

        while(1)
        {
                printf("\n Enter your Option:\n 1. Add doctor\n 2. Add Patient\n 3. Display Doctor list\n 4. Display Patient Queue\n 5. Doctor Call\n 6. Exit\n");
                scanf("%d",&option);

                switch (option)
                {
                        case 1:Add_doctor();
                                break;
                        case 2:Add_patient();
                                break;
			case 3:display_doctors();
                                break;
                        case 4:Display_db();
                                break;
                        case 5:Doctor_call();
                                break;
                        case 6:exit(0);
                        default:
                                printf("\nEnter vaid option\n");
                }
        }


}


