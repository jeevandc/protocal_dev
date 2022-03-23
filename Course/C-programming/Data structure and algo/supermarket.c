#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
	char name[256];
	int price;
	int qty;
};


struct item inventory[1000];
int item_count_in_inventory = 0;


void stock_in()
{
	char name[256];
	int price;
	int qty;

	int i;

	printf("please enter item name\n");
	scanf("%s", name);

	printf("please enter price of the item\n");
	scanf("%d", &price);

	printf("please enter qty of the itme\n");
	scanf("%d", &qty);

	for (i = 0; i < item_count_in_inventory; i++) {
		if (strcmp(name, inventory[i].name) == 0) {
			inventory[i].qty = inventory[i].qty + qty;
			return;
		}
	}

	if (item_count_in_inventory == 1000) {
		printf("Inventory db full. Can't add more\n");
		return;
	}

	strcpy(inventory[item_count_in_inventory].name, name);
	inventory[item_count_in_inventory].price = price;
	inventory[item_count_in_inventory].qty = qty;

	item_count_in_inventory++;
}

void sales()
{
	char name[256];
	int qty;
	int price;
	int i;

	printf("Enter name of the item\n");
	scanf("%s", name);

	printf("Enter qty\n");
	scanf("%d", &qty);

	for (i = 0; i < item_count_in_inventory; i++) {
		if (strcmp(inventory[i].name, name) == 0) {
			price = inventory[i].price * qty;
			inventory[i].qty = inventory[i].qty - qty;

			printf("Collect Rupees %d\n", price);
			return;
		}
	}
}

void check_inventory()
{
	int i;

	printf("\nname\t\tqty\t\tprice\n");
	for (i = 0; i < item_count_in_inventory; i++) {
		printf("%s\t\t%d\t\t%d\n", inventory[i].name, inventory[i].qty, inventory[i].price);
	}
}

int main()
{
	int op;

	while (1) {
		printf("\nEnter the operation\n1. Stock-In\n2. Sales\n3. Check Inventory\n4. Exit\n");
		scanf("%d", &op);

		switch (op) {
			case 1:
				stock_in();
				break;
			case 2:
				sales();
				break;
			case 3:
				check_inventory();
				break;
			case 4:
				exit(0);
			default:
				printf("Enter correct operation\n");
				continue;
		}
	}
}
