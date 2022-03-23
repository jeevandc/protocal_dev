#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank {
	char name[256];
	char contact[15];
	int age;
	int amt;
};

struct linkListNode {
	struct bank* customer;
	struct linkListNode* next;
};

struct linkListNode *customer_db = NULL;


void add_customer()
{
	char name[256];
	char contact[15];
	int age;
	int amt;

	struct  linkListNode *current_node;
	struct linkListNode *new_node;

	printf("Please Enter Name, Contact, Age and Amount\n");

	scanf("%s %s %d %d", name, contact, &age,&amt);

	for (current_node = customer_db; current_node != NULL; current_node = current_node->next) {
		if (strcmp(current_node->customer->name, name) == 0) {
			printf("Customer already exist\n");
			return;
		}
	}

	new_node = malloc(sizeof(struct linkListNode));
	new_node->customer = malloc(sizeof(struct bank));
	
	strcpy(new_node->customer->name, name);
	strcpy(new_node->customer->contact, contact);
	new_node->customer->age = age;
	new_node->customer->amt=amt;
	new_node->next = NULL;

	if (customer_db == NULL) {
		customer_db = new_node;
		return;
	}

	for (current_node = customer_db; current_node->next != NULL; current_node = current_node->next);

	current_node->next = new_node;
}

void display_db()
{
	struct linkListNode *head;
	
	printf("\nName\t\tContact\t\t\tage\t\tAmount\n");
	printf("________________________________________________________________\n");
	for(head=customer_db;;head=head->next)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\n",head->customer->name,head->customer->contact,head->customer->age,head->customer->amt);
				if(head->next==NULL)
		{
			printf("________________________________________________________________\n");
			return;
		}
	}
}

void deposit()
{
	char name[256];
	int amount;
	struct linkListNode *node;
	printf("\nEnter the Name of Account Holder\n");
	scanf("%s",name);

	for(node=customer_db;;node=node->next)
	{
		if(strcmp(node->customer->name,name)==0)
		{
			printf("Enter Deposit Amount\n");
			scanf("%d",&amount);
			node->customer->amt=node->customer->amt+amount;
			printf("\n--Deposit Seccussful, Available Balance:%d\n",node->customer->amt);
			return;	
		}
		if(node->next==NULL)
		break;

	}
	printf("\n**Customer Not Found**\n");

}

void withdraw()
{
        char name[256];
        int amount;
        struct linkListNode *node;
        printf("\nEnter the Name of Account Holder\n");
        scanf("%s",name);

        for(node=customer_db;;node=node->next)
        {
                if(strcmp(node->customer->name,name)==0)
                {
                        printf("Enter Withdraw Amount\n");
                        scanf("%d",&amount);
			if(node->customer->amt<amount)
			{
				printf("\n**Insufficent Balance**\n");
				return;
			}
			else
			{
                        node->customer->amt=node->customer->amt-amount;
                        printf("\n--Withdraw Seccussful, Available Balance:%d\n",node->customer->amt);
                        return;
			}
                }
                if(node->next==NULL)
                break;

        }
        printf("\n**Customer Not Found**\n");

}

void delete_customer()
{
	char name[256];
        struct linkListNode *node;
	struct linkListNode *temp;
        printf("\nEnter the Name of Account Holder to be Deleted:");
        scanf("%s",name);

	 if(strcmp(customer_db->customer->name,name)==0)
           {
                  temp= customer_db->next;
                  free(customer_db->customer);
                  free(customer_db);
		  customer_db=temp;
		  printf("\n**Account Deleted**\n");
                  return;

           }
	   else
	   {

		for(node=customer_db;;node=node->next)
        	{

			if(node->next==NULL)
                	break;

                	if(strcmp(node->next->customer->name,name)==0)
                	{
                  
				temp= node->next->next; 
	        		free(node->next->customer);
                		free(node->next);
				node->next=temp;
				printf("\n**Account Deleted**\n");
				return;
			}

		}
		printf("\n**Customer Not Found**\n");

	   }
}
		

int main()
{
	int option;

	while (1) {
		printf("\n\n1. Add customer\n2. Deposit\n3. Withdraw\n4. Delete Customer\n5. Display DB\n6. Exit\nEnter you option: ");
		scanf("%d", &option);

		switch (option) {
			case 1:
				add_customer();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				delete_customer();
				break;
			case 5:
				display_db();
				break;
			case 6:
				exit(0);
			default:
				printf("\nPlease enter valid option\n");
		}
	}

	return 0;
}
