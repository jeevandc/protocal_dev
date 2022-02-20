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
			printf("\n**Customer already exist**\n");
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

/*	new_node->next=customer_db;
	customer_db=new_node;
*/

	printf("\n**New Account Added**\n");

	if (customer_db == NULL) {
		customer_db = new_node;
		return;
	}

	for (current_node = customer_db; current_node->next != NULL; current_node = current_node->next)
	{
	}
	current_node->next = new_node;
	
}

void display_db()
{
	struct linkListNode *head;
	
	if(customer_db==NULL)
        {
                printf("\n**Customer List Empty**\n");
                return;
        }

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


void find_n_customer()
{
struct  linkListNode *current_node;
int i=1,n=0;

	printf("\nEnetr Account Sl.No Number:");
	scanf("%d",&n);

	for(current_node=customer_db;i<n;current_node=current_node->next)
	{
		i++;
	}
	printf("\n--Account %d Customer Name is:%s\n",n,current_node->customer->name);
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
	int option;
        printf("\nEnter the Name of Account Holder to be Deleted:");
        scanf("%s",name);
     //Check if the Key name is in 1st node
	 if(strcmp(customer_db->customer->name,name)==0)
           {
                  printf("\n--Are you sure!! Do you want to delete customer from list? press 1 to confirm:");
		  scanf("%d",&option);
	      
	      if(option==1)
	       {
		  temp= customer_db->next;	//copy the address of next node(2nd node) 
                  free(customer_db->customer);
                  free(customer_db);
		  customer_db=temp;		//make 2nd node as 1st node
		  printf("\n**Account Deleted**\n");
                  return;
	       }
	      else
	       {
	          return;
	       }
	      

           }
	   else //if Key name is not in the 1st node
	   {

		for(node=customer_db;;node=node->next)// traverse the list from 1st node till the node haveing next address = NULL
        	{

			if(node->next==NULL)//List End
                	break;

                	if(strcmp(node->next->customer->name,name)==0)//Check the key name in the next adjacent node
                	{
                  
			    printf("\n--Are you sure!! Do you want to delete customer from list? press 1 to confirm:");
                  	    scanf("%d",&option);

              		    if(option==1)
               		    {	
				temp= node->next->next; 	
	        		free(node->next->customer);
                		free(node->next);	
				node->next=temp;      	//Create Link
				printf("\n**Account Deleted**\n");
				return;
			    }
			    else 
			    {
				return;
			    }
			}

		}
		printf("\n**Customer Not Found**\n");

	   }
}
		
void edit_customer()
{
	char name[256];
        char contact[15];
        int age;
	int amount;

        struct linkListNode *node;
        printf("\nEnter the Name of Account Holder\n");
        scanf("%s",name);

        for(node=customer_db;;node=node->next)
        {
                if(strcmp(node->customer->name,name)==0)
                {
                        printf("Re-Enter Name, Contact no. & Age \n");
                        scanf("%s %s %d",name,contact,&amount);
                        
                        strcpy(node->customer->name,name);
			strcpy(node->customer->contact,contact);
			node->customer->age=age;
                        printf("\n--Customer Info Updated...\n");
			display_db();
                        return;
                   
                }
                if(node->next==NULL)
                break;

        }
        printf("\n**Customer Not Found**\n");

}

int main()
{
	int option;

	while (1) {
		printf("\n\n1. Add customer\n2. Deposit\n3. Withdraw\n4. Delete Customer\n5. Edit Customer information\n6. Display DB\n7. Find Customer Name\n8. Exit\nEnter your option: ");
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
				edit_customer();
				break;
			case 6:
				display_db();
				break;
			case 7:
				find_n_customer();
				break;
			case 8:
				exit(0);
			default:
				printf("\nPlease enter valid option\n");
		}
	}

	return 0;
}
