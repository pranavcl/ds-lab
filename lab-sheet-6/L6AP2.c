#include<stdio.h>
#include<stdlib.h>

struct Node {
	float coeff, expo;
	struct Node *prev, *next;
} *head1, *tail1, *head2, *tail2, *head3, *tail3;

void init(struct Node **head, struct Node **tail) {
	*head = *tail = NULL;
}

void push(struct Node **head, struct Node **tail, float coeff, float expo) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(!newNode) {
		perror("Failed to dynamically allocate memory!\n");
		return;
	}
	newNode->coeff = coeff;
	newNode->expo = expo;
	newNode->prev = newNode->next = newNode;
	if(*head == NULL) {
		*head = *tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	newNode->prev = *tail;
	newNode->next = *head;
	*tail = newNode;
}

void create(struct Node **head, struct Node **tail, char name) {
	int i, n;
	float coeff, expo;
	printf("Enter number of terms in polynomial %c: ", name);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Coefficient (term %d): ", i+1);
		scanf("%f", &coeff);
		printf("Exponent (term %d): ", i+1);
		scanf("%f", &expo);
		push(head, tail, coeff, expo);
	}
}

void display(struct Node *head) {
	struct Node *temp = head;
	do {
		printf("%.1fx^%.1f", temp->coeff, temp->expo);
		if(temp->next != head) printf(" + ");

		temp=temp->next;
	} while(temp != head);
	printf("\n");
}

void product(struct Node **head3, struct Node **tail3, struct Node **head2, struct Node **tail2, struct Node **head1, struct Node **tail1) {
	struct Node *temp = *head1;

	do {
		struct Node *temp2 = *head2;
		do {
			push(head3, tail3, temp->coeff * temp2->coeff, temp->expo + temp2->expo);
			temp2 = temp2->next;
		} while(temp2 != *head2);
		temp = temp->next;
	} while(temp != *head1);

	temp = *head3;
	do {
		struct Node *temp2 = temp->next;
		while (temp2 != temp) {
			if (temp2->expo == temp->expo) {
            			temp->coeff += temp2->coeff;
            			struct Node *nextNode = temp2->next;

				temp2->prev->next = temp2->next;
				temp2->next->prev = temp2->prev;
				if (temp2 == *head3) *head3 = nextNode;

				free(temp2);
				temp2 = nextNode;
			} else {
			    temp2 = temp2->next;
			}
		}
		temp = temp->next;
	} while (temp->next != *head3);
}

int main() {
	init(&head1, &tail1);
	init(&head2, &tail2);
	init(&head3, &tail3);

	create(&head1, &tail1, 'A');
	create(&head2, &tail2, 'B');

	printf("Polynomial A: ");
	display(head1);

	printf("Polynomial B: ");
	display(head2);

	product(&head3, &tail3, &head2, &tail2, &head1, &tail1);

	printf("A * B: ");
	display(head3);

	return 0;
}
