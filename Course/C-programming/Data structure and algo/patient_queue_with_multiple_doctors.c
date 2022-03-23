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

struct doctor {
	char name[256];
	struct queue_node* patient_queue;
};

struct queue_node* doctor_queue = NULL;

struct queue_node** get_patient_queue_of_doctor(char* doctor_name)
{
	struct queue_node* cur_node;
	struct doctor* doc_node = NULL;

	for (cur_node = doctor_queue; cur_node != NULL; cur_node = cur_node->next) {
		doc_node = (struct doctor*)cur_node->data;
		if (strcmp(doc_node->name, doctor_name) == 0) {
			return &(doc_node->patient_queue);
		}
	}

	doc_node = malloc(sizeof(struct doctor));
	strcpy(doc_node->name, doctor_name);
	doc_node->patient_queue = NULL;

	enqueue(&doctor_queue, doc_node);

	return &(doc_node->patient_queue);
}


void add_patient()
{
	char patient_name[256];
	char doctor_name[256];
	int age;
	struct queue_node** patient_queue = NULL;

	printf("Enter name and age of patient and doctor name\n");
	scanf("%s %d %s", patient_name, &age, doctor_name);

	struct patient* new_patient = malloc(sizeof(struct patient));
	strcpy(new_patient->name, patient_name);
	new_patient->age = age;

	patient_queue = get_patient_queue_of_doctor(doctor_name);

	enqueue(patient_queue, new_patient);
}

void next_patient()
{
	char doctor_name[256];
	struct queue_node** patient_queue;

	printf("Enter doctor name\n");
	scanf("%s", doctor_name);

	patient_queue = get_patient_queue_of_doctor(doctor_name);

	struct patient* next_patient = (struct patient*) dequeue(patient_queue);
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
