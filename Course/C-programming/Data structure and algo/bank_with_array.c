#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank{
	char name[256];
	char contact[15];
	int age;
	int amt;
};


struct bank *customer_db[100];

int customer_count;

void add_customer()
{
	char name[256];
	char contact[15];
	int age;
	int amt;
	
	int node=0;

	printf("Enter Name, Contact , Age and Amount:\n");
	scanf("%s %s %d %d",name,contact,&age,&amt);

	for(node=0;node<customer_count;node++)
	{
		if(strcmp(customer_db[node]->name,name)==0)
		{
			printf("\n--Customer already exist--");
			return;
		}
	}

	customer_db[customer_count]=malloc(sizeof(struct bank));
	strcpy(customer_db[customer_count]->name,name);
	strcpy(customer_db[customer_count]->contact,contact);
	customer_db[customer_count]->age=age;
	customer_db[customer_count]->amt=amt;
	customer_count++;
	printf("\n--Account Added--\n");
		
}

void display_db()
{
	int node=0;
	if(customer_count==0)
	{
		printf("\n**Customer list is empty**\n");
		return;
	}
	printf("\nName\t\tContact\t\t\tage\t\tAmount\n");
	for(node=0;node<customer_count;node++){
		printf("%s\t\t%s\t\t%d\t\t%d\n",customer_db[node]->name,customer_db[node]->contact,customer_db[node]->age,customer_db[node]->amt);
		
	}

}

void delete_customer()
{
	char name[256];
	int i=0,option=0;
	int j=0;
	

	if(customer_count==0)
	{
		printf("\nCustomer list is Empty\n");
		return;
	}
	printf("Enter the name of the customer to be deleted:\n");
	scanf("%s",name);
	
	for(i=0;i<customer_count;i++)
	{
		if(strcmp(customer_db[i]->name,name)==0)
		{
			printf("\n--Are you sure!! Do you want to delete customer from list? press 1 to confirm:");
                        scanf("%d",&option);
			if(option==1)
                        {
                               free(customer_db[i]);			                                       
			       for(j=i;j<customer_count;j++)
			       {
				 customer_db[j]=customer_db[j+1];
			       }
			       customer_count--;
                               printf("\n**Account Deleted**\n");
                               return;
                        }
                        else
                        {
                                return;
                        }
		}
	}
}

void deposit()
{
	char name[256];
        int amount=0,i=0;

        if(customer_count==0)
        {
                printf("\nCustomer list is Empty\n");
                return;
        }
        printf("\nEnter the Deposit Account Name:\n");
        scanf("%s",name);
	
	for(i=0;i<customer_count;i++)
        {
                if(strcmp(customer_db[i]->name,name)==0)
                {
                     printf("\nEnter the deposit amount:");
		     scanf("%d",&amount);
		     customer_db[i]->amt=customer_db[i]->amt+amount;
		     printf("\nDeposit Seccussful**\n");
		     display_db();   
                        return;
                }
        }

	printf("\n**Customer Not Found**\n");
}

void withdraw()
{
	char name[256];
        int amount=0,i=0;

        if(customer_count==0)
        {
                printf("\nCustomer list is Empty\n");
                return;
        }
        printf("Enter the Withdraw Account Name:\n");
        scanf("%s",name);

        for(i=0;i<customer_count;i++)
        {
                if(strcmp(customer_db[i]->name,name)==0)
                {
                     printf("\nEnter the Withdraw amount:");
                     scanf("%d",&amount);
		     if(customer_db[i]->amt<amount)
                     {
                        printf("\n**Insufficent Balance**\n");
                        return;
                     }

                     customer_db[i]->amt=customer_db[i]->amt-amount;
                     printf("\nDeposit Seccussful**\n");
                     display_db();
                     return;
                }
        }

        printf("\n**Customer Not Found**\n");

}

void edit_info()
{

}

int main()

{
	int option=0;

	while(1)
	{
		printf("\n 1. Add customer\n 2. Display DB.\n 3. Delete Customer\n 4. Deposit\n 5. Withdraw\n 6. Edit customer info\n 7. Exit\n Enter your option\n");
		scanf("%d",&option);
		
		switch (option)
		{
			case 1:add_customer();
			       break;
			case 2:display_db();
			       break;
			case 3:delete_customer();
			       break;
			case 4:deposit();
			       break;
			case 5:withdraw();
			       break;
			case 6:edit_info();
			       break;
			case 7:
			       exit(0);
			default:
			       printf("\nEnter valid option\n");
			       
		}
	}
}



