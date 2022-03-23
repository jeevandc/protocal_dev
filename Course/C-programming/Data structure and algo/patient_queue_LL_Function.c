#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Queue implementation **/
struct queue_node {
	void* data;
	struct queue_node* next;
};

int enqueue(struct queue_node **queue, void *data)
{
	struct queue_node* new_node = malloc(sizeof(struct queue_node));
	struct queue_node* cur_node = NULL;

	new_node->data = data;
	new_node->next = NULL;

	if (!*queue) {
		*queue = new_node;
		return 0;
	}

	for(cur_node = *queue; cur_node->next != NULL; cur_node = cur_node->next) {
	}
	cur_node->next = new_node;

	return 0;
}

void* dequeue(struct queue_node** queue)
{
	if (*queue == NULL) {
		return NULL;
	}

	void* data = (*queue)->data;
	struct queue_node* tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);

	return data;
}
/** Queue implementation over **/


struct patient {
	char name[256];
	int age;
};


struct queue_node* patient_queue = NULL;

void add_patient()
{
	char name[256];
	int age;

	printf("Enter name and age\n");
	scanf("%s %d", name, &age);

	struct patient* new_patient = malloc(sizeof(struct patient));
	strcpy(new_patient->name, name);
	new_patient->age = age;

	enqueue(&patient_queue, new_patient);
}

void next_patient()
{
	struct patient* next_patient = (struct patient*) dequeue(&patient_queue);
	//next_patient = NULL
	if (!next_patient) {
		printf("No patient in queue\n");
		return;
	}

	printf("Next patient name: %s, age: %d\n", next_patient->name, next_patient->age);
	return;
}

int main()
{
	int option;
	while(1) {
		printf("1.Add patient\n2.Next patient in queue\n0.Exit\n");
		scanf("%d", &option);

		switch(option) {
			case 1:
				add_patient();
				break;
			case 2:
				next_patient();
				break;
			case 0:
				exit(0);
			default:
				printf("Provide valid option\n");
		}
	}
}
