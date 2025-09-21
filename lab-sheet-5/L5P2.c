#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next, *prev;
};

const char *memfail = "Failed to dynamically allocate memory!\n";

void create(struct Node **head, struct Node **tail, int *arr, int n) {
	if(n<1) return;
	int i;
	for(i = 0; i < n; i++) {
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		if(!newNode) {
			perror(memfail);
			return;
		}
		newNode->data = arr[i];
		newNode->prev = newNode->next = NULL;
		if(*head == NULL) {
			*head = *tail = newNode;
			continue;
		}
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
	}
}

void concat(struct Node **tail1, struct Node **head2) {
	(*tail1)->next = *head2;
	(*head2)->prev = *tail1;
}

void empty(struct Node **head) {
	while(*head) {
		struct Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void display(struct Node **head) {
	struct Node *temp = *head;
	for(;temp;temp=temp->next) {
		printf("<- | %p | %d | %p | -> ", (void*)temp->prev, temp->data, (void*)temp->next);
	}
	printf("\n");
}

void take_input(struct Node **head, struct Node **tail, char name) {
	int n, i;
	printf("Enter number of elements in list %c:\n", name);
	scanf("%d", &n);
	int *arr = (int*)malloc(n*sizeof(int));
	if(!arr) {
		perror(memfail);
		return;
	}
	printf("Enter array elements: ");
	for(i = 0; i < n; i++) scanf("%d", arr+i);
	create(head, tail, arr, n);
	free(arr);
}

int main() {
	struct Node *head1, *tail1, *head2, *tail2;
	head1 = tail1 = head2 = tail2 = NULL;
	take_input(&head1, &tail1, 'A');
	take_input(&head2, &tail2, 'B');
	concat(&tail1, &head2);
	printf("Elements in concatenated list:\n");
	display(&head1);
	empty(&head1);
	return 0;
}
