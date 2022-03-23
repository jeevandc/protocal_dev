#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bank {
	char name[256];
	char contact[15];
	int age;
	int balance;
};


struct bank customer[1000];
int customer_count_in_inventory = 0;


void Create_account()
{
	char name[256];
	int amount;
	int age;
	char contact[15];

	int i;

	printf("please enter customer name\n");
	scanf("%s", name);

	printf("please enter age of the customer\n");
	scanf("%d", &age);

	printf("please enter contact no. of the customer\n");
	scanf("%s", contact);

	printf("please enter Initial amount deposit\n");
        scanf("%d", &amount);

	for (i = 0; i < customer_count_in_inventory; i++) {
		if (strcmp(name, customer[i].name) == 0) {
			printf("User already exist, Try another name\n");
			return;
		}
	}

	if (customer_count_in_inventory == 1000) {
		printf("Inventory db full. Can't add more\n");
		return;
	}

	strcpy(customer[customer_count_in_inventory].name, name);
	customer[customer_count_in_inventory].age = age;
	strcpy(customer[customer_count_in_inventory].contact, contact);
	customer[customer_count_in_inventory].balance = amount;
	customer_count_in_inventory++;
}
void deposit()
{

        char name[256];
        int amount;

        int i;

        printf("Enter name of the customer\n");
        scanf("%s", name);

        printf("Enter deposit amount\n");
        scanf("%d", &amount);

        for (i = 0; i < customer_count_in_inventory; i++) {
                if (strcmp(customer[i].name, name) == 0) {
                       
                        customer[i].balance= customer[i].balance + amount;
                        

                        printf("Cash Deposit Successfull, Available Balance: %d\n", customer[i].balance);
                        return;
                }

        }

        printf("\nCustomer not fund\n");
}


void withdraw()
{
	char name[256];
	int amount;
	
	int i;

	printf("Enter name of the customer\n");
	scanf("%s", name);

	printf("Enter withdrawal amount\n");
	scanf("%d", &amount);

	for (i = 0; i < customer_count_in_inventory; i++) {
		if (strcmp(customer[i].name, name) == 0) {
			if(amount >= customer[i].balance)
			{
				printf("Insufficient Balance\n");
				return;
			}
			else
			{
			customer[i].balance= customer[i].balance - amount;
			}

			printf("Cash Withdrawal Successfull, Remaining balance: %d\n", customer[i].balance);
			return;
		}

	}

	printf("\nCustomer not fund\n");
}

void database()
{
	int i;

	printf("\nname\t\tage\t\tcontact no.\t\tbalance\n");
	for (i = 0; i < customer_count_in_inventory; i++) {
		printf("%s\t\t%d\t\t%s\t\t%d\n", customer[i].name,customer[i].age, customer[i].contact,customer[i].balance);
	}
}
void check_balance()
{
        char name[256];

        int i;

        printf("Enter name of the customer\n");
        scanf("%s", name);


        for (i = 0; i < customer_count_in_inventory; i++) {
                if (strcmp(customer[i].name, name) == 0) {

                        printf("Name: %s , Available Balance: %d\n",customer[i].name, customer[i].balance);
                        return;
                }

        }

        printf("\nCustomer not fund\n");

}
int main()
{
	int  operation;

	while (1) {
		printf("\nEnter the operation\n1. Cash Deposit\n2. Chash Withdraw \n3. Balance Enquiry\n4. Create Account\n5. Customer Database\n6. Exit\n");
		scanf("%d", &operation);

		switch (operation) {
			case 1:
				deposit();
				break;
			case 2:
				withdraw();
				break;
			case 3:
				check_balance();
				break;
			case 4:
				Create_account();
				break;
			case 5:
				database();
				break;
			case 6:
				exit(0);
			default:
				printf("Enter correct operation\n");
				continue;
		}
	}
}
