#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	void* data;
	struct node* next;
};

void push(struct node** stack, void* data)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	if (!*stack) {
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	*stack = new_node;
	return;
}

void* pop(struct node** stack)
{
	if(*stack == NULL) {
		printf("ERROR: Stack underflow\n");
		return NULL;
	}

	void* data = (*stack)->data;
	struct node* tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	return data;
}

int main()
{
	char input[256];
	int i = 0;

	struct node* stack = NULL;

	printf("Enter backets sequence\n");
	scanf("%s", input); //(())))

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			push(&stack, &input[i]);
		}
		else if (input[i] == ')') {
			pop(&stack);
		}
		else {
			printf("Illegal sequence\n");
			return;
		}
	}

	if (stack != NULL) {
		printf("Sequence is not balanced\n");
	}
	else {
		printf("Sequence is balanced\n");
	}

	return 0;

}
