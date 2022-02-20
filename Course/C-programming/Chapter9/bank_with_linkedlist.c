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

	printf("Please enter name, contact, age and Amount\n");

	scanf("%s %s %d %d", &name, &contact, &age,&amt);

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

int display_db()
{
struct linkListNode *head;
printf("Name\tContact\t\tage\tAmount\n");
//for(head=customer_db;head->next!=NULL;head=head->next)
for(head=customer_db;;head=head->next)
{
	printf("%s\t%s\t%d\t%d\n",head->customer->name,head->customer->contact,head->customer->age,head->customer->amt);
if(head->next==NULL)
	return;
}

}
int main()
{
	int option;

	while (1) {
		printf("\n\n1. Add customer\n2. Deposit\n3. Withdraw\n4.Display DB\n5. Exit\nEnter you option: ");
		scanf("%d", &option);

		switch (option) {
			case 1:
				add_customer();
				break;
			case 2:
			//	deposit();
				break;
			case 3:
			//	withdraw();
				break;
			case 4:
				display_db();
				break;
			case 5:
				exit(0);
			default:
				printf("Please enter valid option\n");
		}
	}

	return 0;
}
