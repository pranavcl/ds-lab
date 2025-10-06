#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next, *prev;
} *head1, *tail1, *head2, *tail2, *head3, *tail3;

void init(struct Node **head, struct Node **tail) {
	*head = NULL;
	*tail = NULL;
}

void push(struct Node **head, struct Node **tail, int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(!newNode) {
		perror("Failed to dynamically allocate memory!\n");
		return;
	}
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	if(*head == NULL) {
		*head = *tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	newNode->prev = *tail;
	*tail = newNode;
}

void create(struct Node **head, struct Node **tail, int *arr, int n) {
	if(n <= 0) return;
	int i;
	for(i = 0; i < n; i++) push(head, tail, arr[i]);
}

void display(struct Node **head) {
	for(; *head != NULL; *head = (*head)->next) {
		printf("%d -> ", (*head)->data);
	}
	printf("\n");
}

void concat(struct Node **head3, struct Node **tail3, struct Node **head1, struct Node **tail1, struct Node **head2, struct Node **tail2) {
	struct Node *temp1 = *head1, *temp2 = *head2;
	while(temp1 && temp2) {
		if(temp1->data < temp2->data) {
			push(head3, tail3, temp1->data);
			temp1 = temp1->next;
		} else {
			push(head3, tail3, temp2->data);
			temp2 = temp2->next;
		}
	}
	if(!temp1) temp1 = temp2;
	for(;temp1;temp1=temp1->next) push(head3, tail3, temp1->data);
}

int main() {
	int arr[] = {1, 2, 3, 4, 6};
	int arr1[] = {5, 7, 8, 9, 10};

	init(&head1, &tail1);
	init(&head2, &tail2);
	init(&head3, &tail3);

	create(&head1, &tail1, arr, sizeof(arr)/sizeof(int));
	create(&head2, &tail2, arr1, sizeof(arr1)/sizeof(int));

	concat(&head3, &tail3, &head1, &tail1, &head2, &tail2);

	printf("List 1: ");
	display(&head1);

	printf("List 2: ");
	display(&head2);

	printf("List 3 (concatenated): ");
	display(&head3);

	return 0;
}
